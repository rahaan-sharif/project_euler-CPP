#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
    int length = 15;
    int *a = new int[(length+3) * length];
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            a[i * length + j] = 0;
        }
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i * length + j];
        }
    }
    cout << "***********" << endl<<endl<<endl;
    cout<<"order of numbers: "<<endl;

    int lat=0, lon=0, sum=a[0];
    int tmp_sum[4]={0}, max_sum=0;
    for(int i=0; i<length; i++)
    {
        lat++;
        tmp_sum[0]=a[lat*length+lon]+a[(lat+1)*length+lon];
        tmp_sum[1]=a[lat*length+lon]+a[(lat+1)*length+lon+1];
        tmp_sum[2]=a[lat*length+lon+1]+a[(lat+1)*length+lon];
        tmp_sum[3]=a[lat*length+lon+1]+a[(lat+1)*length+lon+2];

        if(tmp_sum[0]>tmp_sum[1] && tmp_sum[0]>tmp_sum[2] && tmp_sum[0]>tmp_sum[3])
        {
            cout<<a[lat*length+lon]<<" ";
            sum+=a[lat*length+lon];
        }
        else if(tmp_sum[1]>tmp_sum[0] && tmp_sum[1]>tmp_sum[2]&& tmp_sum[0]>tmp_sum[3])
        {
            cout<<a[lat*length+lon]<<" ";
            sum+=a[lat*length+lon];
        }
        else if(tmp_sum[2]>tmp_sum[0] && tmp_sum[2]>tmp_sum[1] && tmp_sum[2]>tmp_sum[3])
        {
            cout<<a[lat*length+lon+1]<<" ";
            sum+=a[lat*length+lon+1];
            lon++;
        }
        else
        {
            cout<<a[lat*length+lon+1]<<" ";
            sum+=a[lat*length+lon+1];
            lon++;
        }
    }

    cout<<endl<<endl<<sum<<endl<<endl;



    return 0;
}