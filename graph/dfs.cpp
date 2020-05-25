#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
class adjacencylist
{
    public:
    vector <int> * ptr;
    int n;
    int *p;
    adjacencylist()
    {
        cout<<"enter the number of vertices:";
        cin>>n;
        ptr=new vector <int> [n];
        p=new int[n];
        
    }
    void add_edge(int v1,int v2)
    {
        if(v1<n && v2<n)
        {
        ptr[v1].push_back(v2);
        ptr[v2].push_back(v1);
        }
    }
    int countedges(int v1)
    {
        return ptr[v1].size();
    }
    void dfs(int v)
    {
        for(int i=0;i<n;i++)
        {
            p[i]=0;
        }
        p[v]=1;
        dfs1(p,v);
        // return p;
    }
    void dfs1(int * p,int v)
    {
        // cout<<"here";
        cout<<v<<" ";
        for(int i=0;i<ptr[v].size();i++)
        {
            // cout<<"here1";
            if(p[ptr[v][i]]==1)
            {

            }
            else
            {
                p[ptr[v][i]]=1;
                dfs1(p,ptr[v][i]);
            }
        }
    }

};
int main()
{
    int a=0,b=1,c=2,d=3,e=4,f=5;
    adjacencylist obj;
    obj.add_edge(a,b);
    obj.add_edge(b,e);
    obj.add_edge(e,c);
    obj.add_edge(c,d);
    obj.add_edge(e,f);
    obj.add_edge(e,d);
    obj.add_edge(a,d);
    obj.add_edge(a,c);

    
    obj.dfs(0);

}