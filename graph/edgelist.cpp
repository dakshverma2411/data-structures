#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class vertex
{
    public:

    int vertex1;
    int vertex2;
    vertex * next;
    string edgename;
    vertex(int a,int b)
    {
        vertex1=a;
        vertex2=b;
    }
}
class edgelist
{
    public:
    int n;
    vertex * head=NULL;
    edgelist()
    {
        cout<<"enter the number of vertices:";
        cin>>n;
        
    }
    void addedge(int v1,int v2,string a)
    {
        if(head==NULL)
        {
            head=new vertex(v1,v2);
            head->next=NULL;
            head->edgename=a;
        }
        else
        {
            vertex* temp=new vertex(v1,v2);
            temp->next=head;
            temp->edgename=a;
            head=temp;
        }
    }
    void deleteedge(int v1,int v2)
    {
        if(head==NULL)
        {
            cout<<"no such edge\n";
        }
        else
        {
            vertex* temp1=head;
            vertex * temp2=head;
            while(temp1!=NULL)
            {
                if((temp1->vertex1==v1 && temp1->vertex2==v2) ||(temp1->vertex1==v2 && temp1->vertex2==v1))
                {
                    break;
                }
                temp2=temp1;
                temp1=temp1->next;
            }
            if(temp1==head)
            {
                head=temp1->next;
                cout<<"deleted "<<temp1->edgename<<endl;
                delete temp1;
            }
            else
            {
                temp2->next=temp1->next;
                cout<<"deleted "<<temp1->edgename<<endl;
                delete temp1;
            }
        }
    }

    void find_vertices(string name,int &v1,int &v2)
    {
        if(head==NULL)
        {
            v1=-1;
            v2=-1;
        }
        else
        {
            vertex * temp=head;
            while(temp!=NULL)
            {
                if(temp->edgename==name)
                {
                    break;
                }
            }
            v1=temp->vertex1;
            v2=temp->vertex2;
        }
    }

    int count_edges(int v1)
    {
        int count=0;
        if(head==NULL)
        {

        }
        else
        {
            vertex* temp=head;
            while(temp!=NULL)
            {
                if(temp->vertex1==v1 || temp->vertex2==v1)
                {
                    count++;
                }
                temp=temp->next;
            }
        }
        return count;
    }


};