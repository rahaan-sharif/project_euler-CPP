//problem number 8:
// first of all, you have to write the numbers
//given by the site in a file named spam.txt

#include <iostream>
#include <fstream>
#define length 13

using namespace std;

int main(void)
{
	int enterence[1000] = { 0 }, loc=0;
	char ch;
	ifstream my_file("spam.txt", ios::in);
	my_file.get(ch);
	while (!my_file.eof())
	{
		if (ch != '\n')
			enterence[loc++] = ch - 48;
		my_file.get(ch);
	}
	my_file.close();

	cout << loc << endl;
	int position = length-1;
	long long int multiple = 0;
	long long int temp = 0;

	while (position<loc)
	{
		temp = 1;
		for (int i = 0; i < length; i++)
		{
			temp *= enterence[position - i];
			cout << enterence[position - i];
		}
		cout << endl;
		cout << "  temp: " << temp << endl;

		for (int i = 0; i < length; i++)
			cout << enterence[position - i];
		cout << endl;
		cout << "************\n";
		if (temp > multiple)
		{
			multiple = temp;
		}
		position++;
	}
	cout << "answer: " << multiple << endl;


	
	return 0;
}
