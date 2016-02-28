#include "voisinage.hpp"
#include "solution.hpp"




bool tryAdd(Data data, Solution* sol, int pos_maille) {

	bool add = true;

	int i = sol->voisins[pos_maille].i;
	int j = sol->voisins[pos_maille].j;
	Maille voisin;

	double updated_cost = (sol->NumP + data.Hp[i][j]*data.Cp[i][j])/(sol->DenumP + data.Cp[i][j]) + (sol->NumA + data.Ha[i][j]*data.Ca[i][j])/(sol->DenumA + data.Ca[i][j]);

	if ((updated_cost >= 2)&&(data.Cp[i][j] != 0)&&(sol->x[i][j] != 1))
	{
	    // On l'ajoute
	    sol->x[i][j] = 1;
	    // Maj des parts du coût
	    sol->NumP = sol->NumP + data.Hp[i][j]*data.Cp[i][j];
	    sol->DenumP = sol->DenumP + data.Cp[i][j];
	    sol->NumA = sol->NumA + data.Ha[i][j]*data.Ca[i][j];
	    sol->DenumA = sol->DenumA + data.Ca[i][j];
	    // Maj de la taille de la sol
	    sol->size++;
	    // Ajout des voisins à la liste
	    if ((i-1 != 0)&&(sol->x[i-1][j] == 0)) {
	    	sol->x[i-1][j] = 2;
	        voisin.i = i-1;
	        voisin.j = j;
	        sol->voisins.push_back(voisin);
	    }
	    if ((i+1 != data.m+1)&&(sol->x[i+1][j] == 0) ){
	    	sol->x[i+1][j] = 2;
	        voisin.i = i+1;
	        voisin.j = j;
	        sol->voisins.push_back(voisin);
	    }
	    if ((j-1 != 0)&&(sol->x[i][j-1] == 0)) {
	    	sol->x[i][j-1] = 2;
	        voisin.i = i;
	        voisin.j = j-1;
	        sol->voisins.push_back(voisin);
	    }
	    if ((j+1 != data.n+1)&&(sol->x[i][j+1] == 0)) {
	    	sol->x[i][j+1] = 2;
	        voisin.i = i;
	        voisin.j = j+1;
	        sol->voisins.push_back(voisin);
	    }
	    // On supprime la maille sélectionnée de la liste des voisins
	    sol->voisins.erase(sol->voisins.begin()+pos_maille);
	} else
	{
		add = false;
	}

	return add;
}



bool tryRemove(Data data, Solution* sol, Maille maille) {

	bool rmv = true;

	int i = maille.i;
	int j = maille.j;
	if (sol->x[i][j] == 1)
	{
		sol->x[i][j] = 0;
		sol->size--;

		double updated_cost = (sol->NumP - data.Hp[i][j]*data.Cp[i][j])/(sol->DenumP - data.Cp[i][j]) + (sol->NumA - data.Ha[i][j]*data.Ca[i][j])/(sol->DenumA - data.Ca[i][j]);

		if ((sol->check_connexity())&&(updated_cost >= 2))
		{
			sol->x[i][j] = 1;
			sol->size++;
			rmv = false;
		} else
		{
			sol->NumP = sol->NumP - data.Hp[i][j]*data.Cp[i][j];
		    sol->DenumP = sol->DenumP - data.Cp[i][j];
		    sol->NumA = sol->NumA - data.Ha[i][j]*data.Ca[i][j];
		    sol->DenumA = sol->DenumA - data.Ca[i][j];
			sol->voisins.push_back(maille);

			auto it = sol->voisins.begin();
			while(it != sol->voisins.end())
			{
				int vi = (*it).i;
				int vj = (*it).j;
				bool v1 = ((vi-1 == 0)||(sol->x[vi-1][vj] == 0));
				bool v2 = ((vi+1 == data.m+1)||(sol->x[vi+1][vj] == 0));
				bool v3 = ((vj-1 == 0)||(sol->x[vi][vj-1] == 0));
				bool v4 = ((vj+1 == data.n+1)||(sol->x[vi][vj+1] == 0));
				if (v1 && v2 && v3 && v4)
				{
					sol->voisins.erase(it);
					sol->x[vi][vj] = 0;
				} else
				{
					it++;
				}
			}
		}
	}

	return rmv;
}





Solution* select_voisin(Data data, Solution* current, Solution* neighbor, int iter)
{
    //voisin->clear();
    neighbor->copy(current);

 	// on fait un rmv toutes les 10 itérations
    if ((iter % 10 != 0)||(iter == 0))
    {
	    // calcul des probas de selection
	    vector<double> add_proba;
	    auto it = neighbor->voisins.begin();
	    while (it != neighbor->voisins.end())
	    {
	    	add_proba.push_back(0);
	    	it++;
	    }
	    compute_proba_add(data, neighbor, add_proba);

	    // tirage de la maille à ajouter selon la loi de proba précédente
	    int pos_maille = select_add_with_proba(data, neighbor, add_proba);

	    // Ajout (si c'est possible) de la maille sélectionnée
	    tryAdd(data, neighbor, pos_maille);


	} else
	{
		// calcul des probas de selection
	    vector<vector<double>> rmv_proba;
	    vector<double> row_Zero;
	    row_Zero.push_back(0);
	    rmv_proba.push_back(row_Zero);
	    for (int i = 1; i <= data.m; i++)
	    {
	        vector<double> row;
	        row.push_back(0);
	        for (int j = 1; j <= data.n; j++)
	        {
	            row.push_back(0);
	        }
	        rmv_proba.push_back(row);
	    }

	    compute_proba_rmv(data, neighbor, rmv_proba);

	    // tirage de la maille à ajouter selon la loi de proba précédente
	    Maille pos_maille = select_rmv_with_proba(data, neighbor, rmv_proba);

	    // Ajout (si c'est possible) de la maille sélectionnée
	    tryRemove(data, neighbor, pos_maille);
	}


    return neighbor;
}




void compute_proba_add(Data data, Solution* sol, vector<double> &add_proba) {

	int i = 0;
	int j = 0;
	int pos = 0;
	double updated_cost = 0;
	double sum_add_proba = 0;
	auto it = sol->voisins.begin();
	while (it != sol->voisins.end())
	{
		i = (*it).i;
		j = (*it).j;
		updated_cost = (sol->NumP + data.Hp[i][j]*data.Cp[i][j])/(sol->DenumP + data.Cp[i][j]) + (sol->NumA + data.Ha[i][j]*data.Ca[i][j])/(sol->DenumA + data.Ca[i][j]);
		if ((updated_cost >= 2)&&(data.Cp[i][j] != 0))
		{
			//add_proba[pos] = 1; // a changer éventuellement. Tel quel : proba uniforme sur les trucs acceptables
			add_proba[pos] = data.Hp[i][j] + data.Ha[i][j];
			sum_add_proba = sum_add_proba + add_proba[pos];
		} else
		{
			add_proba[pos] = 0;
		}
		pos++;
		it++;
	}

	// Normalisation des probas
	if (sum_add_proba != 0)
	{
		pos = 0;
		it = sol->voisins.begin();
		while (it != sol->voisins.end())
		{
			add_proba[pos] = add_proba[pos] / sum_add_proba;
			pos++;
			it++;
		}
	} else
	{
		//cout << "o";
	}
}




int select_add_with_proba(Data data, Solution* sol, vector<double> add_proba) {

	int sel = 0; // position dans la liste voisins de la mailel qu'on va sélectionner

	double p = double(rand()) / double(RAND_MAX); // tirage rand
	double sum_p = 0;

	auto it = sol->voisins.begin();
	while (it != sol->voisins.end())
	{
		if ((sum_p <= p)&&(p < sum_p+add_proba[sel])) {
			return sel;
		}
		sum_p = sum_p + add_proba[sel]; // maj pour l'intervalle suivant
		sel++; // maj de la position de la station dans le circuit
		it++;
	}
	return 0; // normalement en return tjs dans la boucle, juste pour eviter les warning
}






void compute_proba_rmv(Data data, Solution* sol, vector<vector<double>> &rmv_proba) {

	double sum_rmv_proba = 0;
	double updated_cost = 0;

	for (int i = 1; i <= data.m; i++)
	{
		for (int j = 1; j <= data.n; j++)
		{
			if (sol->x[i][j] == 1)
			{
				updated_cost = (sol->NumP - data.Hp[i][j]*data.Cp[i][j])/(sol->DenumP - data.Cp[i][j]) + (sol->NumA - data.Ha[i][j]*data.Ca[i][j])/(sol->DenumA - data.Ca[i][j]);
				// on vérifie que ça garde le truc connexe
				sol->x[i][j] = 0;
				sol->size--;
				bool connex = sol->check_connexity();
				sol->x[i][j] = 1;
				sol->size++;
				if ((updated_cost >= 2)&&(connex))
				{
					//rmv_proba[i][j] = 1;
					rmv_proba[i][j] = 1/(data.Hp[i][j]+data.Ha[i][j]+1);
				} else
				{
					rmv_proba[i][j] = 0;
				}
			} else
			{
				rmv_proba[i][j] = 0;
			}
			sum_rmv_proba = sum_rmv_proba + rmv_proba[i][j];
		}
	}

	// Normalisation des porobas
	if (sum_rmv_proba != 0)
	{
		for (int i = 1; i <= data.m; i++)
		{
			for (int j = 1; j <= data.n; j++)
			{
				rmv_proba[i][j] = rmv_proba[i][j] / sum_rmv_proba;
			}
		}
	} else
	{
		//cout << "O";
	}
}





Maille select_rmv_with_proba(Data data, Solution* sol, vector<vector<double>> rmv_proba) {

	Maille sel;
	sel.i = 1;
	sel.j = 1;

	double p = double(rand()) / double(RAND_MAX); // tirage rand
	double sum_p = 0;

	for (int i = 1; i <= data.m; i++)
	{
		for (int j = 1; j <= data.n; j++)
		{
			if ((sum_p <= p)&&(p < sum_p+rmv_proba[i][j])) {
				sel.i = i;
				sel.j = j;
				return sel;
			}
			sum_p = sum_p + rmv_proba[i][j]; // maj pour l'intervalle suivant
		}
	}
	return sel; // normalement en return tjs dans la boucle, juste pour eviter les warning
}







//./
