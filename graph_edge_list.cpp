#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
class node
{
    public:
    string edge_name;
    int vertex1;
    int vertex2;
    node * next;
};
class edgelist
{
    public:
    node * head=NULL;
    void add_edge(int v1,int v2,string name)
    {
        if(head==NULL)
        {
            head=new node;
            head->edge_name=name;
            head->vertex1=v1;
            head->vertex2=v2;
            head->next=NULL;
        }
        else
        {
            node * temp=new node;
            temp->edge_name=name;
            temp->vertex1=v1;
            temp->vertex2=v2;
            temp->next=head;
            head = temp;
        }
    }
    void delete_edge(string name)
    {
        if(head==NULL)
        {

        }
        else
        {
            node * temp=head;
            node * temp2=head;
            while(temp->edge_name!=name)
            {
                temp2=temp;
                temp=temp->next;
                if(temp==NULL)
                {
                    break;
                }
            }
            if(temp==NULL)
            {

            }
            else if(temp==head)
            {
                head=head->next;
                delete temp;
            }
            else
            {
                temp2->next=temp->next;
                delelte temp;
            }
        }
    }
    void print()
    {
        node * temp=head;
        while(temp!=NULL)
        {
            cout<<temp->edge_name<<" joins "<<temp->vertex1<<" and "<<temp->vertex2<<endl;
            temp=temp->next;
        }
    }
    void delete_vertex(int v)
    {
        node * temp=head;
        while(temp!=NULL)
        {
            if(temp->vertex1=v||temp->vertex2=v)
            {
                delete_edge(temp->edge_name);
            }
        }

    }

};
int main()
{
    int n;
    cout<<"how many vertices u want ?";
    cin>>n;

}
