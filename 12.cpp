#include <iostream>
#include <math.h>
#define length 500
using namespace std;

int divisors(long long int item)
{
	int divisors = 0;
	for (long long int i = 1; i <= sqrt(item); i++)
	{
		if (item % i == 0)
			divisors += 2;
		if (i == sqrt(item))
			divisors--;
	}

	return divisors;
}

int main(void)
{
	long long int triangle = 1;
	int d = 0;
	for (long long int i = 2; i < 100000000; i++)
	{
		cout << triangle << "  * ";
		d = divisors(triangle);
		if (d > length)
		{
			cout << "answer: " << triangle << endl;
			break;
		}
		cout << endl;
		triangle += i;
	}


	return 0;
}