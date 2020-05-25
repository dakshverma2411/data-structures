#include<iostream>
#include<vector>
#include<algorithm>
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

}
int main()
{
    vector <int> * ptr;
    ptr=new vector <int> [5];
    ptr[0].push_back(2);
    cout<<ptr[0].size();
}