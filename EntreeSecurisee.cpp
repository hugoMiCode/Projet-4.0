#include "EntreeSecurisee.h"

bool EntreeSecurisee::trueFalse()
{
    string rejouer{ "" };
    bool commande_able{ false };
    int compteurEspace{ 0 };
    int compteurTrueFalse{ 0 };

    do
    {
        cin.clear();
        getline(cin, rejouer);

        auto debut = begin(rejouer);
        auto fin = end(rejouer);
        auto totale_espace = count(debut, fin, ' ');

        if (totale_espace != 0)
        {
            commande_able = false;
            compteurEspace++;
            if (compteurEspace == 1)
            {
                cout << "Ne rentrez pas d'espace, recommencez : ";
            }
            else {
                cout << "Recommencez : ";
            }
            continue;
        }
        if (rejouer != "true" && rejouer != "false") {
            compteurTrueFalse++;
            if (compteurTrueFalse == 2)
            {
                std::cout << "C'est pas possible tu fais exprès ou quoi ? Entre une valeur cohérente : ";
            }
            else if (compteurTrueFalse == 3)
            {
                std::cout << "Ok, tu fais exprès ! Soit 'true', soit 'false' : ";
            }
            else if (compteurTrueFalse == 4)
            {   
                cout << "TU L'AURAS VOULU !!!" << endl;
                system("pause");
                exit(EXIT_FAILURE);
            }
            else {
                std::cout << "Rentrez 'true' ou 'false' : ";
            }
            commande_able = false;
            continue;
        }
        else {
            commande_able = true;
        }

    } while (!commande_able);

    if (rejouer == "false")
    {
        commande_able = false;
    }
	return commande_able;
}

int EntreeSecurisee::integer(bool negatif)
{
    int compteurEspace{ 0 };
    int compteurDigit{ 0 };
    int compteurSize{ 0 };
    int compteurNegatif{ 0 };
    string copie_entier{ "" };
    bool commande_able{ false };
    bool estNegatif{ false };

    do
    {
        cin.clear();
        getline(cin, copie_entier);


        auto debut = begin(copie_entier);
        auto fin = end(copie_entier);
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
            continue;
        }
        if (negatif)
        {
            if (copie_entier[0] == '-' && all_of(debut + 1, fin, isdigit))
            {
                estNegatif = true;
                copie_entier = { debut + 1, fin };
                debut = begin(copie_entier);
                fin = end(copie_entier);
            }
        }
        else if (copie_entier[0] == '-' && all_of(debut + 1, fin, isdigit))
        {
            compteurNegatif++;
            if (compteurNegatif == 1)
            {
                cout << "Seuls les nombres positifs sont acceptés, recommencez : ";
            }
            else {
                cout << "Recommencez : ";
            }
            continue;
        }
        if (!(all_of(debut, fin, isdigit))) {

            compteurDigit++;
            if (compteurDigit == 1)
            {
                cout << "Seuls les nombres sont acceptés, recommencez : ";
            }
            else {
                cout << "Recommencez : ";
            }
            continue;
        }
        if(copie_entier.size() >= 10) {

            compteurSize++;
            if (compteurEspace == 1)
            {
                cout << "Seuls les nombres strictements inférieurs à 1 milliard sont acceptés, recommencez : ";
            }
            else {
                cout << "Recommencez : ";
            }
            continue;
        }
        else {
            commande_able = true;
        }
    } while (!commande_able);

    if (estNegatif)
    {
        return -stoi(copie_entier);
    }
    else {
        return stoi(copie_entier);

    }
}
string EntreeSecurisee::validation2()
{
    string message{ "" };
    bool messageAble{ true };
    bool caractereAble{ false };
    int compteur{ 0 };
    array<char, 70> const caractere_autorisee{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0',
        '(',')','-','+','/','.','\'',' ' };

    do
    {
        cin.clear();
        messageAble = true;

        getline(cin, message);

        for (auto const lettre : message)
        {
            for (auto const caractere : caractere_autorisee)
            {
                if (caractere == lettre)
                {
                    caractereAble = true;
                    messageAble = true;
                    break;
                }
            }

            if (!caractereAble) {
                messageAble = false;
                compteur++;
                if (compteur == 1)
                {
                    cout << "Un caractère non autorisé a été rentré, recommencez : ";
                    cin.clear();
                    break;
                }
                else if (compteur > 1) {
                    cout << "Recommencez : ";
                    cin.clear();
                    break;
                }
            }
        }

    } while (!messageAble);

    return message;
}

vector<int> EntreeSecurisee::association(string const message)
{
    vector<int> message_chiffre{};

    for (auto const lettre : message)
    {
        switch (lettre)
        {
        case 'a':
            message_chiffre.push_back(1);
            break;

        case 'b':
            message_chiffre.push_back(2);
            break;

        case 'c':
            message_chiffre.push_back(3);
            break;

        case 'd':
            message_chiffre.push_back(4);
            break;

        case 'e':
            message_chiffre.push_back(5);
            break;

        case 'f':
            message_chiffre.push_back(6);
            break;

        case 'g':
            message_chiffre.push_back(7);
            break;

        case 'h':
            message_chiffre.push_back(8);
            break;

        case 'i':
            message_chiffre.push_back(9);
            break;

        case 'j':
            message_chiffre.push_back(10);
            break;

        case 'k':
            message_chiffre.push_back(11);
            break;

        case 'l':
            message_chiffre.push_back(12);
            break;

        case 'm':
            message_chiffre.push_back(13);
            break;

        case 'n':
            message_chiffre.push_back(14);
            break;

        case 'o':
            message_chiffre.push_back(15);
            break;

        case 'p':
            message_chiffre.push_back(16);
            break;

        case 'q':
            message_chiffre.push_back(17);
            break;

        case 'r':
            message_chiffre.push_back(18);
            break;

        case 's':
            message_chiffre.push_back(19);
            break;

        case 't':
            message_chiffre.push_back(20);
            break;

        case 'u':
            message_chiffre.push_back(21);
            break;

        case 'v':
            message_chiffre.push_back(22);
            break;

        case 'w':
            message_chiffre.push_back(23);
            break;

        case 'x':
            message_chiffre.push_back(24);
            break;

        case 'y':
            message_chiffre.push_back(25);
            break;

        case 'z':
            message_chiffre.push_back(26);
            break;

        case 'A':
            message_chiffre.push_back(27);
            break;

        case 'B':
            message_chiffre.push_back(28);
            break;

        case 'C':
            message_chiffre.push_back(29);
            break;

        case 'D':
            message_chiffre.push_back(30);
            break;

        case 'E':
            message_chiffre.push_back(31);
            break;

        case 'F':
            message_chiffre.push_back(32);
            break;

        case 'G':
            message_chiffre.push_back(33);
            break;

        case 'H':
            message_chiffre.push_back(34);
            break;

        case 'I':
            message_chiffre.push_back(35);
            break;

        case 'J':
            message_chiffre.push_back(36);
            break;

        case 'K':
            message_chiffre.push_back(37);
            break;

        case 'L':
            message_chiffre.push_back(38);
            break;

        case 'M':
            message_chiffre.push_back(39);
            break;

        case 'N':
            message_chiffre.push_back(40);
            break;

        case 'O':
            message_chiffre.push_back(41);
            break;

        case 'P':
            message_chiffre.push_back(42);
            break;

        case 'Q':
            message_chiffre.push_back(43);
            break;

        case 'R':
            message_chiffre.push_back(44);
            break;

        case 'S':
            message_chiffre.push_back(45);
            break;

        case 'T':
            message_chiffre.push_back(46);
            break;

        case 'U':
            message_chiffre.push_back(47);
            break;

        case 'V':
            message_chiffre.push_back(48);
            break;

        case 'W':
            message_chiffre.push_back(49);
            break;

        case 'X':
            message_chiffre.push_back(50);
            break;

        case 'Y':
            message_chiffre.push_back(51);
            break;

        case 'Z':
            message_chiffre.push_back(52);
            break;

        case '1':
            message_chiffre.push_back(53);
            break;

        case '2':
            message_chiffre.push_back(54);
            break;

        case '3':
            message_chiffre.push_back(55);
            break;

        case '4':
            message_chiffre.push_back(56);
            break;

        case '5':
            message_chiffre.push_back(57);
            break;

        case '6':
            message_chiffre.push_back(58);
            break;

        case '7':
            message_chiffre.push_back(59);
            break;

        case '8':
            message_chiffre.push_back(60);
            break;

        case '9':
            message_chiffre.push_back(61);
            break;

        case '0':
            message_chiffre.push_back(62);
            break;

        case ' ':
            message_chiffre.push_back(63);
            break;

        case '/':
            message_chiffre.push_back(64);
            break;

        case '.':
            message_chiffre.push_back(65);
            break;

        case '-':
            message_chiffre.push_back(66);
            break;

        case '+':
            message_chiffre.push_back(67);
            break;

        case '(':
            message_chiffre.push_back(68);
            break;

        case '\'':
            message_chiffre.push_back(69);
            break;

        case ')':
            message_chiffre.push_back(0);
            break;

        }
    }

    return message_chiffre;
}

vector<char> EntreeSecurisee::finalisation(vector<int> const message)
{
    vector<char> message_chiffre{};
    for (auto const x : message)
    {
        switch (x) {
        case 1:
            message_chiffre.push_back('a');
            break;

        case 2:
            message_chiffre.push_back('b');
            break;

        case 3:
            message_chiffre.push_back('c');
            break;

        case 4:
            message_chiffre.push_back('d');
            break;

        case 5:
            message_chiffre.push_back('e');
            break;

        case 6:
            message_chiffre.push_back('f');
            break;

        case 7:
            message_chiffre.push_back('g');
            break;

        case 8:
            message_chiffre.push_back('h');
            break;

        case 9:
            message_chiffre.push_back('i');
            break;

        case 10:
            message_chiffre.push_back('j');
            break;

        case 11:
            message_chiffre.push_back('k');
            break;

        case 12:
            message_chiffre.push_back('l');
            break;

        case 13:
            message_chiffre.push_back('m');
            break;

        case 14:
            message_chiffre.push_back('n');
            break;

        case 15:
            message_chiffre.push_back('o');
            break;

        case 16:
            message_chiffre.push_back('p');
            break;

        case 17:
            message_chiffre.push_back('q');
            break;

        case 18:
            message_chiffre.push_back('r');
            break;

        case 19:
            message_chiffre.push_back('s');
            break;

        case 20:
            message_chiffre.push_back('t');
            break;

        case 21:
            message_chiffre.push_back('u');
            break;

        case 22:
            message_chiffre.push_back('v');
            break;

        case 23:
            message_chiffre.push_back('w');
            break;

        case 24:
            message_chiffre.push_back('x');
            break;

        case 25:
            message_chiffre.push_back('y');
            break;

        case 26:
            message_chiffre.push_back('z');
            break;

        case 27:
            message_chiffre.push_back('A');
            break;

        case 28:
            message_chiffre.push_back('B');
            break;

        case 29:
            message_chiffre.push_back('C');
            break;

        case 30:
            message_chiffre.push_back('D');
            break;

        case 31:
            message_chiffre.push_back('E');
            break;

        case 32:
            message_chiffre.push_back('F');
            break;

        case 33:
            message_chiffre.push_back('G');
            break;

        case 34:
            message_chiffre.push_back('H');
            break;

        case 35:
            message_chiffre.push_back('I');
            break;

        case 36:
            message_chiffre.push_back('J');
            break;

        case 37:
            message_chiffre.push_back('K');
            break;

        case 38:
            message_chiffre.push_back('L');
            break;

        case 39:
            message_chiffre.push_back('M');
            break;

        case 40:
            message_chiffre.push_back('N');
            break;

        case 41:
            message_chiffre.push_back('O');
            break;

        case 42:
            message_chiffre.push_back('P');
            break;

        case 43:
            message_chiffre.push_back('Q');
            break;

        case 44:
            message_chiffre.push_back('R');
            break;

        case 45:
            message_chiffre.push_back('S');
            break;

        case 46:
            message_chiffre.push_back('T');
            break;

        case 47:
            message_chiffre.push_back('U');
            break;

        case 48:
            message_chiffre.push_back('V');
            break;

        case 49:
            message_chiffre.push_back('W');
            break;

        case 50:
            message_chiffre.push_back('X');
            break;

        case 51:
            message_chiffre.push_back('Y');
            break;

        case 52:
            message_chiffre.push_back('Z');
            break;

        case 53:
            message_chiffre.push_back('1');
            break;

        case 54:
            message_chiffre.push_back('2');
            break;

        case 55:
            message_chiffre.push_back('3');
            break;

        case 56:
            message_chiffre.push_back('4');
            break;

        case 57:
            message_chiffre.push_back('5');
            break;

        case 58:
            message_chiffre.push_back('6');
            break;

        case 59:
            message_chiffre.push_back('7');
            break;

        case 60:
            message_chiffre.push_back('8');
            break;

        case 61:
            message_chiffre.push_back('9');
            break;

        case 62:
            message_chiffre.push_back('0');
            break;

        case 63:
            message_chiffre.push_back(' ');
            break;

        case 64:
            message_chiffre.push_back('/');
            break;

        case 65:
            message_chiffre.push_back('.');
            break;

        case 66:
            message_chiffre.push_back('-');
            break;

        case 67:
            message_chiffre.push_back('+');
            break;

        case 68:
            message_chiffre.push_back('(');
            break;

        case 69:
            message_chiffre.push_back('\'');
            break;

        case 0:
            message_chiffre.push_back(')');
            break;


        }
    }

    return message_chiffre;
}