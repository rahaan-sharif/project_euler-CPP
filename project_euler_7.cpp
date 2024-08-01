#include <iostream>
#include <math.h>
#define length 10001
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
	int counter = 0;
	int item = 1;
	while (counter != length)
	{
		item++;
		counter += is_prime(item);
	}
	cout << item << endl;


	return 0;
}
