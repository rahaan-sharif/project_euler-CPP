#include <iostream>
#include <math.h>
# define length 20
using namespace std;

bool is_prime(int item)
{
	bool check = 1;
	for (int i = 2; i <= sqrt(item); i++)
	{
		if (item % i == 0)
		{
			check = 0;
			return check;
		}
	}
	return check;
}

int function(int total, int item)
{
	int t_item = item;
	int temp = total;
	for (int i = 2; i <= item; i++)
	{
		if (is_prime(i) && item%i==0)
		{
			if (temp % i == 0)
			{
				temp /= i;
			}
			else
			{
				total *= i;
			}
			item /= i;
			i = 1;
		}
	}
	return total;
}

int main(void)
{
	int total = 1;
	for (int i = 2; i <= length; i++)
	{
		total = function(total, i);
	}
	cout << "answer: " << total << endl;


	return 0;
}