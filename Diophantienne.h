#ifndef DIOPHANTIENNE_H
#define DIOPHANTIENNE_H
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include <time.h>
#include <ctime>
#include <chrono>
#include "EntreeSecurisee.h"
using namespace std;

class Diophantienne
{
public:
    Diophantienne();
    Diophantienne(int a);
    ~Diophantienne();
    int entree_securisee();
    string equation_acctuel(int a, int b, vector<int> solution);
    int pgcd(int a, int b);
    string equation(int a, int b);
    vector<int> fsolution_while(int& a, int& b, double& temps);
    void affichage1(int a, int b, vector<int> solution);
    void fResolution2(int a, int b, vector<int> solution);

private:


};


#endif // DIOPHANTIENNE_H
