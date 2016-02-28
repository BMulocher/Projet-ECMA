#include <ilcplex/ilocplex.h>
#include <iostream>
#include <fstream>
#include "data.hpp"

ILOSTLBEGIN

using namespace std;



void IloData::getData(const IloEnv env, string nom_fichier) {

    this->name = nom_fichier;


    char char1, char2, char3, char4;
    int tmp;
    float tmpFloat;
    ifstream fichier(nom_fichier.c_str());

    if(fichier) {
      fichier >> char1 >> char2 >> tmp >> char3;
      this->n = tmp;
      int n = tmp; // pour éviter les data.n dans les boucles

      fichier >> char1 >> char2 >> tmp >> char3;
      this->m = tmp;
      int m = tmp; // pour éviter les data.m dans les boucles

      this->Ha=NumMatrix(env,m);
      fichier >> char1 >> char2 >> char3 >> char4;
      for(int i=1;i<=m;i++)
      {
         fichier >> char1;
         this->Ha.add(IloNumArray(env));
         for(int j=0;j<=n;j++)
         { 
            if (j==0)
            {
              this->Ha[i].add(0);
            } else
            {
              fichier >> tmpFloat >> char1;
              this->Ha[i].add(tmpFloat);
            }
         }
         fichier >> char1;
      }
      fichier >> char1;

      this->Ca=NumMatrix(env,m);
      fichier >> char1 >> char2 >> char3 >> char4;
      for(int i=1;i<=m;i++)
      {
         fichier >> char1;
         this->Ca[i]=IloNumArray(env);
         for(int j=0;j<=n;j++)
         {
            if (j==0)
            {
              this->Ca[i].add(0);
            } else
            {
              fichier >> tmpFloat >> char1;
              this->Ca[i].add(tmpFloat);
            }
         } 
         fichier >> char1;
      }
      fichier >> char1;

      this->Hp=NumMatrix(env,m);
      fichier >> char1 >> char2 >> char3 >> char4;
      for(int i=1;i<=m;i++)
      {
         fichier >> char1;
         this->Hp[i]=IloNumArray(env);
         for(int j=0;j<=n;j++)
         {
            if (j==0)
            {
              this->Hp[i].add(0);
            } else
            {
              fichier >> tmpFloat >> char1;
              this->Hp[i].add(tmpFloat);
            }
         } 
         fichier >> char1;
      }
      fichier >> char1;

      this->Cp=NumMatrix(env,m);
      fichier >> char1 >> char2 >> char3 >> char4;
      for(int i=1;i<=m;i++)
      {
         fichier >> char1;
         this->Cp[i]=IloNumArray(env);
         for(int j=0;j<=n;j++)
         {
            if (j==0)
            {
              this->Cp[i].add(0);
            } else
            {
              fichier >> tmpFloat >> char1;
              this->Cp[i].add(tmpFloat);
            }
         } 
         fichier >> char1;
      }
      fichier >> char1;

      fichier.close();
    }
}















void Data::getData(string nom_fichier) {

    this->name = nom_fichier;


    char char1, char2, char3, char4;
    int tmpInt;
    double tmpDouble;
    ifstream fichier(nom_fichier.c_str());

    if(fichier) {
      fichier >> char1 >> char2 >> tmpInt >> char3;
      this->n = tmpInt;
      int n = tmpInt; // pour éviter les data.n dans les boucles

      fichier >> char1 >> char2 >> tmpInt >> char3;
      this->m = tmpInt;
      int m = tmpInt; // pour éviter les data.m dans les boucles

      //
      vector<double> row_Zero;
      row_Zero.push_back(0);

      // Ha
      this->Ha.push_back(row_Zero);
      fichier >> char1 >> char2 >> char3 >> char4;
      for(int i=1;i<=m;i++)
      {
         vector<double> row;
         row.push_back(0);
         fichier >> char1;
         for(int j=1;j<=n;j++)
         { 
            fichier >> tmpDouble >> char1;
            row.push_back(tmpDouble);;
         }
         fichier >> char1;
         this->Ha.push_back(row);
      }
      fichier >> char1;

      // Ca
      this->Ca.push_back(row_Zero);
      fichier >> char1 >> char2 >> char3 >> char4;
      for(int i=1;i<=m;i++)
      {
         vector<double> row;
         row.push_back(0);
         fichier >> char1;
         for(int j=1;j<=n;j++)
         { 
            fichier >> tmpDouble >> char1;
            row.push_back(tmpDouble);;
         }
         fichier >> char1;
         this->Ca.push_back(row);
      }
      fichier >> char1;

      // Hp
      this->Hp.push_back(row_Zero);
      fichier >> char1 >> char2 >> char3 >> char4;
      for(int i=1;i<=m;i++)
      {
         vector<double> row;
         row.push_back(0);
         fichier >> char1;
         for(int j=1;j<=n;j++)
         { 
            fichier >> tmpDouble >> char1;
            row.push_back(tmpDouble);;
         }
         fichier >> char1;
         this->Hp.push_back(row);
      }
      fichier >> char1;

      // Cp
      this->Cp.push_back(row_Zero);
      fichier >> char1 >> char2 >> char3 >> char4;
      for(int i=1;i<=m;i++)
      {
         vector<double> row;
         row.push_back(0);
         fichier >> char1;
         for(int j=1;j<=n;j++)
         { 
            fichier >> tmpDouble >> char1;
            row.push_back(tmpDouble);;
         }
         fichier >> char1;
         this->Cp.push_back(row);
      }
      fichier >> char1;


      fichier.close();
    }
}