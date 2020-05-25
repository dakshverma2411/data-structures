#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class vertex
{
    public:
    // int key; key is not needed since array (VERTICES)index represent keys
    vector <int> out;
    vector <int> in;
};
class edge
{
    public:
    vertex* vertex1;
    vertex* vertex2;
    int cost;
    edge * next;
};
class modern_adj_list
{
    public:
    edge * head=NULL;
    int n;
    vertex* * VERTICES; //v is a array of pointers to vertex where index of array (v) represent key of vertex
    modern_adj_list()
    {
        cout<<"enter the number of vertices:";
        cin>>n;
        VERTICES=new vertex*[n];
    }
    void add_edge(int v1,int v2,int c=1)
    {
        if(head==NULL)
        {
            head=new edge;
            head->vertex1=VERTICES[v1];
            head->vertex2=VERTICES[v2];
            head->cost=c;
            head->next=NULL;
        }
        else
        {
            edge * temp=new edge;
            temp->vertex1=VERTICES[v1];
            temp->vertex2=VERTICES[v2];
            temp->cost=c;
            temp->next=head;
            head=temp;
        }
        VERTICES[v1]->out.push_back(v2);
        VERTICES[v2]->in.push_back(v1);
    }

    

};
int main()
{
    vertex * * v;
    v=new vertex*[5];
}
