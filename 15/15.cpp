#include <iostream> 
using namespace std;

class data_
{
private:
    long long int input1, input2, ways;
    data_* next;
public:
    data_(long long int input1_in, long long int input2_in, long long int ways_in)
    {
        input1=input1_in;
        input2=input2_in;
        ways=ways_in;
        next=NULL;
    }
    void insert_data(data_*& start, long long int input1, long long int input2, long long int ways)
    {
        if(start==NULL)
        {
            start=new data_(input1, input2, ways);
        }
        else
        {
            data_* tmp_node=start;
            while(tmp_node->next!=NULL)
            {
                tmp_node=tmp_node->next;
            }
            tmp_node->next=new data_(input1, input2, ways);
        }
    }
    long long int get_ways(data_* start, int input1_in, int input2_in)
    {
        while(start!=NULL)
        {
            if(start->input1==input1_in && start->input2==input2_in)
                return start->ways;
            else if(start->input2==input1_in && start->input1==input2_in)
                return start->ways;
            start=start->next;
        }   
        return -1;
    }
    void show(data_* start)
    {
        while(start!=NULL)
        {
            cout<<start->input1<<", "<<start->input2<<":\t"<<start->ways<<endl;
            start=start->next;
        }
    }
};

long long int path_function(data_*& start, int input1=2, int input2=2)
{
    long long int querry=start->get_ways(start, input1, input2);
    cout<<"querry: "<<querry<<endl;
    if(querry!=-1)
        return querry;
    //cout<<"input1: "<<input1<<"\t\tinput2: "<<input2<<endl;
    if(input1==0)
    {
        return 1;
    }
    else if(input2==0)
    {
        return 1;
    }
    else
    {
        long long int output=0;
        output+=path_function(start, input1-1, input2);
        output+=path_function(start, input1, input2-1);
        start->insert_data(start, input1, input2, output);
        return output;
    }
}

int main(void)
{
   data_* start=NULL;
   cout<<path_function(start, 20, 20);
    


    return 0;
}