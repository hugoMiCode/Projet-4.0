#include "NombrePremier.h"
using namespace std;

NombrePremier::NombrePremier()
{
	std:: cout << "Bienvenue dans le programme des nombres premiers." << endl;
	
 	string rejouer{ "false" };
	
	do
	{
		std::cout << endl << "Rentrez n : ";
		unsigned int n = EntreeSecurisee::integer(false);
		std::cin >> n;

		std::cout << n << std::endl;

		if (n <= 1)
			std::cout << "Sérieusement ?" << endl << endl;
		else {
			if (test_primalite(n))
				std::cout << n << " est premier." << endl;
			else {
				std::cout << n << " n'est pas premier, sa décomposition en facteurs premiers est : ";
				unordered_map<int, int> diviseurs{ decomposition(n) };

				bool plus{ false };
				for (auto const& paire : diviseurs)
				{
					if (plus)
						cout << " x ";
					plus = true;
					cout << paire.first << "^" << paire.second;
				}
				cout << '.' << endl;
			}
			vector<int> listeDiviseurs_tab{ listeDiviseurs(n) };
			std::cout << "La liste des diviseurs de " << n << " est : ";
			bool virgule{ false };
			for (auto const x : listeDiviseurs_tab)
			{
				if (virgule)
					cout << ", ";
				virgule = true;
				std::cout << x;
			}
			cout << "." << endl;

			if (n > 1500000)
			{
				std::cout << endl << "Le calcul risque d'être long, êtes-vous sûr de vouloir continuer ? (true/false) : ";
				if (EntreeSecurisee::trueFalse()) {
					determination_premier(n);
					cout << endl;
				}
			}
			else {
				determination_premier(n);
				cout << endl;
			}
		}

		std::cout << "Voulez vous rentrer un autre nombre ? (true/false) : ";
	} while (EntreeSecurisee::trueFalse());
}

vector<int> NombrePremier::listeDiviseurs(int n)
{
	vector<int> listeDiviseurs{};

	for (int i{ 2 }; i <= n / 2; i++)
		if(n % i == 0)
			listeDiviseurs.push_back(i);

	return listeDiviseurs;
}

unordered_map<int, int> NombrePremier::decomposition(unsigned int n)
{
	unordered_map <int, int> diviseurs{};
	string ligne{ "" };
	char espace{ ' ' };
	

	ifstream fichier_nb_premier{ "Repertoire nombres premiers.tkt" };

	
	while (getline(fichier_nb_premier, ligne))
	{
		auto debut = begin(ligne);
		auto fin = end(ligne);
		auto iterateur = find(debut, fin, espace);

		while (iterateur != fin && n != 1)
		{
			bool ndiviseur{ false };
			string diviseurS{ debut, debut + distance(debut, iterateur) };
			int diviseurI = stoi(diviseurS);
			int puissance{ 0 };

			while (n % diviseurI == 0) {
				ndiviseur = true;
				n /= diviseurI;
				puissance++;
			}

			if (ndiviseur)
				diviseurs.insert({ diviseurI, puissance });

			debut = iterateur + 1;
			iterateur = find(debut, fin, espace);
		}
		if (n == 1)
			break;
	}
	if (n != 1)
		diviseurs.insert({ n, 1 });
	
	return diviseurs;

}

void NombrePremier::determination_premier(int n)
{
	const clock_t begin_time = clock();

	if (n > 200000)
		std::cout << "Calcul en cours.";

	vector<int> nombresPremiers{ fichier(n, "Nombres premiers.tkt") };

	double tempsExecution = double((double)clock() - (double)begin_time);

	std::cout << endl << "L'ordinateur a trouvé " << nombresPremiers.size() << " nombres premiers";
	if (tempsExecution > 1)
		std::cout << " en " << tempsExecution << " millisecondes,\nce qui représente un rythme moyen de " << nombresPremiers.size() / tempsExecution << " nombres premiers par milliseconde." << endl;
	else if (tempsExecution == 1)
		std::cout << " en " << tempsExecution << " milliseconde,\nce qui représente un rythme moyen de " << nombresPremiers.size() / tempsExecution << " nombres premiers par milliseconde." << endl;
	else if (tempsExecution < 1)
		std::cout << " en moins d'une milliseconde." << endl;


	int rang{ entree_securiseAffichage(nombresPremiers) }; // entree_securiseAffichage(nombresPremiers)
	double vitesse_display{ 0 };
	const clock_t begin_time_display = clock();

	if (rang == -1)
	{
		for (auto const Nbp : nombresPremiers)
			std::cout << Nbp << ' ';

		double tempsExecution = double((double)clock() - (double)begin_time_display);
		vitesse_display = nombresPremiers.size() / tempsExecution;
	}
	else {
		if ((unsigned int)rang > nombresPremiers.size())
			rang = nombresPremiers.size();
		for (unsigned int i{ (unsigned int)nombresPremiers.size() - rang }; i < nombresPremiers.size(); i++)
			std::cout << nombresPremiers[i] << ' ';

		double tempsExecution = double((double)clock() - (double)begin_time_display);

		vitesse_display = rang / tempsExecution;

	}
	cout << endl;
	if (n > 20000)
	{
		std::string ligne{ "" };
		unsigned int val{ 4 };
		std::vector<float> tabVel{};

		ifstream fichier_lecture{ "Donnees_Projet.tkt" };

		if (fichier_lecture) {
			while (fichier_lecture >> ligne)
				tabVel.push_back(stof(ligne));

			ofstream fichier_vitesse{ "Donnees_Projet.tkt" };

			if (val > tabVel.size())
				val = tabVel.size();

			for (unsigned int i{ 0 }; i < val; i++)
				fichier_vitesse << tabVel[tabVel.size() - val + i] << " ";
			fichier_vitesse << vitesse_display;
		}
		else {
			ofstream fichier_vitesse{ "Donnees_Projet.tkt" };
			fichier_vitesse << vitesse_display;
		}
	}
}

vector<int> NombrePremier::fichier(int n, string nom)
{
	bool deux{ true };
	vector<int> nombresPremiers{};
	bool premier{ true };
	int retour_ligne{ 0 };
	nombresPremiers.push_back(2);
	
	ofstream fichier_nbpremier{ nom };

	const clock_t timer = clock();
	clock_t clockRefresh = clock();

	int pourc{ 0 };
	for (int i{ 3 }; i <= n; i += 2)
	{
		premier = true;
		int newPourc{ int(100.f * float(i) / n) };

		if (pourc != newPourc || clock() - clockRefresh > 1000.f) {
			int time{ int((clock() - timer) / 1000.f) };
			system("CLS");
			std::cout << newPourc << "%    "<< time / 3600 << "h "  << time / 60 << "m "<< time % 60<< "s" << std::endl;
			clockRefresh = clock();
		}
		pourc = newPourc;
		
		for (unsigned int c{ 2 }; c <= sqrt(i); c++)
			if (i % c == 0) {
				premier = false;
				break;
			}

		if (premier)
		{
			nombresPremiers.push_back(i);
			
			if (retour_ligne % 20 == 0 && retour_ligne != 0)
				fichier_nbpremier << endl;
			if (deux)
			{
				fichier_nbpremier << 2 << " ";
				retour_ligne++;
				deux = false;
			}
			retour_ligne++;
			fichier_nbpremier << i << " ";
			
		}
	}
	return nombresPremiers;
}

bool NombrePremier::test_primalite(int n)
{
	double racineN{ sqrt(n) };
	string ligne{ "" };
	bool premier{ true };
	bool valide{ false };

	do {
		ifstream fichier_nombres_premier{ "Repertoire nombres premiers.tkt" };
		valide = false ;

		if (fichier_nombres_premier)
		{
			char delimiteur{ ' ' };
			bool valide{ true };


			while (getline(fichier_nombres_premier, ligne) && valide)
			{
				auto debut = begin(ligne);
				auto fin = end(ligne);
				auto iterateur = find(debut, fin, delimiteur);

				while (iterateur != fin && valide)
				{
					string nombre_string{ debut, debut + distance(debut, iterateur) };
					int nombre_premier = stoi(nombre_string);

					if (nombre_premier <= racineN + 1) {
						if (n % nombre_premier == 0)
						{
							premier = false;
							valide = false;
							break;
						}
					}
					else
						valide = false;

					debut = iterateur + 1;
					iterateur = find(debut, fin, delimiteur);
				}
			}
		}
		else {
			std::cout << "Création du fichier \"Repertoire nombres premiers.tkt\"." << endl << endl;
				
			vector<int> nombrePremier{ fichier(33000, "Repertoire nombres premiers.tkt") };
			valide = true;
		}
	} while (valide);
	return premier;
}

int NombrePremier::entree_securiseAffichage(vector<int> & nombresPremiers)
{
	double vitesse{ 1 };
	std::cout << "\nVoulez-vous afficher tous les nombres trouvés ou seulement les x derniers ? (all / x)";


	std::vector<float> tabVel{};
	std::string ligne{ "" };
	ifstream fichier_vitesse{ "Donnees_Projet.tkt" };
	if (fichier_vitesse)
	{
		char delimiteur{ ' ' };
		bool valide{ true };


		while (getline(fichier_vitesse, ligne) && valide)
		{
			auto debut = begin(ligne);
			auto fin = end(ligne);
			auto iterateur = find(debut, fin, delimiteur);

			while (iterateur != fin && valide)
			{
				tabVel.push_back(stof(string{ debut, debut + distance(debut, iterateur) }));

				debut = iterateur + 1;
				iterateur = find(debut, fin, delimiteur);
			}
		}

		float moyenne{ 0.f };
		for (float const nb : tabVel)
			moyenne += nb;
		moyenne /= float(tabVel.size());

		if (moyenne != 0.f) {
			int tempsEstime{ (int)(nombresPremiers.size() / moyenne) / 1000 };

			if (tempsEstime >= 1)
				std::cout << ", (temps estimé (all) : " << tempsEstime << "s) : ";
			else
				std::cout << ", (temps estimé (all) < 1s) : ";
		}
	}
	else
		cout << " : ";

	int rang{ 0 };
	int compteur_espace{ 0 };
	int compteur_invalide{ 0 };
	bool valide{ true };
	string rejouer{ "" };
	

	do
	{
		getline(cin, rejouer);

		auto debut = begin(rejouer);
		auto fin = end(rejouer);
		auto espace = count(debut, fin, ' ');

		valide = true;

		if (espace != 0)
		{
			compteur_espace++;
			if (compteur_espace == 1) {
				std::cout << "Ne rentrez pas d'espace, recommencez : ";
				valide = false;
				continue;
			}
			else {
				std::cout << "Recommencez : ";
				valide = false;
				continue;
			}
		}

		if (all_of(begin(rejouer), end(rejouer), isdigit))
		{
			rang = stoi(rejouer);
			if (rang < 0)
			{
				std::cout << "Entrée invalide. Rentrez un nombre positif : ";
				valide = false;
				continue;
			}
			else
				return rang;
		}
		else if (rejouer == "all")
			return -1;
		else
		{
			compteur_invalide++;
			if (compteur_invalide == 1)
				std::cout << "Entrée invalide, recommencez : ";
			else
				std::cout << "Recommencez : ";
			valide = false;
			continue;
		}

	} while (!valide);

	return rang;
}

NombrePremier::~NombrePremier()
{

}