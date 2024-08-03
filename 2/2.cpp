#include <iostream>
using namespace std;
#define length 4000000

void fibonatchi();
int main(void)
{

	cout << "salam donya"<<endl;
	fibonatchi();


	return 0;
}


void fibonatchi()
{
	int sum = 0;
	int a1 = 1, a2 = 2, a3 = 3, temp = 0;
	sum +=a2;

	for (; temp <= length; )
	{
		temp = a2 + a3;
		cout << temp << endl;
		a1 = a2;
		a2 = a3;
		a3 = temp;
		if(temp%2==0)
			sum += temp;
	}
	cout << sum;
}
