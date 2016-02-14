#ifndef VOISINAGE_H
#define VOISINAGE_H

#include "common.hpp"
#include "data.hpp"
#include "solution.hpp"



Solution* select_voisin(Data data, Solution* solution, Solution* voisin, int iter);
	// fonction realisant la selection d'une solution voisine de la solution courante "current"
	// fait appel aux autres fonctions

bool tryAdd(Data data, Solution* sol, int pos_maille);
	// Tente d'ajouter une maille parmis celles qui ne cassent pas la connexité de la sol

bool tryRemove(Data data, Solution* sol, Maille maille);
	// Tente de retirer une maille en vérifiant si ça casse ou pas la connexité de la sol

void compute_proba_add(Data data, Solution* sol, vector<double> &add_proba);
	// Associe à chaque voisin une proba d'être sélectionné pour être ajouté à la sol courante

int select_add_with_proba(Data data, Solution* sol, vector<double> add_proba);
	// Selectionne une maille à ajouter selon la loi de proba add_proba

void compute_proba_rmv(Data data, Solution* sol, vector<vector<double>> &rmv_proba);
	// Associe à chaque maille sélectionnée une proba d'être retirée

Maille select_rmv_with_proba(Data data, Solution* sol, vector<vector<double>> rmv_proba);
	// Selectionne une maille à retirer de la sol selon la loi de proba rmv_proba


#endif
//./
