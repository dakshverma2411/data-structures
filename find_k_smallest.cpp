#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int *a ,int l,int r) // moves the last element to its correct position and return the index 
{
    int x=a[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(a[j]<x)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}
int partition_(int *a,int l,int r)
{
    int x=a[r];
    int count=0;
    for(int j=l;j<r;j++)
    {
        if(a[j]<x)
        {
            swap(&a[j],&a[j-count]);
        }
        else count++;

    }
    swap(&a[r-count],&a[r]);
    return r-count;
}
int find_k_smallest(int *a,int l,int r,int k)
{
    if(l<=r)
    {
        int p=partition(a,l,r);/* p is partitioning index, a[p] is now
           at right place */
        if(p==k-1)
        {
            return a[p];
        }
        if(p>k-1)
        {
            return find_k_smallest(a,l,p-1,k);
        }
        else
        {
            return find_k_smallest(a,p+1,r,k);
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    int a[7];
    for(int i=0;i<7;i++)
    {
        cin>>a[i];
    }
    while(1)
    {
    int k;
    cin>>k;

    cout<<find_k_smallest(a,0,6,k)<<endl;
    }
}