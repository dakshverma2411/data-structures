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

int main()
{
    int a=0,b=1,c=2,d=3,e=4;
    unionfind uf(5);
    cout<<uf.is_connected(a,b);
    cout<<endl;
    uf.unionbyrank(a,b);uf.print();cout<<endl;
    uf.unionbyrank(b,c);uf.print();cout<<endl;
    uf.unionbyrank(e,d);uf.print();cout<<endl;
    uf.unionbyrank(d,b);uf.print();cout<<endl;
    uf.print();


}