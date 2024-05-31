#include <iostream>
#include <math.h>
using namespace std;
long long int function(int);
int main(void)
{
	cout << function(100);


	return 0;
}

long long int function(int length)
{
	long long int sum = 0; 
	long long product = 0;
	for (int i = 1; i <= length; i++)
	{
		sum += pow(i, 2);
		product += i;
	}
	product = pow(product, 2);
	return (product - sum);
}