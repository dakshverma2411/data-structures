// we use MAX heap here
#include<iostream>
using namespace std;
void swap(int * x,int * y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
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
void heapsort(int *a,int n) // n is the total numbers of elements in the array
{
    // first we need to create a heap from the given array(or tree)
    for(int i=n/2-1;i<=0;i--)  //n/2-1 is the index of array of which children are there
    {
        heapify(a,i,n);
    }
    // now we have a array that represent a heap
    // we place the first element at last and heapify again at index=0
    int k=n-1;
    while(k>0)
    {
        swap(&a[0],&a[k]);
        heapify(a,0,k);
        k--;
    }

}
int main()
{

}