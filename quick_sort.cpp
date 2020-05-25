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
void quicksort(int *a,int l,int r)
{
    if(l<=r)
    {
        int p=partition_(a,l,r);/* p is partitioning index, a[p] is now
           at right place */
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}
int main()
{
    int a[7];
    for(int i=0;i<7;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,6);
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }
}