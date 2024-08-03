#include <iostream>
using namespace std;
#define length 20

int main(void)
{
	cout << "enter your grid: \n";
	int ent[length][length] = { 0 };
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			cin >> ent[i][j];

	long long int temp = 1, multiple = 0;
	for(int i=0; i<length-3; i++)
		for (int j = 0; j < length-3; j++)
		{
			for (int k = 0; k < 4; k++)
				temp *= ent[i+k][j+k];
			if (temp > multiple)
				multiple = temp;
			temp = 1;
		}

	for(int i=0; i<length; i++)
		for (int j = 0; j < length - 3; j++)
		{
			for (int k = 0; k < 4; k++)
				temp *= ent[i][j + k];
			if (temp > multiple)
				multiple = temp;
			temp = 1;
		}

	for (int i = 0; i < length-3; i++)
		for (int j = 0; j < length; j++)
		{
			for (int k = 0; k < 4; k++)
				temp *= ent[i+k][j];
			if (temp > multiple)
				multiple = temp;
			temp = 1;
		}

	for (int i = 0; i < length-3; i++)
		for (int j = 3; j < length ; j++)
		{
			for (int k = 0; k < 4; k++)
				temp *= ent[i + k][j - k];
			if (temp > multiple)
				multiple = temp;
			temp = 1;
		}
	cout << "************\n";
	cout << "answer: " << multiple << endl;

	return 0;
}