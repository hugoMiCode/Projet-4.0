#pragma once
#ifndef ENTREESECURISEE_H
#define ENTREESECURISEE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <array>
#include <vector>
#include "ZFraction.h"
using namespace std;

class EntreeSecurisee
{
public:
	static bool trueFalse();
	static int integer(bool negatif, int limiteMin = -1000000000, int limiteMax = 1000000000);
	static vector<int> fraction(bool negatif = true);
	static string validation2();
	static vector<int> association(string const message);
	static vector<char> finalisation(vector<int> const message);
	static int pgcd(int a, int b);
	static void vider_buffer();

};


#endif