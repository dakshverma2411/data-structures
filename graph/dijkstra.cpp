#include<iostream>
using namespace std;
class graph{
    public:
    int n;
    int * * ptr;
    graph(int N)
    {
        n=N;
        ptr=new int*[n];
        for(int i=0;i<n;i++)
        {
            ptr[i]=new int[n];
        }
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ptr[i][j]=0;
            }
           
        }
    }
    void add_edge(int v1,int v2,int cost=1)
    {
        ptr[v1][v2]=cost;
    }
    int findmin(int * dist,bool * confirmed) //returns the vertex with minimum label(dist) and is unreached(confirmed ==false)
    {
        int min=INT_MAX,min_index=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<=min && confirmed[i]==false)
            {
                min=dist[i];
                min_index=i;
            }
        }
        return min_index;
    }
    void printgraph()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void printSolution(int dist[]) 
    { 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < n; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
    } 
    void dijkstra(int src)
    {
        int dist[n];
        bool confirmed[n];
        
        for(int j=0;j<n;j++)
        {
            confirmed[j]=false;
            dist[j]=INT_MAX;
        }
        
        dist[src]=0;
        
        for(int i=0;i<n;i++)
        {
            int u=findmin(dist,confirmed);
            confirmed[u]=true;
            for(int j=0;j<n;j++)
            {
                if(!confirmed[j]&&ptr[u][j]!=0 && dist[u]+ptr[u][j]<dist[j])
                {
                    dist[j]=dist[u]+ptr[u][j];
                }
            }
        }
        printSolution(dist);
    }
    

};
int main()
{
    int a=0,b=1,c=2,d=3,e=4;
    graph obj(5);
    // obj.printgraph();
    obj.add_edge(a,b,10);
    obj.add_edge(a,c,3);
    obj.add_edge(b,c,1);
    obj.add_edge(c,b,4);
    obj.add_edge(b,d,2);
    obj.add_edge(c,e,2);
    obj.add_edge(c,d,8);
    obj.add_edge(d,e,7);
    obj.add_edge(e,d,9);
    // obj.printgraph();
    obj.dijkstra(a);

}