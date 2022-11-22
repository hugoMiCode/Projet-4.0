#pragma once
#include <iostream>
#include <fstream>
#include "EntreeSecurisee.h"
using namespace std;


class ZFraction
{
public:
	ZFraction(int num = 0, int den = 1);
	bool estEgale(ZFraction const& a) const;
	bool estInferieur(ZFraction const& a) const;

	ZFraction& operator+=(ZFraction const& a);
	ZFraction& operator-=(ZFraction const& a);
	ZFraction& operator*=(ZFraction const& a);
	ZFraction& operator/=(ZFraction const& a);

	void affiche(ostream& flux) const;
	void simplifie();
	
private:
	int m_num;
	int m_den;
};

bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);

ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);

ZFraction operator-(ZFraction const& a);
ostream& operator<<(ostream& flux, ZFraction const& fraction);
