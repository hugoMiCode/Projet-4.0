#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <sstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <iomanip>
class ApproximatePi
{
public:
	ApproximatePi();
	void approxim();
	void reset();
	int nbDigitsValides();

private:
	int64_t r;
	double pi, total, total_circle, compteur, recordPi;
};

