#include "solver.hpp"

GloutonSolver::GloutonSolver() : Solver::Solver() {
    name = "GloutonSolver";
    desc = "Résolution par méthode gloutonne\n";
    //logn1(name + ": " + desc + " inst: " + inst->name);
    //this->solution = new Solution(inst);
    //logn1("Apres  CarloSolver::CarloSolver pour instance " + inst->name);
}
GloutonSolver::~GloutonSolver()  {
    // delete this->solution;
}











/*
void
GloutonSolver::setGlouton (Data data, Solution* sol) {

}
*/














// Méthode principale de ce solver, principe :
//
bool GloutonSolver::solve(Data data, Solution* sol) {
    if (log2()) {
        cout << "\n------ FrontalSolver::solve START ------\n";
    }
    

    // Calcul des coûts initiaux qui vont servir à choisir quelle maille ajouter ----------------------------------------
    vector<vector<double>> coeffs;
    // pour que l'appel se fasse pour 1<=i<=m et 1<=j<=n plutot qu'à partir de 0
    vector<double> row_Zero;
    row_Zero.push_back(0);
    coeffs.push_back(row_Zero);

    double coef;
    double max_coef = -100000;
    vector<Maille> startingPoints;
    int nbr_start_P=0;
    for (int i = 1; i <= data.m; i++)
    {
        vector<double> row;
        row.push_back(0);
        for (int j = 1; j <= data.n; j++)
        {
            coef = (data.Hp[i][j]-1)*data.Cp[i][j] + (data.Ha[i][j]-1)*data.Ca[i][j]; // à changer, jouer avec pour trouver truc efficace
            row.push_back(coef);


            if (coef >= max_coef && data.Cp[i][j]>=0.01)
            {
                max_coef = coef;
                Maille new_maille;
                startingPoints.push_back(new_maille);
                startingPoints[nbr_start_P].i = i;
                startingPoints[nbr_start_P].j = j;
                nbr_start_P++;
            }

        }
        coeffs.push_back(row);
    }

    // -------------------------------------------------------------------------------------------------------------------



    // Set des objets pour le calcul -------------------------------------------------------------------------------------
    vector<vector<int>> Select; // 0: pas sélec, 1: sélec dans la sol, 2: dans les voisins, 3: non ajoutable;
    vector<int> row_Zero_int;
    row_Zero_int.push_back(0);
    Select.push_back(row_Zero_int);
    for (int i = 1; i <= data.m; i++)
    {
        vector<int> row;
        row.push_back(0);
        for (int j = 1; j <= data.n; j++)
        {
            row.push_back(0);
        }
        Select.push_back(row);
    }

    vector<double> coeffs_voisins;
    // -------------------------------------------------------------------------------------------------------------------

int best_size(0);
Maille best_maille;

auto it2 = startingPoints.begin();
while ( it2 != startingPoints.end() )
    {
        cout << " i = " << it2->i << " j = " << it2->j << endl;
        // Tirage de la maille de départ autour de laquelle on va agréger les autres -----------------------------------------
        // et récup de ses voisins
        int i0, j0;
        i0 = it2->i;
        j0 = it2->j;
        Select[i0][j0] = 1;
        sol->NumP = sol->NumP + data.Hp[i0][j0]*data.Cp[i0][j0];
        sol->DenumP = sol->DenumP + data.Cp[i0][j0];
        sol->NumA = sol->NumA + data.Ha[i0][j0]*data.Ca[i0][j0];
        sol->DenumA = sol->DenumA + data.Ca[i0][j0];

        // cout << "sol->NumP = " << sol->NumP << " sol->DenumP = " << sol->DenumP << endl;
        // cout << "sol->NumA = " << sol->NumA << " sol->DenumA = " << sol->DenumA << endl;

        Maille voisin;
        if ((i0-1 != 0)&&(Select[i0-1][j0] == 0)) {
            Select[i0-1][j0] = 2;
            voisin.i = i0-1;
            voisin.j = j0;
            sol->voisins.push_back(voisin);
            coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
            // cout << "Ajout de voisin 1" << endl;
        }
        if ((i0+1 != data.m+1)&&(Select[i0+1][j0] == 0) ){
            Select[i0+1][j0] = 2;
            voisin.i = i0+1;
            voisin.j = j0;
            sol->voisins.push_back(voisin);
            coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
            // cout << "Ajout de voisin 2" << endl;
        }
        if ((j0-1 != 0)&&(Select[i0][j0-1] == 0)) {
            Select[i0][j0-1] = 2;
            voisin.i = i0;
            voisin.j = j0-1;
            sol->voisins.push_back(voisin);
            coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
            // cout << "Ajout de voisin 3" << endl;
        }
        if ((j0+1 != data.n+1)&&(Select[i0][j0+1] == 0)) {
            Select[i0][j0+1] = 2;
            voisin.i = i0;
            voisin.j = j0+1;
            sol->voisins.push_back(voisin);
            coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
            // cout << "Ajout de voisin 4" << endl;
        }
        sol->size++;
        // -------------------------------------------------------------------------------------------------------------------




     
        // Sélection d'un voisin à ajouter (si c'est possible) ---------------------------------------------------------------
        int i,j;
        int pos_max;
        double updated_cost;
        auto it = sol->voisins.begin();
        while( it != sol->voisins.end() )
        {
            pos_max = distance(coeffs_voisins.begin(),max_element(coeffs_voisins.begin(), coeffs_voisins.end()));
            i = sol->voisins[pos_max].i;
            j = sol->voisins[pos_max].j;

            updated_cost = (sol->NumP + data.Hp[i][j]*data.Cp[i][j])/(sol->DenumP + data.Cp[i][j]) + (sol->NumA + data.Ha[i][j]*data.Ca[i][j])/(sol->DenumA + data.Ca[i][j]);

            // cout << "updated_cost = " << updated_cost << endl;

            if ((updated_cost >= 2)&&(data.Cp[i][j] != 0))
            {
                // On l'ajoute
                // cout << "Ajout" << endl;
                Select[i][j] = 1;
                // Maj des parts du coût
                sol->NumP = sol->NumP + data.Hp[i][j]*data.Cp[i][j];
                sol->DenumP = sol->DenumP + data.Cp[i][j];
                sol->NumA = sol->NumA + data.Ha[i][j]*data.Ca[i][j];
                sol->DenumA = sol->DenumA + data.Ca[i][j];
                // Ajout des voisins à la liste
                if ((i-1 != 0)&&(Select[i-1][j] == 0)) {
                    Select[i-1][j] = 2;
                    voisin.i = i-1;
                    voisin.j = j;
                    sol->voisins.push_back(voisin);
                    coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
                }
                if ((i+1 != data.m+1)&&(Select[i+1][j] == 0) ){
                    Select[i+1][j] = 2;
                    voisin.i = i+1;
                    voisin.j = j;
                    sol->voisins.push_back(voisin);
                    coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
                }
                if ((j-1 != 0)&&(Select[i][j-1] == 0)) {
                    Select[i][j-1] = 2;
                    voisin.i = i;
                    voisin.j = j-1;
                    sol->voisins.push_back(voisin);
                    coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
                }
                if ((j+1 != data.n+1)&&(Select[i][j+1] == 0)) {
                    Select[i][j+1] = 2;
                    voisin.i = i;
                    voisin.j = j+1;
                    sol->voisins.push_back(voisin);
                    coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
                }
                // On supprime la maille sélectionnée de la liste des voisins
                sol->voisins.erase(sol->voisins.begin()+pos_max);
                coeffs_voisins.erase(coeffs_voisins.begin()+pos_max);
                // ? recalcule des couts privés ? selon formalisme

                // Maj de la taille de la sol
                sol->size++;
            } else
            {
                // On indique qu'on peut pas le sélectionner
                Select[i][j] = 3;
                // on le supprime de la liste
                sol->voisins.erase(sol->voisins.begin()+pos_max);
                coeffs_voisins.erase(coeffs_voisins.begin()+pos_max);
            }


            it = sol->voisins.begin();
        }

        cout << "solution size = " << sol->size << endl;

        if (sol->size >= best_size)
        {
            best_size=sol->size;
            best_maille = *it2;
            // cout << "changement de meilleure maille" << endl;
        }
        sol->size = 0;

        it2++;

    for (int i = 1; i <= data.m; i++)
    {
        for (int j = 1; j <= data.n; j++)
        {
            Select[i][j]=0;
        }
    }
    sol->voisins.clear();
    sol->NumP = 0;
    sol->DenumP = 0;
    sol->NumA = 0;
    sol->DenumA = 0;

    }
    // -------------------------------------------------------------------------------------------------------------------




// Tirage de la maille de départ autour de laquelle on va agréger les autres -----------------------------------------
    // et récup de ses voisins
    int i0, j0;
    i0 = best_maille.i;
    j0 = best_maille.j;

    cout << " i0 = " << best_maille.i << " j0 = " << best_maille.j << endl;

    Select[i0][j0] = 1;
    sol->NumP = sol->NumP + data.Hp[i0][j0]*data.Cp[i0][j0];
    sol->DenumP = sol->DenumP + data.Cp[i0][j0];
    sol->NumA = sol->NumA + data.Ha[i0][j0]*data.Ca[i0][j0];
    sol->DenumA = sol->DenumA + data.Ca[i0][j0];

    // cout << "sol->NumP = " << sol->NumP << " sol->DenumP = " << sol->DenumP << endl;
    // cout << "sol->NumA = " << sol->NumA << " sol->DenumA = " << sol->DenumA << endl;

    Maille voisin;
    if ((i0-1 != 0)&&(Select[i0-1][j0] == 0)) {
        Select[i0-1][j0] = 2;
        voisin.i = i0-1;
        voisin.j = j0;
        sol->voisins.push_back(voisin);
        coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
    }
    if ((i0+1 != data.m+1)&&(Select[i0+1][j0] == 0) ){
        Select[i0+1][j0] = 2;
        voisin.i = i0+1;
        voisin.j = j0;
        sol->voisins.push_back(voisin);
        coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
    }
    if ((j0-1 != 0)&&(Select[i0][j0-1] == 0)) {
        Select[i0][j0-1] = 2;
        voisin.i = i0;
        voisin.j = j0-1;
        sol->voisins.push_back(voisin);
        coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
    }
    if ((j0+1 != data.n+1)&&(Select[i0][j0+1] == 0)) {
        Select[i0][j0+1] = 2;
        voisin.i = i0;
        voisin.j = j0+1;
        sol->voisins.push_back(voisin);
        coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
    }
    sol->size++;
    // -------------------------------------------------------------------------------------------------------------------




 
    // Sélection d'un voisin à ajouter (si c'est possible) ---------------------------------------------------------------
    int i,j;
    int pos_max;
    double updated_cost;
    auto it = sol->voisins.begin();
    while( it != sol->voisins.end() )
    {
        pos_max = distance(coeffs_voisins.begin(),max_element(coeffs_voisins.begin(), coeffs_voisins.end()));
        i = sol->voisins[pos_max].i;
        j = sol->voisins[pos_max].j;

        updated_cost = (sol->NumP + data.Hp[i][j]*data.Cp[i][j])/(sol->DenumP + data.Cp[i][j]) + (sol->NumA + data.Ha[i][j]*data.Ca[i][j])/(sol->DenumA + data.Ca[i][j]);

        // cout << "updated_cost = " << updated_cost << endl;

        if ((updated_cost >= 2)&&(data.Cp[i][j] != 0))
        {
            // On l'ajoute
            Select[i][j] = 1;
            // Maj des parts du coût
            sol->NumP = sol->NumP + data.Hp[i][j]*data.Cp[i][j];
            sol->DenumP = sol->DenumP + data.Cp[i][j];
            sol->NumA = sol->NumA + data.Ha[i][j]*data.Ca[i][j];
            sol->DenumA = sol->DenumA + data.Ca[i][j];
            // Ajout des voisins à la liste
            if ((i-1 != 0)&&(Select[i-1][j] == 0)) {
                Select[i-1][j] = 2;
                voisin.i = i-1;
                voisin.j = j;
                sol->voisins.push_back(voisin);
                coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
            }
            if ((i+1 != data.m+1)&&(Select[i+1][j] == 0) ){
                Select[i+1][j] = 2;
                voisin.i = i+1;
                voisin.j = j;
                sol->voisins.push_back(voisin);
                coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
            }
            if ((j-1 != 0)&&(Select[i][j-1] == 0)) {
                Select[i][j-1] = 2;
                voisin.i = i;
                voisin.j = j-1;
                sol->voisins.push_back(voisin);
                coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
            }
            if ((j+1 != data.n+1)&&(Select[i][j+1] == 0)) {
                Select[i][j+1] = 2;
                voisin.i = i;
                voisin.j = j+1;
                sol->voisins.push_back(voisin);
                coeffs_voisins.push_back(coeffs[voisin.i][voisin.j]);
            }
            // On supprime la maille sélectionnée de la liste des voisins
            sol->voisins.erase(sol->voisins.begin()+pos_max);
            coeffs_voisins.erase(coeffs_voisins.begin()+pos_max);
            // ? recalcule des couts privés ? selon formalisme

            // Maj de la taille de la sol
            sol->size++;
        } else
        {
            // On indique qu'on peut pas le sélectionner
            Select[i][j] = 3;
            // on le supprime de la liste
            sol->voisins.erase(sol->voisins.begin()+pos_max);
            coeffs_voisins.erase(coeffs_voisins.begin()+pos_max);
        }


        it = sol->voisins.begin();
    }

    cout << "sol->size" << sol->size << endl;

    // Save de la selection dans la sol ----------------------------------------------------------------------------------
    for (int i = 1; i <= data.m; i++)
    {
        for (int j = 1; j <= data.n; j++)
        {
            sol->x[i][j] = Select[i][j];
        }
    }
    // -------------------------------------------------------------------------------------------------------------------




    sol->LowerBound = sol->size;

    logn2("------ GloutonSolver::solve: END ------\n");
    this->found = true;
    return found;
}























//./
