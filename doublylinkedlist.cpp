#include<iostream>
using namespace std;

struct node
{
    int data;
    node * next;
    node * previous;

};
typedef node * eptr;
class linkedlist
{
    public:
    eptr head=NULL;
    void insert(int d)
    {
        eptr temp=new node;
        temp->data=d;
        if(head==NULL)
        {
            head=temp;
            temp->next=NULL;
            temp->previous=NULL;
        }
        else
        {
            cout<<"choose a number after which node is to be inserted:";
            int x;cin>>x;
            eptr walker=head;
            while(walker!=NULL)
            {
                if(walker->data==x)
                {
                    break;
                }
                walker=walker->next;
            }
            if(walker==NULL)
            {
                cout<<"not found\n";

            }
            else if(walker->next==NULL) //last node
            {
                walker->next=temp;
                temp->previous=walker;
                temp->next=NULL;
            }
            
            else
            {
                temp->previous=walker;
                temp->next=walker->next;
                temp->next->previous=temp;
                walker->next=temp;
            }
        }

    }

    void display()
    {
        eptr walker=head;
        cout<<"list: ";
        while(walker!=NULL)
        {
            cout<<walker->data<<" ";
            walker=walker->next;
        }
        cout<<endl;
    }

    void del()
    {
        cout<<"choose the number u want to delete:";
        int x;
        cin>>x;
        eptr walker=head;
            while(walker!=NULL)
            {
                if(walker->data==x)
                {
                    break;
                }
                walker=walker->next;
            }
            if(walker==NULL)
            {
                cout<<"no such element\n";
            }
            else if(walker==head)
            {
                head=walker->next;
                walker->next->previous==NULL;
                delete walker;

            }
            
            else if(walker->next==NULL)
            {
                walker->previous->next==NULL;
                delete walker;
            }
            else
            {
                walker->previous->next=walker->next;
                walker->next->previous=walker->previous;
                delete walker;
            }


    }
};
int main()
{
    linkedlist l;
    while(1)
    {
        cout<<"1. insert\n2. delete  3.display\n";
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<"element:";
            int element;
            cin>>element;
            l.insert(element);
        }
        else if(n==2)
        {
            l.del();
        }
        else
        {
            l.display();
        }
    }
}