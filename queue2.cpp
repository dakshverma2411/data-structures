#include<iostream>
using namespace std;

class queue
{
    public:
    int *arr;
    int front=-1;
    int rear=-1;

    int size;
    queue()
    {
        
        cin>>size;
        // size++;
        arr=new int[size];
    }
    bool isempty()
    {
        if(front==-1)
        return true;
        else return false;
    }
    bool isfull()
    {
        if((rear+1)%size==front)
        {
            return true;
        }
        else return false;
    }
    void insert_R(int data)
    {
        if(!isfull())
        {
            if(isempty())
            {
                rear=0;
                front=0;
                arr[0]=data;
            }
            else
            {
            rear=(rear+1)%size;
            arr[rear]=data;
            }
        }
        else{cout<<"list is full\n";}
    }
    int del_F()
    {
        if(!isempty())
        {
            if(rear==front)
            {
                int x=rear;
                rear=front=-1;
                return arr[x];
                
            }
            else
            {
                int x=front;
                front=(front+1)%size;
                return arr[x];
            }
        }
        else
        {
            cout<<"list is empty\n";
            return 0;
        }
    }
    void display()
    {
       int x=front;
       cout<<"queue:";
       while(x!=rear)
       {
           cout<<arr[x]<<" ";
        x=(x+1)%size;
       }
       cout<<arr[rear];
       cout<<endl;
    }
    void positions()
    {
        cout<<"front:"<<front<<endl<<"rear:"<<rear<<endl;
    }

};
int main()
{
    queue q;
    while(1)
    {
        
        cout<<"1.insert   2.delete\n";
        int n;
        cin>>n;
        if(n==1)
        {
            int element;
            cout<<"enter number:";
            cin>>element;
            q.insert_R(element);
        }
        else if(n==2)
        {
            cout<<"deleted item:";
            cout<<q.del_F()<<endl;
        }
        else {
            q.display();
        }
        q.positions();
        cout<<endl;
    }
}