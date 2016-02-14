#include "solver.hpp"

FrontalSolver::FrontalSolver() : Solver::Solver() {
    name = "FrontalSolver";
    desc = "Résolution par PL avec cplex\n";
    //logn1(name + ": " + desc + " inst: " + inst->name);
    //this->solution = new Solution(inst);
    //logn1("Apres  CarloSolver::CarloSolver pour instance " + inst->name);
}
FrontalSolver::~FrontalSolver()  {
    // delete this->solution;
}












void
FrontalSolver::setFrontal (Data data, Solution* sol, IloModel model, BoolVarMatrix x, NumVarMatrix a, NumVarMatrix p, BoolVarTriMat d , IloRangeArray constraints) {
  IloEnv env = model.getEnv();

  // Recuperation des donnees ------------------------------------------
  int n = data.n; // pour éviter les data. dans les boucles
  int m = data.m;
  int h_max = n*m/2;
  // -------------------------------------------------------------------



  // Set des variables -------------------------------------------------
  for (int i = 0; i <= m+1; i++)
  {
    x.add(IloBoolVarArray(env));
    a.add(IloNumVarArray(env));
    p.add(IloNumVarArray(env));

    d.add(BoolVarMatrix(env));

    for (int j = 0; j <= n+1; j++)
    {
      x[i].add(IloBoolVar(env));
      a[i].add(IloNumVar(env));
      p[i].add(IloNumVar(env));

      d[i].add(IloBoolVarArray(env));

      for (int h = 0; h < h_max; h++)
      {
        d[i][j].add(IloBoolVar(env));
      }
    }
  }
  // -------------------------------------------------------------------



  // Objectif ----------------------------------------------------------
  IloExpr obj(env,0);
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      obj += x[i][j];
    }
  }

  model.add(IloMaximize(env, obj));
  // -------------------------------------------------------------------



  // Contraintes : def avec les numero du compte rendu -----------------
  IloExpr c1(env);
  IloExpr c10(env);


  // Meilleures bornes dont on dispose sur l'objectif
  constraints.add(obj <= sol->UpperBound);
  constraints.add(obj >= sol->LowerBound);



  // Calcul des sommes utiles : il doit y av oir une fct pour le faire direct, mais avec les IloTruc je sais pas laquelle c'est
  // sinon le mettre direct dans getData
  IloNum sum_Cp = 0;
  IloNum sum_Ca = 0;
  IloExpr sum_Cp_x(env);
  IloExpr sum_Ca_x(env);
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      sum_Cp += data.Cp[i][j];
      sum_Ca += data.Ca[i][j];
      sum_Cp_x += data.Cp[i][j] * x[i][j];
      sum_Ca_x += data.Ca[i][j] * x[i][j];
    }
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      IloExpr c2(env);
      IloExpr c3(env);
      IloExpr c4(env);
      IloExpr c5(env);
      IloExpr c6(env);
      IloExpr c7(env);
      IloExpr c8(env);
      IloExpr c9(env);
      IloExpr c11(env);
      IloExpr c12(env);


      // Contrainte sur Cp = 0 sortie du corrigé
      if (data.Cp[i][j] == 0.0)
      {
        constraints.add(x[i][j] == 0);
      }


      // Contrainte principale
      c1 += ( data.Hp[i][j] * data.Cp[i][j] - 1*data.Cp[i][j] ) * a[i][j] + ( data.Ha[i][j] * data.Ca[i][j] - 1*data.Ca[i][j] ) * p[i][j];

      // Contraintes sur p
      c2 = x[i][j] * sum_Cp - p[i][j];
      c3 = sum_Cp_x - p[i][j];
      c4 = sum_Cp_x + (x[i][j]-1) * sum_Cp - p[i][j];
      c5 = p[i][j];
      constraints.add(c2 >= 0); c2.end();
      constraints.add(c3 >= 0); c3.end();
      constraints.add(c4 <= 0); c4.end();
      constraints.add(c5 >= 0); c5.end();

      // Contraintes sur a
      c6 = x[i][j] * sum_Ca - a[i][j];
      c7 = sum_Ca_x - a[i][j];
      c8 = sum_Ca_x + (x[i][j]-1) * sum_Ca - a[i][j];
      c9 = a[i][j];
      constraints.add(c6 >= 0); c6.end();
      constraints.add(c7 >= 0); c7.end();
      constraints.add(c8 <= 0); c8.end();
      constraints.add(c9 >= 0); c9.end();

      // Contraintes de connexité
      c10 += d[i][j][0];

      IloExpr sum_d_h(env);
      for (int h = 0; h < h_max; h++)
      {
        sum_d_h += d[i][j][h];

        if (h+1 < h_max)
        {

          /*
          // sans le bord virtuel (il y a les 2 pour comparer la vitesse, et c'est sensiblement la même chose)
          if ((i > 1)&&(i < m)&&(j > 1)&&(j < n)) {   c12 = d[i+1][j][h] + d[i-1][j][h] + d[i][j+1][h] + d[i][j-1][h] - d[i][j][h+1]; }
          if ((i == 1)&&(j == 1)) {                   c12 = d[i+1][j][h] + d[i][j+1][h] - d[i][j][h+1]; }
          if ((i == 1)&&(j == n)) {                   c12 = d[i+1][j][h] + d[i][j-1][h] - d[i][j][h+1]; }
          if ((i == 1)&&(j > 1)&&(j < n)) {           c12 = d[i+1][j][h] + d[i][j+1][h] + d[i][j-1][h] - d[i][j][h+1]; }
          if ((j == 1)&&(i > 1)&&(i < m)) {           c12 = d[i+1][j][h] + d[i-1][j][h] + d[i][j+1][h] - d[i][j][h+1]; }
          if ((j == n)&&(i > 1)&&(i < m)) {           c12 = d[i+1][j][h] + d[i-1][j][h] + d[i][j-1][h] - d[i][j][h+1]; }
          if ((i == m)&&(j == 1)) {                   c12 = d[i-1][j][h] + d[i][j+1][h] - d[i][j][h+1]; }
          if ((i == m)&&(j == n)) {                   c12 = d[i-1][j][h] + d[i][j-1][h] - d[i][j][h+1]; }
          if ((i == m)&&(j > 1)&&(j < n)) {           c12 = d[i-1][j][h] + d[i][j+1][h] + d[i][j-1][h] - d[i][j][h+1]; }
          */
    
          c12 = d[i+1][j][h] + d[i-1][j][h] + d[i][j+1][h] + d[i][j-1][h] - d[i][j][h+1];
          constraints.add(c12 >= 0); c12.end();
        }
      }
      c11 = sum_d_h - x[i][j];
      constraints.add(c11 == 0); c11.end();
      sum_d_h.end();


    } // \for j
  } // \for i

  constraints.add(c1 >= 0); c1.end();

  constraints.add(c10 == 1); c10.end();


  // Contraintes sur le bord virtuel
  
  for (int i = 0; i <= m+1; i++)
  {
    constraints.add(x[i][0] == 0);
    constraints.add(x[i][n+1] == 0);
    constraints.add(p[i][0] == 0);
    constraints.add(p[i][n+1] == 0);
    constraints.add(a[i][0] == 0);
    constraints.add(a[i][n+1] == 0);
    for (int h = 0; h < h_max; h++)
    {
      constraints.add(d[i][0][h] == 0);
      constraints.add(d[i][n+1][h] == 0);
    }
  }
  for (int j = 0; j <= n+1; j++)
  {
    constraints.add(x[0][j] == 0);
    constraints.add(x[m+1][j] == 0);
    constraints.add(p[0][j] == 0);
    constraints.add(p[m+1][j] == 0);
    constraints.add(a[0][j] == 0);
    constraints.add(a[m+1][j] == 0);
    for (int h = 0; h < h_max; h++)
    {
      constraints.add(d[0][j][h] == 0);
      constraints.add(d[m+1][j][h] == 0);
    }
  }
  
  model.add(constraints);

  // -------------------------------------------------------------------
}















// Méthode principale de ce solver, principe :
//
bool FrontalSolver::solve(Data data, Solution* sol) {
    if (log2()) {
        cout << "\n------ FrontalSolver::solve START ------\n";
    }
    
    

    IloEnv env;
    try {
        // Création modèle
        IloModel model(env);

        // Set Variables
        BoolVarMatrix x(env);
        NumVarMatrix a(env);
        NumVarMatrix p(env);
        BoolVarTriMat d(env);
        IloRangeArray constraints(env);

        // Set modèle
        setFrontal(data, sol, model, x, a, p, d, constraints);

        // Résolution
        IloCplex cplex(model);
        cplex.solve();

        // Statut (optimalité ?) et valeur de l'objectif
        env.out() << "Solution status = " << cplex.getStatus() << endl;
        env.out() << "Solution value  = " << cplex.getObjValue() << endl;

        


        // Save de la selection dans la sol
        for (int i = 1; i <= data.m; i++)
        {
            for (int j = 1; j <= data.n; j++)
            {
                sol->x[i][j] = IloRound(cplex.getValue(x[i][j]));
                sol->size = sol->size + sol->x[i][j];
            }
        }



    }
    catch (IloException& e) {
        cerr << "Concert exception caught: " << e << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught" << endl;
    }
    env.end();


    logn2("------ FrontalSolver::solve: END ------\n");
    this->found = true;
    return found;
}























//./
