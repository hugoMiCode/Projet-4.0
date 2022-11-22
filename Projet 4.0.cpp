#include "Diophantienne.h"
#include "Gauss.h"
#include "Cryptage.h"
#include "Key.h"
#include "NombrePremier.h"
#include "EntreeSecurisee.h"
#include <Windows.h>
#include <stdlib.h>
#define NOMINMAX
#define _USE_MATH_DEFINES
#ifdef _WIN32
#define WINPAUSE system("pause")
#endif
using namespace std;

string fCommande(vector<string> board);


int main()
{
    SetConsoleOutputCP(1252);
    vector<string> liste_cmd{ "Gauss", "gauss", "Diophantienne", "diophantienne", "Historique", "historique", "Cryptage",
                              "cryptage", "Decryptage", "decryptage", "Key", "key", "Premier", "premier" };

    do
    {
        string commande = fCommande(liste_cmd);

        if (commande == "diophantienne" || commande == "Diophantienne") {
            Diophantienne diophantienne;

        }
        else if (commande == "historique" || commande == "Historique") {
            Diophantienne historique (0);

        }
        else if (commande == "gauss" || commande == "Gauss") {
            Gauss gauss;

        }
        else if (commande == "cryptage" || commande == "Cryptage") {
            Cryptage cryptage(0);

        }
        else if (commande == "decryptage" || commande == "Decryptage") {
            Cryptage();

        }else if (commande == "Key" || commande == "key") {
            Key clef;

        }else if (commande == "premier" || commande == "Premier") { 
            NombrePremier premier;
		}
        
    cout << "Voulez vous revenir au menu commande ? (true/false) : ";

    } while (EntreeSecurisee::trueFalse());

    cout << endl << "Projet crée en avril/mai 2020 par Hugo™ et Maxime™." << endl 
        << "Programmé en C++ sur Microsoft Visual Studio®." << endl << endl;
    getchar();
    return 0;
}

string fCommande(vector<string> board)
{
    bool commande_able{ false };
    int compteurEspace{ 0 };
    int compteurInvalide{ 0 };
    string cmd{ "" };

    cout << "Tapez \"liste\" pour acceder à la liste des commandes disponibles." << endl
         << "Commande : ";
    do 
    {
        getline(cin, cmd);

        auto debut = begin(cmd);
        auto fin = end(cmd);
        auto totale_espace = count(debut, fin, ' ');

        if (totale_espace != 0)
        {
            compteurEspace++;
            if (compteurEspace == 1)
            {
                cout << "Ne rentrez pas d'espace, recommencez : ";
            }
            else {
                cout << "Recommencez : ";
            }
            commande_able = false;
            continue;
        }

        if (cmd == "liste") {
            cout << "\nliste des commandes possibles : \n";

            for (unsigned int i{ 0 }; i < board.size(); i += 2)
            {
                cout << "- " << board[i] << endl;
            }
            commande_able = false;
            cout << endl << "Commande : ";
            continue;
        }

        for (auto const commande1 : board)
        {
            if (cmd == commande1) {
                commande_able = true;
            }
        }

        if (!commande_able && cmd != "liste")
        {
            compteurInvalide++;
            if (compteurInvalide == 1)
            {
                cout << "Commande introuvable, recommencez : ";
            }
            else {
                cout << "Recommencez : ";
            }
        }
    } while (!commande_able);
    cout << endl;

    return cmd;
}
