#pragma once
#include <vector>

class Goldbach
{
public:
	Goldbach();

	void fillValue(unsigned int n);
	void fillSize(unsigned int size);

private:
	std::vector<unsigned int> primes;
};

