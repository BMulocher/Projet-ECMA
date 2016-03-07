#include "common.hpp"
#include "data.hpp"
#include "solver.hpp"

#include "options.hpp"

// je dois définir cette variable statique en dehors de la classe Options
Options* Options::args = NULL;

// TODO : Remplacer classe Solver par un interface purement abstraite
//        et réorganiser ce fichier
//
int main(int argc, char *argv[]) {

    // Analyse et extraction des arguments de la ligne de commande -----------------------
    Options::args =  new Options(argc, argv);
    Options* args = Options::args;
    // -----------------------------------------------------------------------------------


    /*
    // Exemple d'affichage de quelques options
    cout << "args->solver=" << args->solver << endl;
    cout << "args->seed=" << args->seed << endl;
    cout << "args->filename=" << args->filename << endl;
    cout << "args->outfilename=" << args->outfilename << endl;
    */




    // Démarrage d'un chronomètre --------------------------------------------------------
    time_t start_time;
    time(&start_time);
    // -----------------------------------------------------------------------------------




    // Lecture des données ---------------------------------------------------------------
    Data data;
    data.getData(args->filename);
    // -----------------------------------------------------------------------------------




    // Création d'une solution -----------------------------------------------------------
    Solution* sol = new Solution(data);
    // -----------------------------------------------------------------------------------




    // Appel(s) au(x) solveurs -----------------------------------------------------------
    if (args->solver == 1) 
    {
        logn1("Solver 1 : Frontal");
        FrontalSolver* solver = new FrontalSolver();
        solver->solve(data, sol);
        if (solver->found) {
            //
        } else {
            cout << "FrontalSolver : pas de solution" << endl;
        }
        delete solver;
        logn1("Solver 1 : fin de FrontalSolver");





    } else if (args->solver == 2)
    {
        // Borne sup sans la connexité
        logn1("Solver 2 : NoConnex");
        NoConnexSolver* solver = new NoConnexSolver();
        solver->solve(data, sol);
        if (solver->found) {
            //
        } else {
            cout << "NoConnexSolver : pas de solution" << endl;
        }
        delete solver;
        logn1("Solver 2 : fin de NoConnexSolver");

        






    } else if (args->solver == 3)
    {
        logn1("Solver 3 : Glouton");
        GloutonSolver* solver = new GloutonSolver();
        solver->solve(data, sol);
        if (solver->found) {
            //
        } else {
            cout << "GloutonSolver : pas de solution" << endl;
        }
        delete solver;
        logn1("Solver 3 : fin de GloutonSolver");








    } else if (args->solver == 4)
    {

        logn1("Solver 4 : Recuit");
        RecuitSolver* solver = new RecuitSolver();
        solver->solve(data, sol);
        if (solver->found) {
            //
        } else {
            cout << "RecuitSolver : pas de solution" << endl;
        }
        delete solver;
        logn1("Solver 4 : fin de RecuitSolver");



    } else if (args->solver == 5)
    {

        logn1("Solver 5 : Lagrangien");
        LagrangianSolver* solver = new LagrangianSolver();
        solver->solve(data, sol);
        if (solver->found) {
            //
        } else {
            cout << "LagrangianSolver : pas de solution" << endl;
        }
        delete solver;
        logn1("Solver 5 : fin de LagrangianSolver");



    } else if (args->solver == 6)
    {

        logn1("Solver 6 : Relaché continu");
        relaxedSolver* solver = new relaxedSolver();
        solver->solve(data, sol);
        if (solver->found) {
            //
        } else {
            cout << "relaxedSolver : pas de solution" << endl;
        }
        delete solver;
        logn1("Solver 6 : fin de relaxedSolver");




    } else if (args->solver == 7)
    {

        logn1("Solver 7 : Génération de Colonnes");
        colgenSolver* solver = new colgenSolver();
        solver->solve(data, sol);
        if (solver->found) {
            //
        } else {
            cout << "colgenSolver : pas de solution" << endl;
        }
        delete solver;
        logn1("Solver 7 : fin de colgenSolver");





    }else
    {
        //
    }
    // -----------------------------------------------------------------------------------




    // Affichage et enregistrement des données -------------------------------------------
        // todo, dans des fonctions propres de la classe Solution
    sol->console_print();
    // -----------------------------------------------------------------------------------


    

    // Arrêt et exploitation du chronomètre ----------------------------------------------
    time_t end_time;
    time(&end_time);
    double diff = difftime(end_time, start_time);
    printf("Temps de calcul:\t %.1fs\n", diff);
    //csv_file << diff << endl;
    //cout << "Temps de calcul:\t" << diff << "s" << endl << endl;
    // -----------------------------------------------------------------------------------

    // Print dans un fichier externe
    Solution::main_print_solution(sol, args, diff);


    // Nettoyage des objets alloués dans ce main() ---------------------------------------
        // todo : coder les destructeurs de chaque classe
    // delete data;
    // delete solver;
    // delete args;
    // -----------------------------------------------------------------------------------

    return 0;
}
//./
