#include "Goldbach.h"
#include <iostream>

Goldbach::Goldbach()
{
	unsigned int number{ 4 };
	unsigned int conteur{ 0 };

	/*
	std::cout << "##";
	for (unsigned int nb : primes)
		std::cout << nb << std::endl;

	std::cout << "##";
	for (unsigned int nb : primes)
		std::cout << nb << std::endl;
	*/

	while (number < 1000000) {
		unsigned int i{ 0 };
		do {
			if (i >= primes.size())
				fillSize(i + 1);

			for (unsigned int j{ 0 }; primes[j] <= number - primes[i]; j++) {
				if (j + 1 >= primes.size())
					fillSize(j + 2);

				if (primes[i] + primes[j] == number) {
					//std::cout << primes[i] << " + " << primes[j] << " = " << number << std::endl;
					conteur++;
				}
			}

			i++;

		} while (2 * primes[i] <= number);
		std::cout << number << " : " << conteur << std::endl;
		conteur = 0;
		number += 2;
	}

}

void Goldbach::fillValue(unsigned int n)
{
	if (!primes.empty() && primes[primes.size() - 1] >= n)
		return;
	else {
		if (primes.empty())
			primes.push_back(2);

		unsigned int debut{ primes[primes.size() - 1] };

		for (unsigned int number{ debut + 1 }; number <= n; number++) {
			bool prime{ true };
			for (unsigned int i{ 0 }; primes[i] <= sqrt(number); i++) {
				if (number % primes[i] == 0) {
					prime = false;
					break;
				}
			}
			if (prime)
				primes.push_back(number);
		}
	}
}

void Goldbach::fillSize(unsigned int size)
{
	if (primes.empty())
		primes.push_back(2);

	unsigned int number{ primes.back() + 1 };

	while (primes.size() <= size) {
		bool prime{ true };
		for (unsigned int i{ 0 }; primes[i] <= sqrt(number); i++) {
			if (number % primes[i] == 0) {
				prime = false;
				break;
			}
		}
		if (prime)
			primes.push_back(number);

		number++;
	}
}
