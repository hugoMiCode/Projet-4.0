#include "Systeme.h"
#include "EntreeSecurisee.h"

Systeme::Systeme()
{
	cout << "Bienvenue dans le programme de résolution de systeme d'équation." << endl << endl;
	int degre{ 0 };
	do {
		cout << "Choisissez le nombre d'inconnu(s) du système d'équation (1,2,3) : ";
		degre = EntreeSecurisee::integer(false, 1, 3);

		if (degre == 1)
		{
			degre1();
		}
		else if (degre == 2)
		{
			degre2();
		}
		else if (degre == 3)
		{
			degre3();
		}
		cout << endl << endl << "Voulez vous rentrer un autre systeme ? (true/false) : ";

	} while (EntreeSecurisee::trueFalse());
}

void Systeme::degre1()
{
	cout << "Bienvenue dans le programme de résolution d'équation du type :\n{ ax + b = u ;" << endl << endl;

	cout << "Rentrez a : ";
	vector<int> a_V = EntreeSecurisee::fraction();
	cout << "Rentrez b : ";
	vector<int> b_V = EntreeSecurisee::fraction();
	cout << "Rentrez c : ";
	vector<int> u_V = EntreeSecurisee::fraction();
	ZFraction a(a_V[0], a_V[1]);
	ZFraction b(b_V[0], b_V[1]);
	ZFraction u(u_V[0], u_V[1]);

	cout << endl << "x = " << (u - b) / a ;
}

void Systeme::degre2()
{
	cout << "Bienvenue dans le programme de résolution d'équation du type :\n{ ax + by = u ;\n{ ax + by = u ;" << endl << endl;

	cout << "Premiere équation : " << endl;
	cout << "Rentrez a : ";
	vector<int> a1_V = EntreeSecurisee::fraction();
	cout << "Rentrez b : ";
	vector<int> b1_V = EntreeSecurisee::fraction();
	cout << "Rentrez u : ";
	vector<int> u1_V = EntreeSecurisee::fraction();
	ZFraction a1(a1_V[0], a1_V[1]);
	ZFraction b1(b1_V[0], b1_V[1]);
	ZFraction u1(u1_V[0], u1_V[1]);


	cout << endl << "Deuxieme équation : " << endl;
	cout << "Rentrez a : ";
	vector<int> a2_V = EntreeSecurisee::fraction();
	cout << "Rentrez b : ";
	vector<int> b2_V = EntreeSecurisee::fraction();
	cout << "Rentrez u : ";
	vector<int> u2_V = EntreeSecurisee::fraction();
	ZFraction a2(a2_V[0], a2_V[1]);
	ZFraction b2(b2_V[0], b2_V[1]);
	ZFraction u2(u2_V[0], u2_V[1]);

	ZFraction det{ a1 * b2 - b1 * a2 };

	if (det == 0)
	{
		cout << "Il y a une infinité ou aucune solution au système." << endl;
	}
	else {
		cout << endl << "x = " << u1* (b2 / det) - u2 * (b1 / det);
		cout << endl << "y = " << -u1 * (a2 / det) + u2 * (a1 / det) << endl;
	}
}

void Systeme::degre3()
{
	cout << "(Bienvenue dans le programme de résolution d'équation du type :\n{ ax + by + cz = u ;\n{ ax + by + cz = u ;\n{ ax + by + cz = u ;" << endl << endl;


	cout << "Premiere équation : " << endl;
	cout << "Rentrez a : ";
	vector<int> a1_V = EntreeSecurisee::fraction();
	cout << "Rentrez b : ";
	vector<int> b1_V = EntreeSecurisee::fraction();
	cout << "Rentrez c : ";
	vector<int> c1_V = EntreeSecurisee::fraction();
	cout << "Rentrez u : ";
	vector<int> u1_V = EntreeSecurisee::fraction();
	ZFraction a1(a1_V[0], a1_V[1]);
	ZFraction b1(b1_V[0], b1_V[1]);
	ZFraction c1(c1_V[0], c1_V[1]);
	ZFraction u1(u1_V[0], u1_V[1]);

	cout << endl << "Deuxieme équation : " << endl;
	cout << "Rentrez a : ";
	vector<int> a2_V = EntreeSecurisee::fraction();
	cout << "Rentrez b : ";
	vector<int> b2_V = EntreeSecurisee::fraction();
	cout << "Rentrez c : ";
	vector<int> c2_V = EntreeSecurisee::fraction();
	cout << "Rentrez u : ";
	vector<int> u2_V = EntreeSecurisee::fraction();
	ZFraction a2(a2_V[0], a2_V[1]);
	ZFraction b2(b2_V[0], b2_V[1]);
	ZFraction c2(c2_V[0], c2_V[1]);
	ZFraction u2(u2_V[0], u2_V[1]);

	cout << endl << "Troisime équation : " << endl;
	cout << "Rentrez a : ";
	vector<int> a3_V = EntreeSecurisee::fraction();
	cout << "Rentrez b : ";
	vector<int> b3_V = EntreeSecurisee::fraction();
	cout << "Rentrez c : ";
	vector<int> c3_V = EntreeSecurisee::fraction();
	cout << "Rentrez u : ";
	vector<int> u3_V = EntreeSecurisee::fraction();
	ZFraction a3(a3_V[0], a3_V[1]);
	ZFraction b3(b3_V[0], b3_V[1]);
	ZFraction c3(c3_V[0], c3_V[1]);
	ZFraction u3(u3_V[0], u3_V[1]);

	ZFraction det = a1 * b2 * c3 + b1 * c2 * a3 + c1 * a2 * b3 - a3 * b2 * c1 - b3 * c2 * a1 - c3 * a2 * b1;

	if (det == 0)
	{
		cout << "Il y a une infinité ou aucune solution au système." << endl;
	}
	else {
		ZFraction det11{ b2 * c3 - c2 * b3 };
		ZFraction det12{ - b1 * c3 + b3 * c1 };
		ZFraction det13{ b1 * c2 - c1 * b2 };
		
		ZFraction det21{  - a2 * c3 + c2 * a3 };
		ZFraction det22{ a1 * c3 - c1 * a3 };
		ZFraction det23{ - a1 * c2 + c1 * a2 };
		
		ZFraction det31{ a2 * b3 - b2 * a3 };
		ZFraction det32{ - a1 * b3 + b1 * a3 };
		ZFraction det33{ a1 * b2 - b1 * a2 };

		cout << endl << "x = " << (u1 * det11 + u2 * det12 + u3 * det13) / det;
		cout << endl << "y = " << (u1 * det21 + u2 * det22 + u3 * det23) / det;
		cout << endl << "z = " << (u1 * det31 + u2 * det32 + u3 * det33) / det;
	}


}