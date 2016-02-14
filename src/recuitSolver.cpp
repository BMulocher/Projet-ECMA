#include "solver.hpp"
#include "voisinage.hpp"

RecuitSolver::RecuitSolver() : Solver::Solver() {
    name = "RecuitSolver";
    desc = "Résolution par recuit simulé\n";
    //logn1(name + ": " + desc + " inst: " + inst->name);
    //this->solution = new Solution(inst);
    //logn1("Apres  CarloSolver::CarloSolver pour instance " + inst->name);
}
RecuitSolver::~RecuitSolver()  {
    // delete this->solution;
}











/*
void
RecuitSolver::setRecuit (Data data, Solution* sol) {

}
*/














// Méthode principale de ce solver, principe :
//
bool RecuitSolver::solve(Data data, Solution* sol) {
    if (log2()) {
        cout << "\n------ RecuitSolver::solve START ------\n";
    }
    


    // Parametres du(des) recuit(s) -------------------------------------------------------------------------------------
    Options* args = Options::args;
    int itermax = args->itermax;
    double T; // température initiale
    double TAU_MIN = 0.0000001;
    // ------------------------------------------------------------------------------------------------------------------





/*
    // Calcul des coûts initiaux qui vont servir à choisir quelle maille ajouter ----------------------------------------
    vector<vector<double>> coeffs;
    // pour que l'appel se fasse pour 1<=i<=m et 1<=j<=n plutot qu'à partir de 0
    vector<double> row_Zero;
    row_Zero.push_back(0);
    coeffs.push_back(row_Zero);

    double coef;
    double max_coef = 0;
    Maille startingPoint;
    for (int i = 1; i <= data.m; i++)
    {
        vector<double> row;
        row.push_back(0);
        for (int j = 1; j <= data.n; j++)
        {
            coef = data.Hp[i][j]*data.Cp[i][j]/data.Cp[i][j] + data.Ha[i][j]*data.Ca[i][j]/data.Ca[i][j]; // à changer, joeur avec pour trouver truc efficace
            row.push_back(coef);

            if (coef >= max_coef)
            {
                max_coef = coef;
                startingPoint.i = i;
                startingPoint.j = j;
            }

        }
        coeffs.push_back(row);
    }
    // -------------------------------------------------------------------------------------------------------------------
*/



    // Tirage random d'une maille de départ ------------------------------------------------------------------------------
    Maille startingPoint;
    int sti = 0;
    int stj = 0;
    double coef = 0;
    bool start = false;
    while (!start)
    {
        sti = rand() % data.m + 1;
        stj = rand() % data.n + 1;
        coef = data.Hp[sti][stj]*data.Cp[sti][stj]/data.Cp[sti][stj] + data.Ha[sti][stj]*data.Ca[sti][stj]/data.Ca[sti][stj];
        if (coef >= 2)
        {
            start = true;
            startingPoint.i = sti;
            startingPoint.j = stj;
        }
    }
    // -------------------------------------------------------------------------------------------------------------------




    // Tirage de la maille de départ autour de laquelle on va agréger les autres -----------------------------------------
    // et récup de ses voisins
    int i0, j0;
    i0 = startingPoint.i;
    j0 = startingPoint.j;
    sol->x[i0][j0] = 1;
    sol->NumP = sol->NumP + data.Hp[i0][j0]*data.Cp[i0][j0];
    sol->DenumP = sol->DenumP + data.Cp[i0][j0];
    sol->NumA = sol->NumA + data.Ha[i0][j0]*data.Ca[i0][j0];
    sol->DenumA = sol->DenumA + data.Ca[i0][j0];
    sol->size++;
    Maille voisin;
    if ((i0-1 != 0)&&(sol->x[i0-1][j0] == 0)) {
        sol->x[i0-1][j0] = 2;
        voisin.i = i0-1;
        voisin.j = j0;
        sol->voisins.push_back(voisin);
    }
    if ((i0+1 != data.m+1)&&(sol->x[i0+1][j0] == 0) ){
        sol->x[i0+1][j0] = 2;
        voisin.i = i0+1;
        voisin.j = j0;
        sol->voisins.push_back(voisin);
    }
    if ((j0-1 != 0)&&(sol->x[i0][j0-1] == 0)) {
        sol->x[i0][j0-1] = 2;
        voisin.i = i0;
        voisin.j = j0-1;
        sol->voisins.push_back(voisin);
    }
    if ((j0+1 != data.n+1)&&(sol->x[i0][j0+1] == 0)) {
        sol->x[i0][j0+1] = 2;
        voisin.i = i0;
        voisin.j = j0+1;
        sol->voisins.push_back(voisin);
    }
    // -------------------------------------------------------------------------------------------------------------------




 
    // Recuit ------------------------------------------------------------------------------------------------------------
    //T = 5*sol->size;
    T = 5*data.m*data.n;
    sol = this->recuit(data, sol, T, 0.99, 50, 50*itermax, TAU_MIN);
    // -------------------------------------------------------------------------------------------------------------------

cout << sol->check_connexity() << endl;



/*
    // Save de la selection dans la sol ----------------------------------------------------------------------------------
    for (int i = 1; i <= data.m; i++)
    {
        for (int j = 1; j <= data.n; j++)
        {
            sol->x[i][j] = Select[i][j];
        }
    }
    sol->LowerBound = sol->size;
    // -------------------------------------------------------------------------------------------------------------------
*/

    logn2("\n------ RecuitSolver::solve: END ------\n");
    this->found = true;
    return found;
}







Solution* RecuitSolver::recuit(Data data, Solution* solution, double T0, double prog_geo_T, int max_prop, int itermax, double TAU_MIN) {

    // recup et init des param ************************************************************
    Solution* current = new Solution(solution);
    Solution* neighbor = new Solution(current); // solution voisine de la sol courante du recuit
    double T = T0; // température initiale
    double tau = 1.0; // taux d'acceptation, sert pour le critère de convergence
    double p = 1.0; // init de la proba de garder une sol moins bonne
    double proba;
    int iter = 0; // pour compter le nb de tours
    // ************************************************************************************



    // début de la boucle ****************************************************************
    if (log2()) {
        cout << "\n" << iter << ": " << solution->size;
    }

    int count_proposition = 0;
    int count_accepted_proposition = 0;
    while ( (tau>TAU_MIN)&&(iter<itermax) ) {
      
        cout << "." << flush;

        count_proposition = 0;
        count_accepted_proposition = 0;

        for (int i=0; i < max_prop; ++i) {
        
            // tirage d'une solution voisine
            neighbor = select_voisin(data, current, neighbor, iter);
            if ((iter % 10 == 0)&&(iter != 0))
            {
                i = max_prop;
            }

            // vérification de la connexité ?
            bool is_valid = true;
                // todo

            if (is_valid) { 
                // voisin valide
                count_proposition++;

                if ( neighbor->size > current->size ) {
                    // voisin meilleur que la solution actuelle :
                    current->copy(neighbor);
                    count_accepted_proposition++;

                    if ( current->size > solution->size ) {
                        // voisin meilleur que la meilleure solution
                        solution->copy(neighbor);
                        if (log2()) {
                            cout << "\n" << iter << ": " << solution->size;
                        }
                    }
                
                } else {
                    // voisin pas meilleur, testons si oui ou non on le garde
                    p = (double) exp(-static_cast<double>( neighbor->size - current->size )/T );
                    proba = ((double) rand() / (RAND_MAX));

                    if (proba < p) {
                        // voisin accepté
                        current->copy(neighbor);
                        count_accepted_proposition++;
                    } else {
                        // voisin rejeté
                    }
                
                }
            } else {
                // voisin invalide
            } // \if voisin valide

        } // \for sur les propositions

        iter++;

        // mise à jour taux d'acceptation
        tau = (double) count_accepted_proposition/count_proposition;

        // mise à jour de la température. La coder dans une fonction à part ?
        T = prog_geo_T*T;

    } // \while
    

    // evitons les fuites memoire
    //delete neighbor;
    //delete current;
    //***************************************************************************************

    return solution;
}















//./
