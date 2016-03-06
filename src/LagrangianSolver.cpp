#include "solver.hpp"

//Création d'un type Vecteur de Model :
typedef IloArray<IloModel> modelArray;
//Création d'un type Matrice de Model :
typedef IloArray<modelArray> modelMatrix;

//Création d'un type Vecteur de Model :
typedef IloArray<IloCplex> cplexArray;
//Création d'un type Matrice de Model :
typedef IloArray<cplexArray> cplexMatrix;

LagrangianSolver::LagrangianSolver() : Solver::Solver() {
    name = "LagrangianSolver";
    desc = "Résolution par méthode lagrangienne\n";
}

LagrangianSolver::~LagrangianSolver()  {
    // delete this->solution;
}



void
LagrangianSolver::setLagrangian (Data data, Solution* sol, IloModel model, BoolVarMatrix x, NumVarMatrix a, NumVarMatrix p, BoolVarTriMat d, IloNum lambda, IloRangeArray constraints) {
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
  IloExpr c1(env);
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      c1 = ( data.Hp[i][j] * data.Cp[i][j] - 1*data.Cp[i][j] ) * a[i][j] + ( data.Ha[i][j] * data.Ca[i][j] - 1*data.Ca[i][j] ) * p[i][j];
      obj += x[i][j] + lambda*c1 ;
    }
  }

  model.add(IloMaximize(env, obj));
  // -------------------------------------------------------------------
if (log3()) cout << "ok : objectif" << endl;


  // Contraintes : def avec les numero du compte rendu -----------------
  

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
bool LagrangianSolver::solve(Data data, Solution* sol) {
    if (log2()) {
        cout << "\n------ LagrangianSolver::solve START ------\n";
    }

    IloEnv env;
    try {

        // Set lambda
        IloNum lambda;
        lambda = 100;

        // Résolution

        //Algortithme de sur-gradient
        IloNum test=0;
        IloNum ecart=1;
        IloInt k=0;

        while (ecart>0.01 && k <100){
            
            sol->size = 0;

            // Creation Mdèle
            IloModel model(env);

            // Set variables
            BoolVarMatrix x(env);
            NumVarMatrix a(env);
            NumVarMatrix p(env);
            BoolVarTriMat d(env);
            IloRangeArray constraints(env);

            float rho;
            if (k==0)
            {
                rho=100.0;
            }
            else
            {
                rho=10.0/log((double)k+1);
            }

            // Set modèle
            setLagrangian(data, sol, model, x, a, p, d, lambda, constraints);

            // Résolution
            IloCplex cplex(model);
            cplex.solve();

            // Statut (optimalité ?) et valeur de l'objectif
            env.out() << "Solution status = " << cplex.getStatus() << endl;
            env.out() << "Solution value  = " << cplex.getObjValue() << endl;

            double cur_test(0);

            for (int i = 1; i <= data.m; i++)
            {
              for (int j = 1; j <= data.n; j++)
              {
                cur_test += ( data.Hp[i][j] * data.Cp[i][j] - 1*data.Cp[i][j] ) * cplex.getValue(a[i][j]) + ( data.Ha[i][j] * data.Ca[i][j] - 1*data.Ca[i][j] ) * cplex.getValue(p[i][j]);
              }
            }


            cout << "lambda = " << lambda << " et " << cur_test/sqrt(cur_test*cur_test) << endl;
            // Nouveau lambda
            lambda+=-rho*(cur_test/sqrt(cur_test*cur_test));
            if(lambda<0) {
                lambda=0;
            }
            cout << "lambda = " << lambda << endl;
            
            k=k+1;

            cout << "ecart = " << ecart << endl;
            ecart = sqrt((test-cur_test)*(test-cur_test));
            cout << "ecart = " << ecart << endl;

            cout << "test = " << test << endl;
            cout << "cur_test = " << cur_test << endl;

            test=cur_test;
            cout << "test = " << test << endl;

            cout << "k = " << k << endl;
            std::cout << "itération numéro : "<< k << std::endl;

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


    }
    catch (IloException& e) {
        cerr << "Concert exception caught: " << e << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught" << endl;
    }
    env.end();

    logn2("------ LagrangianSolver::solve: END ------\n");
    this->found = true;
    return found;
}



//./
