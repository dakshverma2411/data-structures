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
    adjacencylist()
    {
        cout<<"enter the number of vertices:";
        cin>>n;
        ptr=new vector <int> [n];
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
    int * bfs(int v)
    {
        for(int i=0;i<n;i++)
        {
            p[i]=INT_MAX;
        }
        // int count=0;
        int * p=new int[n];
        deque <int> dq;
        dq.push_back(v);
        p[v]=0;
        while(!dq.empty())
        {
            int x=dq.front();
            dq.pop_front();

            for(int i=0;i<ptr[x].size();i++)
            {
                int y=ptr[x][i];
                if(p[y]==INT_MAX)
                {
                    dq.push_back(y);
                    p[y]=p[x]+1;
                }
            }
            count++;
        }

    }

}
int main()
{
    vector <int> * ptr;
    ptr=new vector <int> [5];
    ptr[0].push_back(2);
    cout<<ptr[0].size();
}