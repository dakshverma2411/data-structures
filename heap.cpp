// THIS IS A MAX HEAP
#include<iostream>
using namespace std;
void swap(int * x,int * y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void insert(int *a,int i,int key)
{
    a[i]=key;
    int parent=(i-1)/2;
    while(a[parent]<a[i])
    {
        swap(&a[parent],&a[i]);
        i=parent;
        parent=(i-1)/2;
    }

}
void heapify(int *a, int i,int n) // n i the total number if elements 
{
    int c1=2*i+1;
    int c2=2*i+2;
    int largest=i;
    if(c1<n && a[c1]>a[largest])
    {
        largest=c1;
    }
    if(c2<n && a[c2]>a[largest])
    {
        largest=c2;
    }
    // largest now have the maximum of parent and 2 children
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,largest,n);
    }

}

void del_root(int *a,int &n)
{
    swap(a[0],a[n-1]);
    a[n-1]=0;
    n--;
    heapify(a,0,n);
}
int main()
{
    int a[7]={0,0,0,0,0,0,0};
    int noe=0;
    while(1)
    {
        int x;
        cout<<"enter 1 for insert and 2 for deletion";
        cin>>x;
        if(x==1)
        {
            int element;
            cin>>element;
            insert(a,noe,element);
            noe++;
            cout<<"noe:"<<noe<<endl;
            cout<<"heap:";
            for(int i=0;i<noe;i++)
            {
                
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            del_root(a,noe);
            cout<<"heap:";
            for(int i=0;i<noe;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;

        }
    }
}