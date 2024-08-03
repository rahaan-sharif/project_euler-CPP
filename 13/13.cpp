#include <iostream>
using namespace std;
int main(void)
{
	char ent[100][50] = { 0 }, ch;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 50; j++)
		{
			cin >> ch;
			if (ch == '\n' || ch == ' ')
			{
				i--;
				j--;
				continue;
			}
			ent[i][j] = ch;
		}

	cout << "***\n";
	int ent_int[100][50] = { 0 };
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 50; j++)
			ent_int[i][j] = ent[i][j] - 48;

	int total_answer[52] = { 0 };
	for(int i=0; i<100; i++)
		for (int j = 0; j < 50; j++)
			total_answer[j + 2] += ent_int[i][j];
	
	for(int i=51; i>0; i--)
		if (total_answer[i] > 9)
		{
			total_answer[i - 1] += total_answer[i] / 10;
			total_answer[i] %= 10;
		}

	cout << "answer: ";
	for (int i = 0; i < 10; i++)
		cout << total_answer[i];
	cout << endl;

	return 0;
}