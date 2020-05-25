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
    node* header=NULL;
    node * end=NULL;
    void insert(int d)
    {
        node * temp=new node;
        temp->data=d;
        temp->next=NULL;
        node * t=header;
        if(t!=NULL)
        {
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
        
        }
        else
        {
            header=temp;
        }
        end=temp;
    }
   
    void reorderlist()
    {
      node * current=header;
      
      if(current!=NULL)
      {
         
      while((current->next!=end)&&(current!=end))
      {
        
          node * temp=removelast();
          temp->next=current->next;
          current->next=temp;
          current=temp->next;
        
      }
     
      }
    
    }
    node * removelast()
    {
        node * temp=header;
        if(header==NULL)
        {
            return NULL;
        }
        else if(header->next==NULL)
        {
            return NULL;
        }
        else
        {
            while(temp->next!=end)
            {
                temp=temp->next;
                
            }
            node * temp2=temp->next;
            temp->next=NULL;
            end=temp;
            return temp2;
        }
        
    }
    void display()
    {
        node * temp=header;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
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
       {
           int element;
           cin>>element;
           list.insert(element);
           
       }
       list.reorderlist();
       list.display();
   } 
}