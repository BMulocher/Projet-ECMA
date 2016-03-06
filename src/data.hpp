#ifndef DATA_H
#define DATA_H
#include <ilcplex/ilocplex.h>
#include <iostream>
#include <fstream>
#include "common.hpp"

ILOSTLBEGIN

using namespace std;


typedef IloArray<IloIntArray>       IntMatrix;
typedef IloArray<IloNumArray>       NumMatrix;
typedef IloArray<IloBoolArray>      BoolMatrix;
typedef IloArray<IloNumVarArray>    NumVarMatrix;
typedef IloArray<NumVarMatrix>      NumVarTriMat;
typedef IloArray<IloIntVarArray>    IntVarMatrix;
typedef IloArray<IloBoolVarArray>   BoolVarMatrix;
typedef IloArray<BoolVarMatrix>     BoolVarTriMat;



// Inutile mtn, je la garde au cas où
class IloData {
public:
	string name;

	IloInt n, m;
	NumMatrix Ha, Ca, Hp, Cp;


	void getData(const IloEnv env, string nom_fichier);

};



class Data {
public:
	string name;
	int m, n;
	vector<vector<double>> Ha, Ca, Hp, Cp;

	void getData(string nom_fichier);
};




class Maille {
public:
	int i;
	int j;

};




#endif
//./
