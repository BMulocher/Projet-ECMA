#include "solution.hpp"




////////////////////////////////////////////////////////////////////////////
//
//      Constructeurs
//
////////////////////////////////////////////////////////////////////////////

Solution::Solution() {
    this->size = 0;
    this->m = 0;
    this->n = 0;
    this->NumP = 0;
    this->DenumP = 0;
    this->NumA = 0;
    this->DenumA = 0;
    this->UpperBound = 99999999;
    this->LowerBound = 0;
}


Solution::Solution(Data data) {
    this->data = &data;
    this->size = 0;
    this->m = data.m;
    this->n = data.n;
    this->NumP = 0;
    this->DenumP = 0;
    this->NumA = 0;
    this->DenumA = 0;
    this->UpperBound = 99999999;
    this->LowerBound = 0;

    vector<double> row_Zero;
    row_Zero.push_back(0);
    this->x.push_back(row_Zero);
    for (int i = 1; i <= data.m; i++)
    {
        vector<double> row;
        row.push_back(0);
        for (int j = 1; j <= data.n; j++)
        {
            row.push_back(0);
        }
        this->x.push_back(row);
    }
}


Solution::Solution(const Solution* sol)  {
    this->data = sol->data;
    this->size = sol->size;
    this->m = sol->m;
    this->n = sol->n;
    this->NumP = sol->NumP;
    this->DenumP = sol->DenumP;
    this->NumA = sol->NumA;
    this->DenumA = sol->DenumA;
    this->UpperBound = sol->UpperBound;
    this->LowerBound = sol->LowerBound;

    vector<double> row_Zero;
    row_Zero.push_back(0);
    this->x.push_back(row_Zero);
    for (int i = 1; i <= sol->m; i++)
    {
        vector<double> row;
        row.push_back(0);
        for (int j = 1; j <= sol->n; j++)
        {
            row.push_back(sol->x[i][j]);
        }
        this->x.push_back(row);
    }

    auto it = sol->voisins.begin();
    while( it != sol->voisins.end() ) 
    {
        this->voisins.push_back(*it);
        it++;
    }
}


void Solution::copy(Solution* sol) {
    this->data = sol->data;
    this->size = sol->size;
    this->NumP = sol->NumP;
    this->DenumP = sol->DenumP;
    this->NumA = sol->NumA;
    this->DenumA = sol->DenumA;
    this->UpperBound = sol->UpperBound;
    this->LowerBound = sol->LowerBound;

    if ((this->m != sol->m)||(this->n != sol->n))
    {
        cerr << "Erreur copy solution : size does not match" << endl;
    } else {
        for (int i = 1; i <= sol->m; i++)
        {
            for (int j = 1; j <= sol->n; j++)
            {
                this->x[i][j] = sol->x[i][j];
            }
        }

        this->voisins.clear();
        auto it = sol->voisins.begin();
        while( it != sol->voisins.end() ) 
        {
            this->voisins.push_back(*it);
            it++;
        }
    }
}



/*
Solution::~Solution() {
    for (unsigned i = 0; i < inst->remorques->size(); i++) {
        delete this->circuits->at(i);
        //// cout << "Solution::~Solution pout i=" << i;
    }
    delete this->circuits;
}

Solution::Solution(const Solution& Sol){
    this->inst = Sol.inst;
    this->circuits = new vector<Circuit*>(this->inst->remorques->size());
    // for (vector<Remorque*>::iterator it = inst->remorques->begin(); it != inst->remorques->end(); it++) {
    //     Remorque* remorque = *it;
    // }
    // for (auto it = inst->remorques->begin(); it != inst->remorques->end(); it++) {
    //     Remorque* remorque = *it;
    // }
    for (unsigned i = 0; i < inst->remorques->size(); i++) {
        Remorque* remorque = inst->remorques->at(i);
        Circuit* circ = new Circuit(inst, remorque);
        Circuit* sol_circuit = Sol.circuits->at(i);
        for (auto it = sol_circuit->stations->begin(); it != sol_circuit->stations->end(); ++it) {
        	Station* station = *it;
        	circ->insert(station,-1);
        }
        this->circuits->at(i) = circ; // ne marche que si circuits prédimentionné
        // this->circuits->push_back(circ);
        // this->circuits->at(i) = new Circuit(inst, inst->remorques->at(i));
    }

    // La solution est invalide à la construction : on invente un coût
    // "infini" grâce à un longueur arbitrairement élevée !
    // this->length = 0;
    this->length = 999999999;
    this->desequilibre = 0;

}


void Solution::clear() {
    length = 999999999;
    this->desequilibre = 0;
    for (unsigned i = 0; i < circuits->size(); i++) {
        circuits->at(i)->clear();
    }
}
*/






////////////////////////////////////////////////////////////////////////////
//
//      Affichage et sauvegarde
//
////////////////////////////////////////////////////////////////////////////

void Solution::console_print() {
    for (int i = 1; i <= this->m; i++)
    {
      cout << "|";
      for (int j = 1; j <= this->n; j++)
      {
        if (this->x[i][j] == 1)
        {
          cout << ("x|");
        } else
        {
          cout << (" |");
        }
      }
      cout << "" << endl;
    }
    cout << "Nombre de mailles sélectionnées : " << this->size << "\n" << endl;
}


string Solution::get_tmp_filename() {
    ostringstream buf;
    buf << data->name << "-" << this->size
        << ".sol";

    return buf.str();
}

string Solution::to_s(Options* args, double diff) {
    /// cout << "# solution pour " << inst->name << endl;
    ostringstream buf;
    time_t rawtime;
    time (&rawtime);
    buf << "Solution générée le : " << ctime(&rawtime) << endl;
    if (args->solver == 1) {
        buf << "Résolution par le solveur Cplex" << endl;
    }
    else if (args->solver == 2)
    {
        buf << "Avec le solveur Frontal" << endl;
    }
    else if (args->solver == 3)
    {
        buf << "Avec le solveur Glouton" << endl;
    }
    else if (args->solver == 4)
    {
        buf << "Avec la méthode du Recuit Simulé" << endl;
    }
    else if (args->solver == 5)
    {
        buf << "Avec le solveur Lagrangien" << endl;
    }
    buf << endl;
    buf << "Nom : "          << U::file_basename(data->name, ".dat")         << endl;
    buf << endl;
    buf << "Nombre de mailles sélectionnées : " << this->size << endl;
    buf << endl;
    for (int i = 1; i <= this->m; i++)
    {
      buf << "|";
      for (int j = 1; j <= this->n; j++)
      {
        if (this->x[i][j] == 1)
        {
          buf << ("x|");
        } else
        {
          buf << (" |");
        }
      }
      buf << "" << endl;
    }
    buf << "Temps de résolution : " << diff << "s" << endl;
    return buf.str();
}


void Solution::main_print_solution(Solution* sol, Options* args, double diff) {
    logn3("Enregistemenet éventuel de la solution\n");
    if (args->outfilename != "") {
        if (args->outfilename == "_AUTO_") {
            if (args->filename != "") {
                ostringstream buf;
                buf << U::file_basename(args->filename, ".dat")
                    << "-s" << args->solver
                    << "-" << sol->size
                    << ".sol";
                args->outfilename = buf.str();
            } else {
                args->outfilename = sol->get_tmp_filename();
            }
        }
        U::write_file(args->outfilename, sol->to_s(args, diff));
    }

}


////////////////////////////////////////////////////////////////////////////
//
//      Autres fonctions
//
////////////////////////////////////////////////////////////////////////////

bool Solution::check_connexity()
{
    bool connex = true;

    // Recherche d'un point de départ sélectionné
    bool start = false;
    int i = 1;
    int j = 1;
    while (!start)
    {
        if (this->x[i][j] == 1) {
            start = true;
            break;
        }
        if (j == this->n) {
            i++;
            j = 1;
        } else {
            j++;
        }
    }

    // Marquage des mailles déjà visitées
    vector<vector<int>> Marquage; // 0: pas sélec, 1: sélec dans la sol, 2: dans les voisins, 3: non ajoutable;
    vector<int> row_Zero_int;
    row_Zero_int.push_back(0);
    Marquage.push_back(row_Zero_int);
    for (int a = 1; a <= this->m; a++)
    {
        vector<int> row;
        row.push_back(0);
        for (int b = 1; b <= this->n; b++)
        {
            row.push_back(0);
        }
        Marquage.push_back(row);
    }
    Marquage[i][j] = 1;

    // Init des voisins
    Maille voisin;
    vector<Maille> expend_voisinage;
    if ((i-1 != 0)&&(this->x[i-1][j] == 1)&&(Marquage[i-1][j] != 1)) {
        voisin.i = i-1;
        voisin.j = j;
        expend_voisinage.push_back(voisin);
        Marquage[i-1][j] = 1;
    }
    if ((i+1 != this->m+1)&&(this->x[i+1][j] == 1)&&(Marquage[i+1][j] != 1)){
        voisin.i = i+1;
        voisin.j = j;
        expend_voisinage.push_back(voisin);
        Marquage[i+1][j] = 1;
    }
    if ((j-1 != 0)&&(this->x[i][j-1] == 1)&&(Marquage[i][j-1] != 1)) {
        voisin.i = i;
        voisin.j = j-1;
        expend_voisinage.push_back(voisin);
        Marquage[i][j-1] = 1;
    }
    if ((j+1 != this->n+1)&&(this->x[i][j+1] == 1)&&(Marquage[i][j+1] != 1)) {
        voisin.i = i;
        voisin.j = j+1;
        expend_voisinage.push_back(voisin);
        Marquage[i][j+1] = 1;
    }


    // Parcours du voisinage jusqu'à être bloqué
    int copenent_size = 1;
    auto it = expend_voisinage.begin();
    while (it != expend_voisinage.end()) {
        i = expend_voisinage[0].i;
        j = expend_voisinage[0].j;
        if ((i-1 != 0)&&(this->x[i-1][j] == 1)&&(Marquage[i-1][j] != 1)) {
            voisin.i = i-1;
            voisin.j = j;
            expend_voisinage.push_back(voisin);
            Marquage[i-1][j] = 1;
        }
        if ((i+1 != this->m+1)&&(this->x[i+1][j] == 1)&&(Marquage[i+1][j] != 1)){
            voisin.i = i+1;
            voisin.j = j;
            expend_voisinage.push_back(voisin);
            Marquage[i+1][j] = 1;
        }
        if ((j-1 != 0)&&(this->x[i][j-1] == 1)&&(Marquage[i][j-1] != 1)) {
            voisin.i = i;
            voisin.j = j-1;
            expend_voisinage.push_back(voisin);
            Marquage[i][j-1] = 1;
        }
        if ((j+1 != this->n+1)&&(this->x[i][j+1] == 1)&&(Marquage[i][j+1] != 1)) {
            voisin.i = i;
            voisin.j = j+1;
            expend_voisinage.push_back(voisin);
            Marquage[i][j+1] = 1;
        }

        copenent_size++;
        expend_voisinage.erase(expend_voisinage.begin()+0);

        it = expend_voisinage.begin();
    }


    if (copenent_size != this->size)
    {
        connex = false;
    }

    return connex;
}






//./
