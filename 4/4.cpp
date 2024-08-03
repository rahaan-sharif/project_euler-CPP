#include <iostream>
using namespace std;
bool is_palirdorme(int);
int main(void)
{
	long long int large = 0;
	long long int number = 0;
	for (int i = 0; i < 900; i++)
	{
		for (int j = 100 + i; j < 1000; j++)
		{
			number = j * (100 + i);
			if (number>large)
			{
				if (is_palirdorme(number))
					large = number;
			}
		}
	}
	cout << large << endl;


	return 0;
}
bool is_palirdorme(int a)
{
	int b = 0, aa=a; 
	while (a != 0)
	{
		b=(b*10)+(a%10);
		a /= 10;
	}
	if (aa == b)
		return 1;
	return 0;
}



