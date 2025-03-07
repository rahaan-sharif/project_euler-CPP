//this code gives the wrong answer.
//but I have checked it many times.
//I got nothing. I gived it to chat gpt
//but it couldn't find the problem. I 
//thing there is a minor problem that I 
//missed it.

#include <iostream>
using namespace std;

class digits
{
private:
    int d_num, length;
    string s_num;
    digits *next;

public:
    digits(int d_num_in, string s_num_in)
    {
        d_num = d_num_in;
        s_num = s_num_in;
        length = s_num.length();
        next = NULL;
    }
    void add_num(digits *&start, int d_num_in, string s_num_in)
    {
        if (start == NULL)
        {
            start = new digits(d_num_in, s_num_in);
            return;
        }
        else
        {
            digits *tmp_digits = start;
            while (tmp_digits->next != NULL)
            {
                tmp_digits = tmp_digits->next;
            }
            tmp_digits->next = new digits(d_num_in, s_num_in);
        }
    }
    void show(digits *start)
    {
        while (start != NULL)
        {
            cout << start->d_num << ": " << start->s_num << ": " << start->length << endl;
            start = start->next;
        }
    }
    int get_length(digits *start, int in_num)
    {
        while (start != NULL)
        {
            if (start->d_num == in_num)
            {
                cout << start->s_num << " ";
                return start->length;
            }
            start = start->next;
        }
        cout << in_num << "*** not found! ***\n";
        return -1;
    }
    int calculator_function(digits *start, int in_num)
    {
        cout << "<<< calculation_function >>>" << endl;
        int arr[3] = {0};
        arr[2] = (in_num % 1000) / 100;
        arr[1] = (in_num % 100) / 10;
        arr[0] = in_num % 10;
        for (int i = 2; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        int total_sum = 0;

        if (arr[2] != 0)
        {
            if (arr[2] != 0 )
            {
                total_sum += start->get_length(start, arr[2]);
                total_sum += start->get_length(start, 100);
                int tmp_num = arr[1] * 10 + arr[0];
                if(tmp_num>0)
                {
                    total_sum+=3;
                    cout<<"and ";
                }
                if (tmp_num > 9 && tmp_num < 20)
                    total_sum += start->get_length(start, tmp_num) ;
                else if(tmp_num>0)
                {
                    total_sum += start->get_length(start, arr[1] * 10);
                    total_sum += start->get_length(start, arr[0]);
                }
            }
            else
            {
                total_sum += start->get_length(start, arr[2]);
                total_sum += start->get_length(start, 100);
                total_sum += 3;
                cout << "and ";
                int tmp_num = arr[1] * 10 + arr[0];
                total_sum += start->get_length(start, tmp_num);
            }
        }
        else
        {
            int tmp_num = arr[1] * 10 + arr[0];
            if (tmp_num > 9 && tmp_num < 20)
                total_sum += start->get_length(start, tmp_num) + 3;
            else
            {
                total_sum += start->get_length(start, arr[1] * 10);
                total_sum += start->get_length(start, arr[0]);
            }
        }
        cout << "\nlength: " << total_sum << endl;
        return total_sum;
    }
};

int main(void)
{
    digits *start = NULL;
    start->add_num(start, 0, "");
    start->add_num(start, 1, "one");
    start->add_num(start, 2, "two");
    start->add_num(start, 3, "three");
    start->add_num(start, 4, "four");
    start->add_num(start, 5, "five");
    start->add_num(start, 6, "six");
    start->add_num(start, 7, "seven");
    start->add_num(start, 8, "eight");
    start->add_num(start, 9, "nine");
    start->add_num(start, 10, "ten");
    start->add_num(start, 11, "eleven");
    start->add_num(start, 12, "twelve");
    start->add_num(start, 13, "thirteen");
    start->add_num(start, 14, "fourteen");
    start->add_num(start, 15, "fifteen");
    start->add_num(start, 16, "sixteen");
    start->add_num(start, 17, "seventeen");
    start->add_num(start, 18, "eighteen");
    start->add_num(start, 19, "nineteen");
    start->add_num(start, 20, "twenty");
    start->add_num(start, 30, "thirty");
    start->add_num(start, 40, "forty");
    start->add_num(start, 50, "fifty");
    start->add_num(start, 60, "sixty");
    start->add_num(start, 70, "seventy");
    start->add_num(start, 80, "eighty");
    start->add_num(start, 90, "ninety");
    start->add_num(start, 100, "hundred");

    long long int total_letters=0;
    int num_count=0;
    for(int i=1; i<1000; i++)
    {
        num_count++;
        cout<<"num_count: "<<num_count<<endl;
        total_letters+=start->calculator_function(start, i);
        cout<<"---------\n\n";
    }
    total_letters+=11;   //this is adding letter counter of "one thousand".
    cout<<total_letters<<endl;

    return 0;
}