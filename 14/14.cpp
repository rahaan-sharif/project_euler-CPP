//I solve this problem with recersive function.
//It take more time, but I want to have this method
//of solving in my repository.
#include <iostream>
using namespace std;

long long int chain_length(long long int item, int check)
{
	static long long int length = 0;
	if (check == 0)
		length = 0;
	if (item == 1)
	{
		length++;
		return length;
	}
	else if (item % 2 == 0)
	{
		length++;
		chain_length(item / 2, 1);
	}
	else if (item % 2 != 0)
	{
		length++;
		chain_length((3 * item) + 1, 1);
	}
}

int main(void)
{
	long long int longest[2] = { 0 }, temp=0;
	for (long long int i = 1; i < 1000000; i++)
	{
		cout << "i: " << i << "\t";
		temp = chain_length(i, 0);
		cout << temp << endl;
		if (temp > longest[1])
		{
			longest[0] = i;
			longest[1] = temp;
		}
	}

	cout << "****\n" << endl;
	cout << "final answer:    i= ";
	cout << longest[0] << "      chain_length= " << longest[1] << endl;



	return 0;
}