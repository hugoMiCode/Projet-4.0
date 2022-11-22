#include "cryptage.h"

Cryptage::Cryptage() // Decryptage.
{    
    string message{ "" };
    string clef{ "" };


    cout << "Bienvenue dans le programme de décryptage !" << endl << "Message : ";
    message = EntreeSecurisee::validation2();

    cout << endl;

    cout << "Clef :";
    clef = EntreeSecurisee::validation2();

    string message_original = dechiffrement(message, clef);
    cout << endl << "Message décrypté : " << message_original << endl << endl;
}

Cryptage::Cryptage(int a) // Cryptage.
{
    cout << R"*(Bienvenue dans le programme de cryptage !, toutes les lettres sont valides en majuscule et minuscule ainsi)*" << endl << R"*(que les caractères suivants :  .  /  - ( + )  ')*" << endl;


    cout << "Message : ";
    string message = EntreeSecurisee::validation2();

    cout << endl;

    cout << "Clef de chiffrement : ";
    string clef = EntreeSecurisee::validation2();

    vector<string> donne_clef = chiffrement(message, clef);

    cout << endl << "Message codé : " << donne_clef[0] << endl << endl;
}




vector<string> Cryptage::chiffrement(string message, string clef)
{
    vector<string> donne{};

    vector<int> clef_chiffre{ EntreeSecurisee::association(clef) };
    vector<int> message_chiffre{ EntreeSecurisee::association(message) };
    vector<int> message_crypte_chiffre{ generation(clef_chiffre, message_chiffre) };
    vector<int> message_code{ transformation(message_crypte_chiffre, message_chiffre) };
    vector<char> message_finale{ EntreeSecurisee::finalisation(message_code) };
    string code{ "" };


    for (auto const x : message_finale)
    {
        code += x;
    }

    ofstream fichier{ "Donnee crypte.tkt" };
    if (fichier)
    {
        cout << "\nMessage crypté sauvegardé dans \"Donnee crypte.tkt\".";
        fichier << code;
    }
    else {
        cout << "\nLe message crypté n'a pas été sauvegardé, échec d'ouverture de \"Donnee crypte.tkt\".";
    }
    donne.push_back(code);
    donne.push_back(clef);

    return donne;
}

string Cryptage::dechiffrement(string message, string clef)
{

    vector<int> clef_chiffre{ EntreeSecurisee::association(clef) };                                                 // Transformation de la clef en suite de nombre.
    vector<int> message_code_chiffre{ EntreeSecurisee::association(message) };                                      // Transformation du message en suite de nombre.
    vector<int> clef_finale_chiffre{ generation(clef_chiffre, message_code_chiffre) };                              // Clef addapter a la bonne taille.
    vector<int> message_final_chiffre{ transformation_decryptage(clef_finale_chiffre, message_code_chiffre) };      // Addition de la clef et du message en nombre.
    vector<char> message_finale{ EntreeSecurisee::finalisation(message_final_chiffre) };                            // Transformation des nombre du message e lettre.

    string message_original{ "" };

    for (auto const x : message_finale)
    {
        message_original += x;
    }

    return message_original;
}


vector<int> Cryptage::generation(vector<int>& clef, vector<int> const& message)
{
    vector<int> message_crypte_chiffre{};
    unsigned int j{ 0 };

    while (message.size() < clef.size())
    {
        clef.pop_back();
    }
    if (message.size() >= clef.size())
    {
        for (unsigned int i{ 0 }; i < message.size(); i++)
        {
            message_crypte_chiffre.push_back(clef[j % clef.size()]);
            j++;
        }
    }

    return message_crypte_chiffre;
}

vector<int> Cryptage::transformation(vector<int> const& clef, vector<int> const& message)
{
    vector<int> message_chiffre{};

    for (unsigned int i{ 0 }; i < message.size(); i++)
    {
        message_chiffre.push_back((clef[i] + message[i]) % 70);
    }

    return message_chiffre;
}

vector<int> Cryptage::transformation_decryptage(vector<int> const& clef, vector<int> const& message)
{
    vector<int> message_chiffre{};
     
    for (unsigned int i{ 0 }; i < message.size(); i++)
    {
        if (message[i] - clef[i] <= 0)
        {
            int j{ (message[i] - clef[i]) + 70 };
            message_chiffre.push_back(j);
        }
        else {
            message_chiffre.push_back(message[i] - clef[i]);
        }
    }
    return message_chiffre;
}


