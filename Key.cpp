#include "Key.h"
Key::Key()
{

    string rejouer{ "" };
    cout << "Bienvenue dans le programme de décryptage de la clef !\n";
    string message_decrypte{ "" };
    string message_crypte{ "" };
    do {
        rejouer = "false";

        cout << endl << "Message crypté : ";
        message_crypte = EntreeSecurisee::validation2();

        cout << endl << "Message décrypté : ";
        message_decrypte = EntreeSecurisee::validation2();


        if (message_decrypte.size() != message_crypte.size())
        {
            cout << "Les deux messages n'ont pas la même taille, impossible de trouver la clef de chiffrage.\n" << endl
                 << "Voulez vous rentrer d'autres messages ? (true/false) : ";
        }
        else {
            string clef_cryptage = cassage(message_decrypte, message_crypte);

            cout << endl << endl << "Clef de cryptage : " << clef_cryptage << endl << endl;
        }
        cout << "Voulez vous rentrer d'autres messages ? (true/false) : ";

    } while (EntreeSecurisee::trueFalse());
}

string Key::cassage(string message_decrypte, string message_crypte)
{

    vector<int> message_crypte_chiffre{ EntreeSecurisee::association(message_crypte) };
    vector<int> message_decrypte_chiffre{ EntreeSecurisee:: association(message_decrypte) };
    vector<int> clef_chiffre{ subtitution(message_decrypte_chiffre, message_crypte_chiffre) };
    vector<char> clef_de_decryptage{ EntreeSecurisee::finalisation(clef_chiffre) };

    string clef{ "" };
    bool valide{ true };
    unsigned int j{ 0 };
    clef += clef_de_decryptage[0];
 

    for (unsigned int i{ 1 }; i < clef_de_decryptage.size(); i++)
    {
        valide = true;
        if (clef_de_decryptage[i] == clef_de_decryptage[0])
        {
            for (unsigned int k{ 0 }; k < clef_de_decryptage.size() - clef.size(); k++)
            {
                if ((k % clef.size()) == 0)
                {
                    j = 0;
                }
                if (clef_de_decryptage[k + clef.size()] != clef[j])
                {
                    valide = false;
                    break;
                }
                j++;
            }
            if (valide)
            {
                return clef;
            }
            else {
                clef += clef_de_decryptage[0];
            }
        }
        else {
            clef += clef_de_decryptage[i];
        }
    }


    return clef;
}


vector<int> Key::subtitution(vector<int> message_decrypte, vector<int> message_crypte)
{
    vector<int> clef_chiffre;

    for (unsigned int i{ 0 }; i < message_crypte.size(); i++)
    {
        if ((message_crypte[i] - message_decrypte[i]) < 0)
        {
            clef_chiffre.push_back(message_crypte[i] - message_decrypte[i] + 70);
        }
        else {
            clef_chiffre.push_back(message_crypte[i] - message_decrypte[i]);
        }
    }

    return clef_chiffre;
}


Key::~Key()
{

}