#include <iostream>


#include <vector>
#include <iterator>

const int MAX = 100;

int main(int argc, char const *argv[])
{

	std::vector<int> primes;

	bool _isPrime;

	bool isPrime[MAX + 1];

	for (int i = 2; i < MAX; ++i)
	{
		_isPrime = true;
		for (std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) if (i % *it == 0) _isPrime = false;
		if (_isPrime) {
			primes.push_back(i);
			isPrime[i] = true;
		}
		else isPrime[i] = false;

	}

	for_each(primes.begin(), primes.end(), [](int x){std::cout << x << ", ";});

	int size = primes.size();
	int _third;


// Generalize the loop nesting depth

	for (int n = 0; n < MAX; ++n)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = i; j < size; ++j)
			{
				if ((_third = n - primes[i] - primes[j]) >= primes[j] && isPrime[_third]) printf("%d = %d + %d + %d\n", n, primes[i], primes[j], _third);
			}
		}
		
	}

	
	// prime generator

	// dynamically allocated array or constant capacity?

	// How to test the performance of two different programs/executables?

	// Manually control nesting depth

	


	return 0;
}