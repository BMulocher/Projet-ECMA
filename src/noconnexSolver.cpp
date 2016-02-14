#include "solver.hpp"

NoConnexSolver::NoConnexSolver() : Solver::Solver() {
    name = "NoConnexSolver";
    desc = "Résolution par PL avec cplex, sans les contraintes de conexité\n";
    //logn1(name + ": " + desc + " inst: " + inst->name);
    //this->solution = new Solution(inst);
    //logn1("Apres  CarloSolver::CarloSolver pour instance " + inst->name);
}
NoConnexSolver::~NoConnexSolver()  {
    // delete this->solution;
}









void
NoConnexSolver::setNoConnex (Data data, Solution* sol, IloModel model, BoolVarMatrix x, NumVarMatrix a, NumVarMatrix p, BoolVarTriMat d , IloRangeArray constraints) {
  IloEnv env = model.getEnv();

  // Recuperation des donnees ------------------------------------------
  int n = data.n; // pour éviter les data. dans les boucles
  int m = data.m;
  // -------------------------------------------------------------------
if (log3()) cout << "ok : getData" << endl;



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
    }
  }
  // -------------------------------------------------------------------
if (log3()) cout << "ok : set variables" << endl;


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
if (log3()) cout << "ok : objectif" << endl;


  // Contraintes : def avec les numero du compte rendu -----------------
  IloExpr c1(env);

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


    } // \for j
  } // \for i

  constraints.add(c1 >= 0); c1.end();

 

  model.add(constraints);

  // -------------------------------------------------------------------
if (log3()) cout << "ok : constraintes" << endl;

}












// Méthode principale de ce solver, principe :
//
bool NoConnexSolver::solve(Data data, Solution* sol) {
    if (log2()) {
        cout << "\n------ NoConnexSolver::solve START ------\n";
    }
    
    // Récupération du fichier data dans la ligne d'arguments
    //Options* args = Options::args;
    //string data_file = args->filename;


    IloEnv env;
    try {
        // Creation Mdèle
        IloModel model(env);

        // Set variables
        BoolVarMatrix x(env);
        NumVarMatrix a(env);
        NumVarMatrix p(env);
        BoolVarTriMat d(env);
        IloRangeArray constraints(env);

        // Set modèle
        setNoConnex(data, sol, model, x, a, p, d, constraints);

        // Résolution
        IloCplex cplex(model);
        cplex.solve();

        // Statut (optimalité ?) et valeur de l'objectif
        env.out() << "Solution status = " << cplex.getStatus() << endl;
        env.out() << "Solution value  = " << cplex.getObjValue() << endl;

        // Maj de la borne sup
        sol->UpperBound = IloRound(cplex.getObjValue());

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


    logn2("------ NoConnexSolver::solve: END ------\n");
    this->found = true;
    return found;
}

//./
