#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node * next;
};
class linklist
{
    public:
    node * header=NULL;
    void sortinsert(int d)
    {
        node * temp=new node;
        temp->data=d;
        node * t=header;
        if(t!=NULL)
        {
            if(t->data>=d)
            {
                temp->next=header;
                header=temp;
            }
            else{
             while(t->next!=NULL)
            {
            if(t->next->data>=d)
            {
                break;
            }
            else
            {
                t=t->next;
            }

            }
            temp->next=t->next;
            t->next=temp;}
            }
        else
        {
            header=temp;
            temp->next=NULL;
        }
    }
    void display()
    {
        node * temp=header;
        cout<<"link list:";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }

    void remove_duplicates()
    {
        node * temp=header;
        if(temp!=NULL)
        {
        int var=temp->data;
        while(temp->next!=NULL)
        {
            if(temp->next->data==var)
            {
                node * t=temp->next;
                temp->next=temp->next->next;
                delete t;
                // cout<<"deleted "<<var<<endl;

            }
            else{
                var=temp->next->data;
                temp=temp->next;
            }
            
            if(temp==NULL)
            {
                break;
            }
        }
        }
    }


};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        linklist list;
        int n;
        cin>>n;
        while(n--)
        { int element;
        cin>>element;
            list.sortinsert(element);
        }
        list.display();
        list.remove_duplicates();
        list.display();
    }


}