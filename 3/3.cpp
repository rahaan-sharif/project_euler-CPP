#include <iostream>
#include <math.h>
using namespace std;
long long int prime_factor(long long int);
bool is_prime(long long int);

int main(void)
{
	cout<<prime_factor(600851475143)<<endl;

	return 0;
}
bool is_prime(long long int a)
{
	for (long long int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}

long long int prime_factor(long long int a)
{
	long long int large = -1;
	for (long long int i = 1; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			if (is_prime(i))
				if (i > large)
					large = i;
			if (is_prime(a / i))
				if((a/i)>large)
					large=a/i;
		}
	}
	return large;
}
