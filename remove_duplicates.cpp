#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next=NULL;   // can it be 0?
};
class linklist{
    
    public:
    node* header=NULL;
    node* end=NULL;
    
    void insert(int d,node * p=NULL)  //after p
    {   node * temp=new node;
        if(p==NULL)
        { 
            temp->data=d;
            temp->next=header;
            header=temp;
        }
        else
        {          
            temp->data=d;
            temp->next=p->next;
            p->next=temp;

        }
        if(temp->next==NULL)
        {
            end=temp;
        }
    }
    void display()
    {
        node* temp=header;
        cout<<"link list:";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
         cout<<endl;

    } 
    node * biggernode(int d)
    {
        node * temp=header;
        if(header!=NULL){
        if(header->data>d)
        {
            return NULL;
        }
        while(temp->next!=NULL)
        {
            if(temp->next->data>d)
            {
                return temp;
            }
            else{
                temp=temp->next;
            }
        }
        return temp;}
        else
        {
            return NULL;
        }
    }
    void remove_duplication()
    {
        node * temp=header;
        while(temp!=NULL)
        {
            temp->next=biggernode(temp->data)->next;

            temp=temp->next;
            
        }
    }
    void removeduplication()
    {
        node * temp=header;
        int var=header->data;
        while(temp->next!=NULL)
        {
            if(temp->next->data==var)
            {
                node * temp2;
                temp2=temp->next;
                temp->next=temp2->next;
                temp2->next=NULL;
                delete temp2;
            }
           else{var=temp->next->data;
           temp=temp->next;}
        }
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        linklist list1;
        int n;
        cin>>n;
        while(n--)
        {
           int element;
           cin>>element;
           list1.insert(element,list1.biggernode(element));
           list1.display();
        }
        list1.removeduplication();
       list1.display();
    
    }
}