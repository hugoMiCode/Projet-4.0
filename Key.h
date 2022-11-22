#pragma once
#ifndef KEY_H
#define KEY_H
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
#include "EntreeSecurisee.h"
using namespace std;


class Key
{
public:
	Key();
	~Key();
	string cassage(string message_decrypte, string message_crypte);
	vector<int> subtitution(vector<int> message_decrypte, vector<int> message_crypte);
private:

};

#endif

