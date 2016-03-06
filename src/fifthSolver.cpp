#include "solver.hpp"

FifthSolver::FifthSolver() : Solver::Solver() {
    name = "5Solver";
    desc = "Résolution par méthode ...\n";
    //logn1(name + ": " + desc + " inst: " + inst->name);
    //this->solution = new Solution(inst);
    //logn1("Apres  CarloSolver::CarloSolver pour instance " + inst->name);
}
FifthSolver::~FifthSolver()  {
    // delete this->solution;
}











/*
void
FifthSolver::setFifth (Data data, Solution* sol) {

}
*/














// Méthode principale de ce solver, principe :
//
bool FifthSolver::solve(Data data, Solution* sol) {
    if (log2()) {
        cout << "\n------ FifthSolver::solve START ------\n";
    }

    int i = 0;
    int j = 0;


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




    // Récup des trucs utiles
    double value = 0;
    int maille = 0;
    pair<double,int> paire;
    vector<pair<double,int>> tosort;
    vector<pair<double,int>> negativ;
    for (int i = 1; i <= data.m; i++)
    {
        for (int j = 1; j <= data.n; j++)
        {
            value = (data.Hp[i][j]-1)*data.Cp[i][j] + (data.Ha[i][j]-1)*data.Ca[i][j];
            if (data.Cp[i][j] == 0)
            {
                value = -1000000;
            }
            maille = data.n*(i-1) + (j-1);
            paire = pair<double,int>(value,maille);
            tosort.push_back(paire);
            cout << value << endl;
            if (value < 0)
            {
                negativ.push_back(paire);
            }
        }
    }
    sort(tosort.begin(), tosort.end());





    double Vp = 0;
    double Va = 0;
    double P = 0;
    double A = 0;

    auto it = tosort.end()-1;
    while (it != tosort.begin())
    {
        i = floor(double(it->second)/double(data.n))+1;
        j = it->second - (i-1)*data.n + 1;
        cout << it->first << " : " << i << ", " << j << endl;
        if (it->first >= 0)
        {
            Vp = Vp + (data.Hp[i][j]-1)*data.Cp[i][j];
            Va = Va + (data.Ha[i][j]-1)*data.Ca[i][j];
            P = P + data.Cp[i][j];
            A = A + data.Ca[i][j];
            Select[i][j] = 1;
            sol->size++;
            it --;
        } else {
            it = tosort.begin();
        }
    }



    

    bool add = true;
    i = 0;
    j = 0;
    auto kt = negativ.end()-1;
    while ((add == true)&&(kt != negativ.begin()))
    {
        for (auto jt = negativ.begin(); jt != negativ.end(); jt++)
        {
            i = floor(double(jt->second)/double(data.n))+1;
            j = jt->second - (i-1)*data.n + 1;
            jt->first = Vp*(A+data.Ca[i][j]) + Va*(P+data.Cp[i][j]) + (data.Hp[i][j]-1)*data.Cp[i][j]*(A + data.Ca[i][j]) + (data.Ha[i][j]-1)*data.Ca[i][j]*(P + data.Cp[i][j]);
        }
        sort(negativ.begin(), negativ.end());
        kt = negativ.end()-1;
        i = floor(double(kt->second)/double(data.n))+1;
        j = kt->second - (i-1)*data.n + 1;


        if (kt->first >= 0)
        {
            if (data.Cp[i][j] != 0) 
            {
                Vp = Vp + (data.Hp[i][j]-1)*data.Cp[i][j];
                Va = Va + (data.Ha[i][j]-1)*data.Ca[i][j];
                P = P + data.Cp[i][j];
                A = A + data.Ca[i][j];
                Select[i][j] = 1;
                sol->size++;
            }
            negativ.erase(kt);
        } else
        {
            add = false;
        }
    }







    // Save de la selection dans la sol ----------------------------------------------------------------------------------
    for (int i = 1; i <= data.m; i++)
    {
        for (int j = 1; j <= data.n; j++)
        {
            sol->NumP = sol->NumP + data.Hp[i][j]*data.Cp[i][j]*Select[i][j];
            sol->DenumP = sol->DenumP + data.Cp[i][j]*Select[i][j];
            sol->NumA = sol->NumA + data.Ha[i][j]*data.Ca[i][j]*Select[i][j];
            sol->DenumA = sol->DenumA + data.Ca[i][j]*Select[i][j];
            sol->x[i][j] = Select[i][j];
        }
    }
    // -------------------------------------------------------------------------------------------------------------------




    sol->LowerBound = sol->size;

    logn2("------ FifthSolver::solve: END ------\n");
    this->found = true;
    return found;
}























//./
