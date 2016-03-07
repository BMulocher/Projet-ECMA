#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include "common.hpp"
#include "options.hpp"
#include "data.hpp"

// CONVENTION : les objets de cette classe seront généralement appelés
// sol1, sol2, pour ne pas confodre avec solver (de clasee Solver !) ou
// s1 et s2 de classe  Site ou Station.
//
class Solution {
public:

    Data* data;
    
    // Les données associées
    int m;
    int n;

    // Vecteur paramétrant les mailles retenues (on met des doubles au cas où on veut récup une sol d'un relaché...)
    vector<vector<double>> x;

    // Valeur du membre de gauche de la contrainte principale (cf énoncé)
    //double constraint_value;

    // Nombre de mailles retenues
    int size;


    // Meilleure borne sup/inf dont on dispose (si on en a pas n*m)
    int UpperBound;
    int LowerBound;


    // Liste des mailles qui juxtent cellent actuellement sélectionnée (ie possible ajouts connexe)
    vector<Maille> voisins;

    // Valeur des numérateurs et dénominateurs de la contrainte originelle
    double NumP;
    double DenumP;
    double NumA;
    double DenumA;





    // Constructeurs -------------------------------------------------------------------------------------------------------------

    Solution();

    Solution(Data data);

    // Attention : ceci n'est pas le constructeur par copie car il prend un **pointeur** en parametre
    Solution(const Solution* sol);

    void copy(Solution* sol);

    /*
    //constructeur par copy
    Solution(const Solution& Sol);

    // Le constructeur par copie officiel c++
    /// Solution(const Solution&);

    void copy(Solution* other);

    virtual ~Solution();
    */


    // Autre trucs ---------------------------------------------------------------------------------------------------------------
    bool check_connexity();


    // Affcihege et sauvegarde ---------------------------------------------------------------------------------------------------

    // Pour afficher la solution vite fait dans la console
    void console_print();

    // Construit un nom de fichier basé sur le nom du fichier de donnees
    string get_tmp_filename();

    // Retourne la chaine de sortie de la solutin au format standard
    string to_s(Options* args, double diff);

    // Pour save et plot la solution
    static void main_print_solution(Solution* solution, Options* args, double diff);

};


#endif
