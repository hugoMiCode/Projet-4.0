#include "Gauss.h"

Gauss::Gauss()
{
    cout << "Theoreme de Gauss :\nSoient a, b, et c trois entiers tels que a et b soient premiers entre eux." << endl 
         << "Si a divise bc alors a divise c." << endl << endl
         << "Voulez-vous plus d'informations sur Carl Friedrich Gauss ? (true/false) : ";

    if (EntreeSecurisee::trueFalse()) {
        more();
    }
}

void Gauss::more()
{
    cout << "Carl Friedrich Gauss est un math�maticien, astronome et physicien allemand." << endl
         << "Il a apport� de tr�s importantes contributions � ces trois domaines" << endl
         << "Il est consider� comme l'un des plus grands mathematiciens de tous les temps." << endl
         << "Il a travaill� sur toutes les branches des math�matiques puis sur l'�lectricit� en physique" << endl << endl;
}

Gauss::~Gauss()
{

}
