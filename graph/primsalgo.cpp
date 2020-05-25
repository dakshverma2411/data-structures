#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class edge
{
    public:
    int vertex1;
    int vertex2;
    int weight;
};
class vertex
{
    public:
    list <edge *> adjacent;
};
class heap
{
    public:
    edge * * p; // p will be an array that stores pointers to edges in heap
    int last_index=-1;  //follows the last element in heap array
    heap(int m)
    {
        p=new edge * [m];
        for(int i=0;i<m;i++)
        {
            p[i]=NULL;
        }

    }
    void swap(edge * * a,edge * * b)
    {
        edge * temp=* a;
        *a =*b;
        *b=temp;

    }
    void insert(edge * e)
    {
        last_index++;
        p[last_index]=e;
        int j=last_index;
        int i=(j-1)/2;
        while(i>=0)
        {
            if(p[i]->weight>p[j]->weight)
            {
                swap(&p[i],&p[j]);

                j=i;
                i=(j-1)/2;
            }
            else
            {
                break;
            }
        }

    }
    void heapify(int i)
    {
        int j1,j2;
        j1=2*i+1;
        j2=2*i+2;
        if(j1>last_index && j2 > last_index)
        {

        }
        else
        {
            if(j1<=last_index && j2<=last_index)
            {
                int min_of_children=p[j1]->weight;
                int index_of_min_of_children=j1;
                if(p[j2]->weight<min_of_children)
                {
                    min_of_children=p[j2]->weight;
                    index_of_min_of_children=j2;

                }
                // now index_of_min_of_children has the index of min weighted children
                // min_of_children holds the weight of min weight among children of i;
                if(p[i]->weight>min_of_children)
                {
                    swap(&p[i],&p[index_of_min_of_children]);
                    heapify(index_of_min_of_children); //calling recursively
                }
                
            }
            else if(j1<=last_index)
            {
                //j1 is the last element in heap;
                if(p[i]->weight>p[j1]->weight)
                {
                    swap(&p[i],&p[j1]);
                }
            }
            
        }
    }
    edge * deletemin()
    {
        edge * temp=p[0];
        swap(&p[0],&p[last_index]);
        last_index--;
        if(last_index!=-1)
        {
        heapify(0);
        }
        // cout<<"last index of heap:"<<last_index<<endl;
        
        return temp;
    }
    bool isempty()
    {
        if(last_index==-1)
        {
            return true;
        }
        return false;
    }
    void printheap()
    {
        for(int i=0;i<=last_index;i++)
        {
            cout<<p[i]->weight<<" ";
        }
    }


};
class graph   // we use adjacency list here
{
    public:
    int N;
    vertex * * ptr;    // created a pointer to array whose indexes represent the vertex and values points to corresponding vertex
    edge * * spanning_tree_edges;
    graph(int n)
    {
        N=n;
        ptr=new vertex * [N]; //create a array pointed by ptr
        spanning_tree_edges=new edge*[N-1];
        for(int i=0;i<N;i++)
        {
            ptr[i]=new vertex;
        }
    }
    void add_edge(int v1,int v2,int w)
    {
        edge * temp=new edge;  // create a new edge 
        temp->vertex1=v1;
        temp->vertex2=v2;
        temp->weight=w;
        ptr[v1]->adjacent.push_back(temp); //adding the created edge in adjacency list of two vertices
        ptr[v2]->adjacent.push_back(temp);
    }
    int find_other_vertex(edge * p,int v)
    {
        // cout<<(*p).weight<<endl;
        
        if(p->vertex1==v)
        {
            // cout<<"here"<<endl;
            return p->vertex2;
        }
        // cout<<"here"<<endl;
        return p->vertex1;
    }
    edge * * primsalgo(int start)
    {
        int confirmed[N]={0};
        int count=0;
        heap H((N*(N-1))/2);
        list <edge *> ::iterator i=ptr[start]->adjacent.begin();
        while(i!=ptr[start]->adjacent.end())
        {
            H.insert(*i);
            i++;
        }
        H.printheap();cout<<endl;
        confirmed[start]=1;
        while(!H.isempty())
        {
            edge * minimun_weighted=H.deletemin();
            int a1=minimun_weighted->vertex1;
            int a2=minimun_weighted->vertex2;
            int x; //to store the unreached vertex out of a1 and a2
            if(confirmed[a1]==1 && confirmed[a2]==1)
            {
                continue;
            }
            else if(confirmed[a1]==0)
            {
                // a1 vertex is not in spanning tree
                x=a1;
                
            }
            else
            {
                // a2 is not in spanning tree
                x=a2;
            }
            spanning_tree_edges[count++]=minimun_weighted;
            confirmed[x]=1;
            list <edge *> ::iterator iter=ptr[x]->adjacent.begin();
            while(iter!=ptr[x]->adjacent.end())
            {
                // *iter is pointer to edge object
                edge * temp=*iter;
                int y=find_other_vertex(temp,x);
                if(confirmed[y]==0)
                {
                    H.insert(temp);
                }
                iter++;
            }


        }
        return spanning_tree_edges;
    }
    void print()
    {
        for(int i=0;i<N;i++)
        {
            cout<<i<<"->";
            list <edge *> ::iterator iter=ptr[i]->adjacent.begin();
            while(iter!=ptr[i]->adjacent.end())
            {
                edge * temp=*iter;
                if(temp->vertex1==i)
                {
                    cout<<temp->vertex2<<" ";
                }
                else
                {
                    cout<<temp->vertex1<<" ";
                }
                iter++;
            }
            cout<<endl;
        }
    }

};
int main()
{
    int a=0,b=1,c=2,d=3,e=4;
    graph G(5);
    G.add_edge(a,b,15);
    G.add_edge(b,e,20);
    G.add_edge(e,c,10);
    G.add_edge(c,d,5);
    G.add_edge(d,a,5);
    G.add_edge(a,e,30);
    G.add_edge(a,c,10);
    G.add_edge(b,c,15);
    G.print();
    edge * * mst=G.primsalgo(e);
    for(int i=0;i<4;i++)
    {
        cout<<mst[i]->weight<<" ";
    }



    // edge e1;
    // e1.weight=70;
    // edge e2;
    // e2.weight=30;
    // edge e3;
    // e3.weight=20;
    // edge e4;
    // e4.weight=40;
    // edge e5;
    // e5.weight=50;
    // edge e6;
    // e6.weight=60;
    // heap H(10);
    // H.insert(&e1);
    // H.insert(&e2);
    // H.insert(&e3);
    // H.insert(&e4);
    // H.insert(&e5);
    // H.insert(&e6);
    // H.printheap();cout<<endl;
    // edge * temp;
    
    
    // while(!H.isempty())
    // {
    //     temp=H.deletemin();
    // H.printheap();cout<<endl;
    // }



}
