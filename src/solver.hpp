#ifndef SOLVER_H
#define SOLVER_H

#include "common.hpp"
#include "data.hpp"
#include "solution.hpp"
#include "voisinage.hpp"

class Solver {
public:

    // nom court du solver e.g "S_1_glouton"
    string name;
    // description en une ligne
    // e.g "Par itération : un simplex + un mip + un seul sous tour"
    string desc;

    // pointeur sur l'instance du problème
    //Instance* inst;

    // un boolean parmettent de connaitre l'état de la résolution en fin de calcul
    // TODO : différencier les états "optimum trouvé" dans état "interrompu avant
    // optimum"
    // true : le solveur à terminé normalement sa fonction qui dépend de la
    //        méthode appelée, en général c'est que l'optimum a été trouvé
    // false : une interruption à été déclenchée avant la fin de la résolution
    // TODO TRANSFORMER EN ATTRIBUT state :
    // - found : solution trouvée fin normale du solver
    // - notfound : solution non trouvée (car interuption avant la fin, ...)
    // - optimum : solution optimale trouvée (version branch and bound ou PPC)
    //
    // enum State {
    //     INIT,
    //     RUNING,
    //     INTERRUPTED,
    //     FOUND,
    //     OPTIMUM
    // }
    // State state = INIT;
    bool found;

    //Solution* solution;

    Solver();

    virtual ~Solver();

    // La principal méthode à redéfinir par les classes filles
    //
    virtual bool solve(Data data, Solution* sol);
    // virtual State solve();

    //virtual Solution* get_solution()  {return solution ; };

};

////////////////////////////////////////////////////////////////////////
// Déclaration des solveur spécialisés
//

class FrontalSolver : public Solver {
public:
    FrontalSolver();
    virtual ~FrontalSolver();
    virtual bool solve(Data data, Solution* sol);
    void setFrontal (Data data, Solution* sol, IloModel model, BoolVarMatrix x, NumVarMatrix a, NumVarMatrix p, BoolVarTriMat d , IloRangeArray constraints);
    //Solution* get_solution() {return this->solution;};
};

class NoConnexSolver : public Solver {
public:
    NoConnexSolver();
    virtual ~NoConnexSolver();
    virtual bool solve(Data data, Solution* sol);
    void setNoConnex (Data data, Solution* sol, IloModel model, BoolVarMatrix x, NumVarMatrix a, NumVarMatrix p, BoolVarTriMat d , IloRangeArray constraints);
    //Solution* get_solution() {return this->solution;};
};

class GloutonSolver : public Solver {
public:
        GloutonSolver();
        virtual ~GloutonSolver();
        virtual bool solve(Data data, Solution* sol);
};

class RecuitSolver : public Solver {
public:
        RecuitSolver();
        virtual ~RecuitSolver();
        virtual bool solve(Data data, Solution* sol);
        Solution* recuit(Data data, Solution* solution, double T0, double prog_geo_T, int max_prop, int itermax, double TAU_MIN);

};

class LagrangianSolver : public Solver {
public:
    LagrangianSolver();
    virtual ~LagrangianSolver();
    virtual bool solve(Data data, Solution* sol);
    void setLagrangian (Data data, Solution* sol, IloModel model, BoolVarMatrix x, NumVarMatrix a, NumVarMatrix p, BoolVarTriMat d, IloNum lambda, IloRangeArray constraints);
    //Solution* get_solution() {return this->solution;};
};

class relaxedSolver : public Solver {
public:
    relaxedSolver();
    virtual ~relaxedSolver();
    virtual bool solve(Data data, Solution* sol);
    void setrelaxed (Data data, Solution* sol, IloModel model, NumVarMatrix x, NumVarMatrix a, NumVarMatrix p, NumVarTriMat d , IloRangeArray constraints);
    //Solution* get_solution() {return this->solution;};
};


#endif

