#include <iostream>
#include <math.h>
using namespace std;

bool check(int item1, int item2, int item3)
{
	item1 *= item1;  item2 *= item2;  item3 *= item3;
	if (item1 + item2 == item3)
		return 1;
	if (item1 + item3 == item2)
		return 1;
	if (item1 == item2 + item3)
		return 1;
	return 0;
}

int main(void)
{
	for(int i=1; i<1000; i++)
		for(int j=1; j<i; j++)
			for (int k = 1; k < j; k++)
				if (i + j + k == 1000)
					if (check(i, j, k))
					{
						cout <<"nubers:  "<< i << ", " << j << ", " << k << endl;
						cout <<"product: "<< i * j * k << endl;
						return 0;
					}


	return 0;
}
