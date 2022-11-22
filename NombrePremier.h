#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#include <string>
#include "EntreeSecurisee.h"

class NombrePremier
{
public:
	NombrePremier();
	~NombrePremier();
	int entree_securiseAffichage(vector<int> & nombresPremiers);
	bool test_primalite(int n);
	unordered_map <int, int> decomposition(unsigned int n);
	void determination_premier(int n);
	vector<int> fichier(int n, string nom);
	vector<int> listeDiviseurs(int n);
};


