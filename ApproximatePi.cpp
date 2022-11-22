#include "ApproximatePi.h"

double const _PI{ 3.14159265358979323846 };

ApproximatePi::ApproximatePi()
{
	reset();
	bool reset_values{ true };
	while (true) {
		approxim();


		if (GetAsyncKeyState(0x58)) { // KeyBoard X
			std::cout << "Fin du programme !" << std::endl;
			break;
		}
		if (GetAsyncKeyState(0x52)) { // KeyBoard::R
			if (reset_values) {
				std::cout << std::endl << "Reset !!" << std::endl;
				reset();
				reset_values = false;
			}
		}
		else
			reset_values = true;
	}
	std::cout.precision(6);
}

void ApproximatePi::approxim()
{
	double x = (double)rand() / (double)RAND_MAX * (-(double)2 * this->r) + this->r;
	double y = (double)rand() / (double)RAND_MAX * (-(double)2 * this->r) + this->r;
	total++;

	if ((double)x * (double)x + (double)y * (double)y <= r * r)
		total_circle++;

	pi = (double)4 * total_circle / total;
	double recordDiff{ std::abs(_PI - recordPi) };
	double diff{ std::abs(_PI - pi) };
	if (diff < recordDiff) {
		compteur++;
		recordDiff = diff;
		recordPi = pi;

		int valideDigits{ nbDigitsValides() };

		std::cout << "Pi(" << total << ") : " << std::setprecision(valideDigits + 1) << this->pi << std::endl;
	}
}
void ApproximatePi::reset()
{
	this->pi = 0;
	this->r = 1000000;
	this->total = 0, this->total_circle = 0, this->compteur = 0, this->recordPi = 0;
}

int ApproximatePi::nbDigitsValides()
{
	int com{ 0 };

	std::string s_PI{ std::to_string(_PI * (long double)1000000000) };
	std::string s_pi{ std::to_string(this->recordPi * (long double)1000000000) };

	//std::cout << "s_PI : " << s_PI << std::endl;
	//std::cout << "s_pi : " << s_pi << std::endl << std::endl;

	while (s_PI[com] == s_pi[com]) {
		//std::cout << s_PI[com] << "  " << s_pi[com] << std::endl;
		com++;
	}
	return com;
}