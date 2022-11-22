#ifndef CRYPTAGE_H
#define CRYPTAGE_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include "EntreeSecurisee.h"
using namespace std;

class Cryptage
{
public:
    Cryptage(int a);
    Cryptage();

    vector<string> chiffrement(string message, string clef);
    string dechiffrement(string message, string clef);
    vector<int> generation(vector<int>& clef, vector<int> const& message);
    vector<int> transformation(vector<int> const& clef, vector<int> const& message);
    vector<int> transformation_decryptage(vector<int> const& clef, vector<int> const& message);
};

#endif // CRYPTAGE_H
