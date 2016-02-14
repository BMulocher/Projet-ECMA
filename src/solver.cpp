#include "solver.hpp"

Solver::Solver() {

    name = "S_0_abstract";
    desc = "Par itération : un simplex + un mip + un seul sous tour";

    found = false;
}
Solver::~Solver() {
    // todo;
}

// Méthode principale de ce solver, principe :
//
bool Solver::solve(Data data, Solution* sol) {
    found = false;
    return found;
}
// ./

