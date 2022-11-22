#include "Diophantienne.h"


Diophantienne::Diophantienne()
{
    std::cout << R"(Bienvenue dans le programme de résolution d'équation diophantienne du type : "au + bv = d",)" << endl << R"(avec d = PGCD(a;b) et a,b,u,v des entiers relatifs !)" << endl;
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


        int Pgcd{ EntreeSecurisee::pgcd(a, b) };

        if (Pgcd != d) {
            std::cout << endl << "PGCD(" << a << ";" << b << ") = " << Pgcd << ", l'équation (E) : ";
            equation(a, b); 
            std::cout << " = " << d << " n'est pas résolvable !" << endl << endl;
        }
        else {
            if (Pgcd != 1)
            {
                std::cout << "L'équation (E) : "; equation(a, b); std::cout << " = " << d << " <=> ";
                a /= d;
                b /= d;
                equation(a, b); std::cout << " = 1." << endl;
            }
            std::cout << endl << "PGCD(" << a << ";" << b << ") = " << Pgcd << ". Ainsi " << a << " et " << b << " sont premiers entre eux."
                      << " Par le théorème de Bezout,\nil existe au moins un couple d'entiers (u;v) tels que (E) : ";

            equation(a, b); std::cout << " = 1.\n";
            double temps{ 0 };
            vector<int> solution{ fsolution_while(a,b, temps) };
            affichage1(a, b, solution);
         


            if (solution[3] == 0)
                std::cout << "Après " << solution[2] << " tests en " << temps << " millisecondes,";
            else
                std::cout << "Après " << solution[3] << "." << solution[2] << " milliards de tests en " << temps << " ms, au rythme de "
                     << ((int64_t)solution[3] * 1000000000) / (int64_t)temps + (int64_t)solution[2] / (int64_t)temps << " tests par milliseconde,";
            std::cout << "\nle couple (" << solution[0] << ';' << solution[1] << ") a été trouvé comme solution particulière de (E). " << endl;

            if (solution[2] < 20)
                std::cout << "Pas besoin d'un ordinateur pour résoudre cette équation !" << endl;

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
                        break;
                }
                std::cout << "L'équation a bien été enregistré dans l'historique." << endl;
            }
            else {
                std::cout << "Le fichier \"Historique diophantienne.tkt\" n'éxiste pas," << endl
                    << "création du fichier contenant l'historique des équations diophantiennes." << endl << endl;

                ofstream fichier_historique_clear{ "Historique diophantienne.tkt" };
                fichier_historique_clear << equation_act;
            }
        }

        std::cout << "Voulez vous rentrer une autre équation ? (true/false) : ";

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
            break;
    }

    if (compteur != 1 && compteur != 0)
        std::cout << "Voici l'historique des " << compteur << " dernières équations resolues par cet algorithme : \n" << endl;
    else if (compteur == 1) 
        std::cout << "Voici l'historique de la derniere équation résolue par cet algorithme : \n" << endl;
    else
        std::cout << "L'historique est vide.\n" << endl;

    for (unsigned int i{ 0 }; i < lignes.size() && i < 10; i++)
        std::cout << i + 1 << ": " << lignes[i] << endl;
    
    std::cout << endl;
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
    if (b < 0) {
        equation += " - ";
        equation += b_N;
    }
    else {
        equation += " + ";
        equation += b_P;
    }
    equation += "v = 1,     (";
    equation += sol_0_P;
    if (b < 0) {
        equation += " - ";
        equation += b_N;
    }
    else {
        equation += " + ";
        equation += b_P;
    }
    equation += "k ; ";
    equation += sol_1_P;
    if (a < 0) {
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

string Diophantienne::equation(int a, int b)
{
    if (b < 0) 
        std::cout << a << 'u' << " - " << -b << 'v';
    else
        std::cout << a << 'u' << " + " << b << 'v';

    string ret{ "" };
    return ret;
}

vector<int> Diophantienne::fsolution_while(int& a, int& b, double& temps)
{

    vector<int> board{};
    int memoire{ -2 }; int resultat{ 0 }; int compteur{ 0 }; int coef{ 0 }; int u{ 0 };

    const clock_t begin_time = clock();
    
    std::cout << "Calcul en cours." << endl;

    while (resultat != 1)
    {
        u += 2;
        memoire += 2;
        for (int i{ -u }; i <= u; i++) {
            if (resultat == 1)
                break;
            for (int j{ -u }; j <= u; j++) {
                if (j == -memoire && i >= -memoire && i <= memoire)
                    j += 2 * memoire + 1;

                resultat = a * i + b * j;
                compteur++;
                if (a < 100 && b < 100)
                    std::cout << " u = " << i << "       v = " << j << endl;
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
    std::cout << endl << a << " x ";
    if (solution[0] < 0)
        std::cout << "(" << solution[0] << ')';
    else
        std::cout << solution[0];
    if (b < 0)
        std::cout << " - " << -b << " x ";
    else
        std::cout << " + " << b << " x ";
    if (solution[1] < 0)
        std::cout << '(' << solution[1] << ") = ";
    else
        std::cout << solution[1] << " = ";
    std::cout << a * solution[0];
    if (b * solution[1] < 0)
        std::cout << " - " << -b * solution[1] << " = ";
    else
        std::cout << " + " << b * solution[1] << " = ";
    std::cout << a * solution[0] + b * solution[1] << '.' << endl;
}

void Diophantienne::fResolution2(int a, int b, vector<int> solution)
{
    std::cout << endl;
    equation(a, b);
    std::cout << " = 1\n<=> ";
    equation(a, b);
    std::cout << " = " << a << " x ";
    if (solution[0] < 0)
        std::cout << '(' << solution[0] << ')';
    else
        std::cout << solution[0];
    if (b < 0)
        std::cout << " - " << -b << " x ";
    else
        std::cout << " + " << b << " x ";
    if (solution[1] < 0)
        std::cout << '(' << solution[1] << ")\n";
    else
        std::cout << solution[1] << endl;
    std::cout << "<=> " << a << "(u";

    if (solution[0] < 0)
        std::cout << " + " << -solution[0];
    else
        std::cout << " - " << solution[0];

    std::cout << ") = " << b << "(" << solution[1] << " - v)" << endl
         << " => " << a << " | " << b << '(' << solution[1] << " - v)" << endl
         << "Par le théorème de Gauss, comme " << a << " et " << b << " sont premiers entre eux, alors "
         << a << " divise " << solution[1] << " - v." << endl 
         << "Il existe donc un entier relatif k tel que " << a << "k = " << solution[1] << " - v. Soit v  = " << solution[1];

    if (a < 0)
        std::cout << " + " << -a << "k. ";
    else
        std::cout << " - " << a << "k. ";

    std::cout << endl;
    std::cout << "\nL'égalité devient donc :\n    " << a << 'u';
    if (b < 0)
        std::cout << " - " << -b;
    else
        std::cout << " + " << b;
    std::cout << '(' << solution[1];
    if (a < 0)
        std::cout << " + " << -a;
    else
        std::cout << " - " << a;
    std::cout << "k) = 1\n<=> " << a << "u = 1";
    if (b < 0)
        std::cout << " + " << -b;
    else
        std::cout << " - " << b;
    std::cout << " x ";
    if (solution[1] < 0)
        std::cout << '(' << solution[1] << ')';
    else
        std::cout << solution[1];
    if (b < 0)
        std::cout << " - " << -b;
    else
        std::cout << " + " << b;
    std::cout << " x ";
    if (a < 0)
        std::cout << '(' << a << ')';
    else
        std::cout << a;
    std::cout << "k\n<=> " << a << "u = " << 1 - b * solution[1];
    if (b < 0)
        std::cout << " - " << -b;
    else
        std::cout << " + " << b;
    std::cout << " x ";
    if (a < 0)
        std::cout << '(' << a << ')';
    else
        std::cout << a;
    std::cout << "k\n<=> u = " << solution[0];
    if (b < 0)
        std::cout << " - " << -b;
    else
        std::cout << " + " << b;
    std::cout << "k  ";

    std::cout << "\n\nRéciproquement, s'il existe un entier relatif k tel que : u = " << solution[0];
    if (b < 0)
        std::cout << " - " << -b;
    else
        std::cout << " + " << b;
    std::cout << "k et v = " << solution[1];
    if (a < 0)
        std::cout << " + " << -a;
    else
        std::cout << " - " << a;
    std::cout << "k. Alors,\n" << a << 'u';
    if (b < 0)
        std::cout << " - " << -b;
    else
        std::cout << " + " << b;
    std::cout << "v = " << a << '(' << solution[0];
    if (b < 0)
        std::cout << " - " << -b;
    else
        std::cout << " + " << b;
    std::cout << "k)";
    if (b < 0)
        std::cout << " - " << -b;
    else
        std::cout << " + " << b;
    std::cout << '(' << solution[1];
    if (a > 0)
        std::cout << " - " << a;
    else
        std::cout << " + " << -a;
    std::cout << "k) = " << solution[0] * a;
    if (a < 0)
        std::cout << " - " << -a;
    else
        std::cout << " + " << a;
    std::cout << " x ";
    if (b < 0)
        std::cout << '(' << b << ")k";
    else
        std::cout << b << 'k';
    if (b * solution[1] < 0)
        std::cout << " - " << -b * solution[1];
    else
        std::cout << " + " << b * solution[1];
    if (a < 0)
        std::cout << " + " << -a;
    else
        std::cout << " - " << a;
    std::cout << " x ";
    if (b < 0)
        std::cout << '(' << b << ')';
    else
        cout << b;
    std::cout << "k = 1.\n";


    std::cout << "\nDonc (u;v) est un couple d'entiers relatifs solution de (E). En conclusion,\nl'ensemble des couples (u;v) solutions de l'équation (E), sont les couples de la forme :\n("
        << solution[0];
    if (b >= 0)
        std::cout << " + " << b << "k;" << solution[1];
    else
        std::cout << " - " << -b << "k;" << solution[1];
    if (a < 0)
        std::cout << " + " << -a;
    else
        std::cout << " - " << a;
    std::cout << "k), k appartenant à Z.\n\n";
}

Diophantienne::~Diophantienne()
{

}

