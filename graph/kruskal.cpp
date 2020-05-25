#include<iostream>
using namespace std;
class unionfind
{
    public:
    int * ptr;
    int N;
    int * size;
    unionfind(int n)
    {
        N=n;
        ptr=new int[N];   
        for(int i=0;i<N;i++)  //inititlaising union find ..all values equal to index(N seperate connected components)
        {
            ptr[i]=i;
        }
        size=new int[N];
        for(int i=0;i<N;i++)  // setting size of each connected components to 1
        {
            size[i]=1;
        }
    }
    int find(int i)
    {
        while(ptr[i]!=i)
        {
            i=ptr[i];
        }
        return i;
    }
    int rank(int i)
    {
        while(ptr[i]!=i)
        {
            i=ptr[i];
        }
        // i is now the representative 
        return size[i];
    }
    void unionbyrank(int a,int b) // a and b are 2 verteces
    {
        int r1=find(a);
        int r2=find(b);
        if(rank(r1) > rank(r2))
        {
            ptr[r2]=r1;
            size[r1]+=size[r2];
        }
        else 
        {
            ptr[r1]=r2;
            size[r2]+=size[r1];
        }
    }
    bool is_connected(int a,int b)
    {
        int r1=find(a); //representative of a
        int r2=find(b); //representative of b
        if(r1==r2)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        for(int i=0;i<N;i++)
        {
            cout<<ptr[i]<<" ";
        }
        
    }

};
class edge
{
    public:
    int vertex1;
    int vertex2;
    int weight;
    edge * next;
};
class linklistif
{

};
class graph
{
    public:
    edge * head=NULL;
    int * spanning_tree;
    int N;
    graph(int n)
    {
        N=n;
        spanning_tree=new int[n-1];
    }
    void add_edge(int v1,int v2,int w)  //insert edge in ascending order on the basis of weight
    {
        if(head==NULL)
        {
            head=new edge;
            head->next=NULL;
            head->vertex1=v1;
            head->vertex2=v2;
            head->weight=w;
        }
        else
        {
            if(head->weight>w)
            {
                edge * temp=new edge;
                temp->vertex1=v1;
                temp->vertex2=v2;
                temp->weight=w;
                temp->next=head;
                head=temp;
            }
            else
            {
                edge * temp=head;
                while(temp->next!=NULL)
                {
                    if(temp->next->weight>w)
                    {
                        break;
                    }
                    else
                    {
                        temp=temp->next;
                    }
                }
                //edge is to be  inserted after temp
                edge * temp2=new edge;
                temp2->vertex1=v1;
                temp2->vertex2=v2;
                temp2->weight=w;
                temp2->next=temp->next;
                temp->next = temp2;
            }
        }
    }

    int * kruskal()
    {
        int count=0;
        unionfind uf(N);
        edge * temp=head;
        while(temp!=NULL)
        {
            int w=temp->weight;
            int v1=temp->vertex1;
            int v2=temp->vertex2;
            if(!uf.is_connected(v1,v2))
            {
                uf.unionbyrank(v1,v2);
                spanning_tree[count++]=w;
            }
            temp=temp->next;

        }
        return spanning_tree;

    }
    
};

int main()
{
    int a=0,b=1,c=2,d=3,e=4;
    graph G(5);
    int n=5;
    G.add_edge(a,b,15);
    G.add_edge(b,e,20);
    G.add_edge(e,c,10);
    G.add_edge(c,d,5);
    G.add_edge(d,a,5);
    G.add_edge(a,e,30);
    G.add_edge(a,c,10);
    G.add_edge(b,c,15);
    int * x=G.kruskal();
    for(int i=0;i<n-1;i++)
    {
        cout<<x[i]<<" ";
    }
    


}