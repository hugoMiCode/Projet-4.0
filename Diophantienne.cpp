#include "Diophantienne.h"


Diophantienne::Diophantienne()
{
    cout << R"(Bienvenue dans le programme de r�solution d'�quation diophantienne du type : "au + bv = d",)" << endl << R"(avec d = PGCD(a;b) et a,b,u,v des entiers relatifs !)" << endl;
    int a, b, d{ 0 };
    string equation_act{ "" };

    string rejouer;
    do
    {
        std::cout << endl << "Rentrez a : ";
        a = EntreeSecurisee::integer(true);

        std::cout << "Rentrez b : ";
        b = EntreeSecurisee::integer(true);

        std::cout << "Rentrez d : ";
        d = EntreeSecurisee::integer(false);


        int Pgcd{ pgcd(a, b) };

        if (Pgcd != d)
        {
            cout << endl << "PGCD(" << a << ";" << b << ") = " << Pgcd << ", l'�quation (E) : ";
            equation(a, b); cout << " = " << d << " n'est pas r�solvable !" << endl << endl;            
        }
        else {
            if (Pgcd != 1)
            {
                cout << "L'�quation (E) : "; equation(a, b); cout << " = " << d << " <=> ";
                a /= d;
                b /= d;
                equation(a, b); cout << " = 1." << endl;
            }
            std::cout << endl << "PGCD(" << a << ";" << b << ") = " << Pgcd << ". Ainsi " << a << " et " << b << " sont premiers entre eux."
                      << " Par le th�or�me de Bezout,\nil existe au moins un couple d'entiers (u;v) tels que (E) : ";

            equation(a, b); cout << " = 1.\n";
            double temps{ 0 };
            vector<int> solution{ fsolution_while(a,b, temps) };
            affichage1(a, b, solution);
         


            if (solution[3] == 0)
            {
                cout << "Apr�s " << solution[2] << " tests en " << temps << " millisecondes,";
            }
            else {
                cout << "Apr�s " << solution[3] << "." << solution[2] << " milliards de tests en " << temps << " ms, au rythme de " 
                     << ((int64_t)solution[3] * 1000000000) / (int64_t)temps + (int64_t)solution[2] / (int64_t)temps << " tests par milliseconde,";
            }
            cout << "\nle couple (" << solution[0] << ';' << solution[1] << ") a �t� trouv� comme solution particuli�re de (E). " << endl;

            if (solution[2] < 20) {

                cout << "Pas besoin d'un ordinateur pour r�soudre cette �quation !" << endl;
            }

            fResolution2(a, b, solution);
            equation_act = equation_acctuel(a, b, solution);
            ifstream fichier_historique_lecture{ "Historique diophantienne.tkt" };

            if (fichier_historique_lecture)
            {
                vector<string> lignes{};
                string equation{ "" };
                int position{ 1 };

                while (getline(fichier_historique_lecture, equation))
                {
                    lignes.push_back(equation);
                    if (position == 9)
                    {
                        position = 0;
                        break;
                    }
                    position++;
                }

                reverse(begin(lignes), end(lignes));
                lignes.push_back(equation_act);
                reverse(begin(lignes), end(lignes));

                ofstream fichier_historique_clear{ "Historique diophantienne.tkt" };

                for (auto const ligne : lignes)
                {
                    fichier_historique_clear << ligne << endl;
                    if (position == 10)
                    {
                        break;
                    }
                }
                cout << "L'�quation a bien �t� enregistr� dans \"Historique diophantienne.tkt\"." << endl;
            }
            else {
                cout << "Le fichier \"Historique diophantienne.tkt\" n'�xiste pas," << endl
                    << "cr�ation du fichier contenant l'historique des �quations diophantiennes." << endl << endl;

                ofstream fichier_historique_clear{ "Historique diophantienne.tkt" };
                fichier_historique_clear << equation_act;
            }
        }

        cout << "Voulez vous rentrer une autre �quation ? (true/false) : ";

    } while (EntreeSecurisee::trueFalse());
}

Diophantienne::Diophantienne(int compteur) // Historique.
{
    ifstream fichier_historique{ "Historique diophantienne.tkt" };
    string ligne{ "" };
    vector<string> lignes{};

    while (getline(fichier_historique, ligne))
    {
        lignes.push_back(ligne);
        compteur++;
        if (compteur == 10)
        {
            break;
        }
    }
    if (compteur != 1 && compteur != 0)
    {
        cout << "Voici l'historique des " << compteur << " derni�res �quations resolues par cet algorithme : \n" << endl;
    }
    else if (compteur == 1){
        cout << "Voici l'historique de la derniere �quation r�solue par cet algorithme : \n" << endl;

    }
    else {
        cout << "L'historique est vide.\n" << endl;
    }

    for (unsigned int i{ 0 }; i < lignes.size() && i < 10; i++)
    {
        cout << i + 1 << ": " << lignes[i] << endl;
    }cout << endl;

}

string Diophantienne::equation_acctuel(int a, int b, vector<int> solution)
{
    string equation{ "" };
    string a_P = to_string(a);
    string a_N = to_string(-a);
    string b_P = to_string(b);
    string b_N = to_string(-b);
    string sol_0_P = to_string(solution[0]);
    string sol_1_P = to_string(solution[1]);

    equation += a_P;
    equation += "u";
    if (b < 0)
    {
        equation += " - ";
        equation += b_N;
    }
    else {
        equation += " + ";
        equation += b_P;
    }
    equation += "v = 1,     (";
    equation += sol_0_P;
    if (b < 0)
    {
        equation += " - ";
        equation += b_N;
    }
    else {
        equation += " + ";
        equation += b_P;
    }
    equation += "k ; ";
    equation += sol_1_P;
    if (a < 0)
    {
        equation += " + ";
        equation += a_N;
    }
    else {
        equation += " - ";
        equation += a_P;
    }
    equation += "k).";

    return equation;
}


int Diophantienne::pgcd(int a, int b)
{
    if (a < b)
    {
        int copie{ a };
        a = b;
        b = copie;
    }

    while (b != 0)
    {
        int t{ b };
        b = a % b;
        a = t;
    }
    if (a < 0) {
        a = -a;
    }
    return a;
}

string Diophantienne::equation(int a, int b)
{
    if (b < 0)
    {
        b *= -1;
        cout << a << 'u' << " - " << b << 'v';
    }
    else
    {
        cout << a << 'u' << " + " << b << 'v';
    }
    string ret{ "" };
    return ret;
}

vector<int> Diophantienne::fsolution_while(int& a, int& b, double& temps)
{

    vector<int> board{};
    int memoire{ -2 }; int resultat{ 0 }; int compteur{ 0 }; int coef{ 0 }; int u{ 0 };

    const clock_t begin_time = clock();
    
     cout << "Calcul en cours." << endl;

    while (resultat != 1)
    {
       
        u += 2;
        memoire += 2;
        for (int i{ -u }; i <= u; i++) {
            if (resultat == 1) {
                break;
            }
            for (int j{ -u }; j <= u; j++) {
                if (j == -memoire && i >= -memoire && i <= memoire) {
                    j += 2 * memoire + 1;
                }

                resultat = a * i + b * j;
                compteur++;
                if (a < 100 && b < 100)
                {
                    cout << " u = " << i << "        v = " << j << endl;
                }
                if (compteur == 1000000000) {
                    compteur = 0;
                    coef++;
                } if (resultat == 1) {
                    board.push_back(i);
                    board.push_back(j);
                    break;
                }
            }
        }
    }

    temps = double((double)clock() - (double)begin_time);

    board.push_back(compteur);
    board.push_back(coef);
    return board;
}

void Diophantienne::affichage1(int a, int b, vector<int> solution)
{
    cout << endl << a << " x ";
    if (solution[0] < 0)
    {
        cout << "(" << solution[0] << ')';
    }
    else {
        cout << solution[0];
    }
    if (b < 0)
    {
        cout << " - " << -b << " x ";
    }
    else {
        cout << " + " << b << " x ";
    }
    if (solution[1] < 0)
    {
        cout << '(' << solution[1] << ") = ";
    }
    else {
        cout << solution[1] << " = ";
    }
    cout << a * solution[0];
    if (b * solution[1] < 0)
    {
        cout << " - " << -b * solution[1] << " = ";
    }
    else {
        cout << " + " << b * solution[1] << " = ";
    }
    cout << a * solution[0] + b * solution[1] << '.' << endl;
}

void Diophantienne::fResolution2(int a, int b, vector<int> solution)
{
    cout << endl;
    equation(a, b);
    cout << " = 1\n<=> ";
    equation(a, b);
    cout << " = " << a << " x ";
    if (solution[0] < 0)
    {
        cout << '(' << solution[0] << ')';
    }
    else {
        cout << solution[0];
    }
    if (b < 0)
    {
        cout << " - " << -b << " x ";
    }
    else {
        cout << " + " << b << " x ";
    }
    if (solution[1] < 0)
    {
        cout << '(' << solution[1] << ")\n";
    }
    else {
        cout << solution[1] << endl;
    }
    cout << "<=> " << a << "(u";

    if (solution[0] < 0)
    {
        cout << " + " << -solution[0];
    }
    else {
        cout << " - " << solution[0];
    }
    cout << ") = " << b << "(" << solution[1] << " - v)" << endl
         << " => " << a << " | " << b << '(' << solution[1] << " - v)" << endl
         << "Par le th�or�me de Gauss, comme " << a << " et " << b << " sont premiers entre eux, alors "
         << a << " divise " << solution[1] << " - v." << endl 
         << "Il existe donc un entier relatif k tel que " << a << "k = " << solution[1] << " - v. Soit v  = " << solution[1];

    if (a < 0)
    {
        cout << " + " << -a << "k. ";
    }
    else {
        cout << " - " << a << "k. ";
    }

    cout << endl;
    cout << "\nL'�galit� devient donc :\n    " << a << 'u';
    if (b < 0)
    {
        cout << " - " << -b;
    }
    else {
        cout << " + " << b;
    }
    cout << '(' << solution[1];
    if (a < 0)
    {
        cout << " + " << -a;
    }
    else {
        cout << " - " << a;
    }
    cout << "k) = 1\n<=> " << a << "u = 1";
    if (b < 0)
    {
        cout << " + " << -b;
    }
    else {
        cout << " - " << b;
    }
    cout << " x ";
    if (solution[1] < 0)
    {
        cout << '(' << solution[1] << ')';
    }
    else {
        cout << solution[1];
    }
    if (b < 0)
    {
        cout << " - " << -b;
    }
    else {
        cout << " + " << b;
    }
    cout << " x ";
    if (a < 0)
    {
        cout << '(' << a << ')';
    }
    else {
        cout << a;
    }
    cout << "k\n<=> " << a << "u = " << 1 - b * solution[1];
    if (b < 0)
    {
        cout << " - " << -b;
    }
    else {
        cout << " + " << b;
    }
    cout << " x ";
    if (a < 0)
    {
        cout << '(' << a << ')';
    }
    else {
        cout << a;
    }
    cout << "k\n<=> u = " << solution[0];
    if (b < 0)
    {
        cout << " - " << -b;
    }
    else {
        cout << " + " << b;
    }
    cout << "k  ";

    cout << "\n\nR�ciproquement, s'il existe un entier relatif k tel que : u = " << solution[0];
    if (b < 0)
    {
        cout << " - " << -b;
    }
    else {
        cout << " + " << b;
    }
    cout << "k et v = " << solution[1];
    if (a < 0)
    {
        cout << " + " << -a;
    }
    else {
        cout << " - " << a;
    }
    cout << "k. Alors,\n" << a << 'u';
    if (b < 0)
    {
        cout << " - " << -b;
    }
    else {
        cout << " + " << b;
    }
    cout << "v = " << a << '(' << solution[0];
    if (b < 0)
    {
        cout << " - " << -b;
    }
    else {
        cout << " + " << b;
    }
    cout << "k)";
    if (b < 0)
    {
        cout << " - " << -b;
    }
    else {
        cout << " + " << b;
    }
    cout << '(' << solution[1];
    if (a > 0)
    {
        cout << " - " << a;
    }
    else {
        cout << " + " << -a;
    }
    cout << "k) = " << solution[0] * a;
    if (a < 0)
    {
        cout << " - " << -a;
    }
    else {
        cout << " + " << a;
    }
    cout << " x ";
    if (b < 0)
    {
        cout << '(' << b << ")k";
    }
    else {
        cout << b << 'k';
    }
    if (b * solution[1] < 0)
    {
        cout << " - " << -b * solution[1];
    }
    else {
        cout << " + " << b * solution[1];
    }
    if (a < 0)
    {
        cout << " + " << -a;
    }
    else {
        cout << " - " << a;
    }
    cout << " x ";
    if (b < 0)
    {
        cout << '(' << b << ')';
    }
    else {
        cout << b;
    }
    cout << "k = 1.\n";


    cout << "\nDonc (u;v) est un couple d'entiers relatifs solution de (E). En conclusion,\nl'ensemble des couples (u;v) solutions de l'�quation (E), sont les couples de la forme :\n("
        << solution[0];
    if (b >= 0)
    {
        cout << " + " << b << "k;" << solution[1];
    }
    else {
        cout << " - " << -b << "k;" << solution[1];
    }
    if (a < 0)
    {
        cout << " + " << -a;
    }
    else {
        cout << " - " << a;
    }
    cout << "k), k appartenant � Z.\n\n";
}

Diophantienne::~Diophantienne()
{

}

