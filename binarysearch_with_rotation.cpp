#include<iostream>
using namespace std;
int findpivot(int *a,int l,int r) // pivot is the point next of which element is smaller than it eg. 7 8 9 1 2 3--->9 is the pivot
{
    // l=6,r=6,m=6
    // 8 8 8 8 8 8 8
    if(l<=r)
    {
    int m=l+(r-l)/2;
    if(a[l]<a[r])
    {
        return -1;
    }
    else if(m<r && a[m]>a[m+1])//m is the pivot
    {
        return m;
    }
    else if(m>l && a[m-1]>a[m]) //m-1 is the pivot
    {
        return m-1;
    }
    else if(a[l]>a[m]) //pivot is in the left subarray
    {
        return findpivot(a,l,m-1);
    }
    else //pivot is in the right subarray
    {
        return findpivot(a,m+1,r);
    }
    }
    else // already sorted fine 
    {
        return -1;
    }
}
int binarysearch(int *a,int l,int r,int key)
{
    if(l>r)
    {
        return -1;
    }
    else
    {
        int m=l+(r-l)/2;
        if(a[m]==key)
        {
            return m;
        }
        else if(a[m]>key)
        {
            return binarysearch(a,l,m-1,key);
        }
        else
        {
            return binarysearch(a,m+1,r,key);
        }
    }
}
int pivotbinarysearch(int *a,int l,int r,int key)
{
    int p=findpivot(a,l,r);
    if(p!=-1)
    {
    if(a[p]==key)
    {
        return p;
    }
    else if(a[0]>key)
    {
        return binarysearch(a,p+1,r,key);
    }
    else
    {
        return binarysearch(a,l,p,key);
    }
    }
    else 
    {
        return binarysearch(a,l,r,key);
    }
}
int main()
{
    int a[7]={8,8,8,8,8,8,8};
    cout<<pivotbinarysearch(a,0,6,8);
}