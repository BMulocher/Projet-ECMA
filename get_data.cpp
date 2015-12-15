#include <ilcplex/ilocplex.h>
#include <iostream>
#include <fstream>

ILOSTLBEGIN

using namespace std;

typedef IloArray<IloIntArray> DataMatrix;
DataMatrix E;
IloInt n, m;
IloNum Ba, Bp;
IloIntArray p;

void getData(const IloEnv env, char nom_fichier[]) {

    char char1, char2, char3, char4;
    int tmp;
    ifstream fichier(nom_fichier);

    if(fichier) {
      fichier >> char1 >> char2 >> tmp >> char3;
      n = tmp;

      fichier >> char1 >> char2 >> tmp >> char3;
      m = tmp;

      fichier >> char1 >> char2 >> tmp >> char3;
      Ba = tmp;

      fichier >> char1 >> char2 >> tmp >> char3;
      Bp = tmp;

      Ha=DataMatrix(env,n);
      fichier >> char1 >> char2 >> char3;
      for(int i=0;i<n;i++)
      {
         fichier >> char1;
         Ha[i]=IloIntArray(env);
         for(int j=0;j<m;j++)
         {
             fichier >> tmp >> char1;
             Ha[i].add(tmp);
         } 
         fichier >> char1;
      }
      fichier >> char1;

      Ca=DataMatrix(env,n);
      fichier >> char1 >> char2 >> char3;
      for(int i=0;i<n;i++)
      {
         fichier >> char1;
         Ha[i]=IloIntArray(env);
         for(int j=0;j<m;j++)
         {
             fichier >> tmp >> char1;
             Ca[i].add(tmp);
         } 
         fichier >> char1;
      }
      fichier >> char1;

      Hp=DataMatrix(env,n);
      fichier >> char1 >> char2 >> char3;
      for(int i=0;i<n;i++)
      {
         fichier >> char1;
         Ha[i]=IloIntArray(env);
         for(int j=0;j<m;j++)
         {
             fichier >> tmp >> char1;
             Hp[i].add(tmp);
         } 
         fichier >> char1;
      }
      fichier >> char1;

      Cp=DataMatrix(env,n);
      fichier >> char1 >> char2 >> char3;
      for(int i=0;i<n;i++)
      {
         fichier >> char1;
         Ha[i]=IloIntArray(env);
         for(int j=0;j<m;j++)
         {
             fichier >> tmp >> char1;
             Cp[i].add(tmp);
         } 
         fichier >> char1;
      }
      fichier >> char1;

      fichier.close();
    }
}