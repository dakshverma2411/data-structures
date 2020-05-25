#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class vertex
{
    public:
    // string vertex_name;
    int data;
    vector <int> list;



};
class adjacency_list
{
    public:
    vector <vertex * > v;
    void add_vertex(int d)
    {
        vertex * temp=new vertex;
        temp->data=d;
        v.push_back(temp);
        
    }
    void add_edge(int a,int b)
    {
        int i;
        for(i=0;i<v.size();i++)
        {
            if(v[i]->data==a)
            {
                break;
            }
        }
        v[i]->list.push_back(b);


        // int i;
        for(i=0;i<v.size();i++)
        {
            if(v[i]->data==b)
            {
                break;
            }
        }
        v[i]->list.push_back(a);
        
    }
    void delete_edge(int a,int b)
    {
        int i;
        for(i=0;i<v.size();i++)
        {
            if(v[i]->data==a)
            {
                break;
            }
        }
        vector <int> ::iterator iter;
        iter=find(v[i]->list.begin(),v[i]->list.end(),b);
        v[i]->list.erase(iter);


        // int i;
        for(i=0;i<v.size();i++)
        {
            if(v[i]->data==b)
            {
                break;
            }
        }
        vector <int> ::iterator iter;
        iter=find(v[i]->list.begin(),v[i]->list.end(),a);
        v[i]->list.erase(iter);
        

    }
    void print()
    {
        int i;
        for(i=0;i<v.size();i++)
        {
            int d=v[i]->data;
            int s=v[i]->list.size();
            cout<<d<<" is adjacent to ";
            for(int j=0;j<s;j++)
            {
                cout<<v[i]->list[j]<<" ";
            }
            cout<<endl;
        }
    }
    
};
int main()
{
    cout<<"starting...\n";
    adjacency_list obj;
    obj.add_vertex(0);
    obj.add_vertex(1);
    obj.add_vertex(2);
    obj.add_vertex(3);
    obj.add_edge(0,1);
    obj.add_edge(2,1);
    obj.add_edge(2,3);
// int a=1;
// int b=2;
// int c=3;
// vector <int * > v;
// v.push_back(&a);
    obj.print();
    

}