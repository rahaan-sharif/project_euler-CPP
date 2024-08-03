#include <iostream>
#include <math.h>
#define length 2000000
using namespace std;

bool is_prime(int item)
{
	for (int i = 2; i <= sqrt(item); i++)
		if (item % i == 0)
			return 0;
	return 1;
}

int main(void)
{
	long long int sum = 0;
	for (int i = 2; i < length; i++)
		if (is_prime(i))
		{
			sum += i;
			cout << i << endl;
		}
	cout << sum << endl;



	return 0;
}
