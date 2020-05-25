#include<iostream>
using namespace std;

void merge(int *a,int l,int m,int h)
{
    int n1=m-l+1;
    int n2=h-m;
    // create two sub array (temp)
    int a1[n1];
    int a2[n2];
    // divide main array into two array a1 and a2(partitioning at m)
    for(int i=0;i<n1;i++)
    {
        a1[i]=a[i+l];
    }
    for(int i=0;i<n2;i++)
    {
        a2[i]=a[m+1+i];
    }
    int i=0;int j=0;
    int k=l;
    //shift elements by comparing each time in main array
    while(i<n1&& j<n2)
    {
        if(a1[i]<a2[j])
        {
            a[k]=a1[i];
            i++;
        }
        else
        {
            a[k]=a2[j];
            j++;

        }
        k++;
    }

    // now enter remaining elements
    while(i<n1)
    {
        a[k]=a1[i];
        i++;k++;
    }
    while(j<n2)
    {
        a[k]=a2[j];
        k++;
        j++;
    }
}

void mergesort(int *a,int l,int h)
{
    if(l<h) // call until 1 element is arrived
    {
        int m=l+(h-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }

}
int main()
{
    int a[5]={7,6,5,5,4};
    mergesort(a,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
}