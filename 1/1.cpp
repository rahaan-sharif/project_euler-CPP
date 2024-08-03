#include <iostream>
#include <math.h>
using namespace std;
#define length 1000

bool check_p(int);

int main(void)
{
	int sum = 0;
	for (int i = 1; i < length; i++)
		if (check_p(i))
			sum += i;
	cout << sum << endl;



	return 0;
}

bool check_p(int a)
{
	if (a % 3 == 0)
		return 1;
	if (a % 5 == 0)
		return 1;
	return 0;
}
