#pragma once
#ifndef ENTREESECURISEE_H
#define ENTREESECURISEE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <array>
#include <vector>
using namespace std;

class EntreeSecurisee
{
public:
	static bool trueFalse();
	static int integer(bool negatif);
	static string validation2();
	static vector<int> association(string const message);
	static vector<char> finalisation(vector<int> const message);

};


#endif