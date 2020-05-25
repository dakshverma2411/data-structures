#include<iostream>
using namespace std;
void quick_sort(long long int[],int,int);
int partition(long long int[],int,int);
int main()
{
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        long long int x;
        cin>>x;
        a[i]=a[i]-x;
    }
    int count=0;
    quick_sort(a,0,n-1);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<=0)
        {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>-a[j])
            {
                count+=n-j;
                break;
            }
        }
        }
        else
        {
             int y=n-1-i;
            int s=(y*(y+1))/2;
            count+=s;
            break;
        }
    }
    cout<<count;
}
void quick_sort(long long int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition(long long int a[],int l,int u)
{
    long long int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
        do
        {
            i++;
        }while(a[i]<v&&i<=u);
        do
        {
            j--;
        }
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    a[l]=a[j];
    a[j]=v;
    return(j);

    }

