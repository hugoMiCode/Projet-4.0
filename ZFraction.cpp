#include "ZFraction.h"

ZFraction::ZFraction(int num, int den) : m_num(num), m_den(den)
{
	simplifie();
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
	return a.estEgale(b); 
}

bool operator!=(ZFraction const& a, ZFraction const& b)
{
	return !(a == b);
}

bool operator<(ZFraction const& a, ZFraction const& b)
{
	return a.estInferieur(b);
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
	return b.estInferieur(a);
}

bool operator<=(ZFraction const& a, ZFraction const& b)
{
	return !(b.estInferieur(a));
}

bool operator>=(ZFraction const& a, ZFraction const& b)
{
	return !(a.estInferieur(b));
}

ostream& operator<<(ostream& flux, ZFraction const& fraction)
{
	fraction.affiche(flux);
	return flux;
}


ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie += b;
	return copie;
}

ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie -= b;
	return copie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie *= b;
	return copie;
}

ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie /= b;
	return copie;
}

ZFraction operator-(ZFraction const& a)
{
	ZFraction copie(a);
	copie *= -1;
	return copie;
}


ZFraction& ZFraction::operator+=(ZFraction const& a)
{
	m_num = a.m_den * m_num + m_den * a.m_num;
	m_den *= a.m_den;

	simplifie();

	return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const& a)
{
	m_num = a.m_den * m_num - m_den * a.m_num;
	m_den *= a.m_den;

	simplifie();

	return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& a)
{
	m_num *= a.m_num;
	m_den *= a.m_den;

	simplifie();

	return *this;
}

ZFraction& ZFraction::operator/=(ZFraction const& a)
{
	m_num *= a.m_den;
	m_den *= a.m_num;

	simplifie();

	return *this;
}




void ZFraction::simplifie()
{
	int pgcd{ EntreeSecurisee::pgcd(m_num, m_den) };

	m_num /= pgcd;
	m_den /= pgcd;
}

bool ZFraction::estInferieur(ZFraction const& a) const
{
	return (m_num * a.m_den < m_den* a.m_num);
}

bool ZFraction::estEgale(ZFraction const& b) const
{
	return m_num == b.m_num && m_den == b.m_den;
}

void ZFraction::affiche(ostream& flux) const
{
	if (m_den == 1)
		flux << m_num;
	else
		flux << m_num << '/' << m_den;
}