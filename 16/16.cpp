#include <iostream>
using namespace std;

int power_func(int* arr, int exp, int length=50)
{
    arr = new int[length];
    for(int i=0; i<length; i++)
    {
        arr[i]=0;
    }
    int carr=0;
    arr[0]=2;
    for(int i=0; i<exp-1; i++)
    {
        for(int j=0; j<length; j++)
        {
            
            arr[j]*=2;
            arr[j]+=carr;
            if(arr[j]>9)
            {
                carr=arr[j]/10;
                arr[j]%=10;
            }
            else
            {
                carr=0;
            }
        }
    }

    int digit_sum=0;
    for(int i=length-1; i>=0; i--)
    {
        digit_sum+=arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return digit_sum;



}

int main(void)
{
    int* arr=NULL;
    cout<<power_func(arr, 1000, 350);


    return 0;
}