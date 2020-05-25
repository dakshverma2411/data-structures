#include<iostream>
using namespace std;

class queue
{
    public:
    int *arr;
    int front=-1;
    int rear=-1;
    int size;
    queue(int n)
    {
        size=n;
        arr=new int[n+1];
    }
    ~queue()
    {
        delete arr;
    }
    void insert(int data)
    {
        if(rear!=-1&&front!=-1)
        {
        if((rear+2)%(size+1)==(front%(size+1)))
        {
            cout<<"queue is full"<<endl;
        }
        else{
            rear=(rear+1)%(size+1);
            arr[rear]=data;
        }
        }
        else{
            rear=0;
            front=0;
            arr[0]=data;
        }
    }
    void del()
    {
        if(rear==-1)
        {
            cout<<"queue is empty"<<endl;
        }
        else
        {
            front=(front+1)%(size+1);

        }
        if((rear+1)%(size+1)==(front%(size+1)))
        {
            rear=-1;
            front=-1;
        }

    }
    void display()
    {
        if(rear!=-1)
        {
            cout<<"queue:";
        int start=front;
        int end = rear;
        while(start!=end)
        {
            cout<<arr[start]<<" ";
            start=(start+1)%(size+1);
        }
        cout<<arr[end]<<endl;
        }
        else{
            cout<<"empty queue"<<endl;
        }
    }


};
int main()
{
    queue q(5);
    while(1)
    {
        cout<<"1 for insert\n2 for delete\n3 for display\n";
        int n;
        cin>>n;
        if(n==1)
        {
            int element;
            cout<<"enter element:";
            cin>>element;
            q.insert(element);
        }
        else if(n==2)
        {
            q.del();
        }
        else
        {
            q.display();
        }
    }
}