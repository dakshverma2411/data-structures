#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void insertion_sort(vector <int> &v)
{
    int size=v.size();
    for(int i=1;i<size;i++)
    {
        int x=v[i];
        int j=i;
        while(j>0)
        {
            if(v[j]<v[j-1])
            {
                v[j]=v[j-1];
                v[j-1]=x;
                j--;
            }
            else
            {
                break;
            }
        }
        v[j]=x;

    }
}
void bucket_sort(int * arr,int n,int m,int largest,int smallest=0)
{
    vector <int>  * v =new vector <int>[m];
    int range;   // range is the number of ele
    if((largest-smallest+1)%m==0)
    {
        // cout<<'a'<<endl;
        range=(largest-smallest+1)/m;
    }
    else
    {
        range=(largest-smallest+1)/m+1;
    }
    cout<<"range"<<range<<endl;
    for(int i=0;i<n;i++)
    {
        int bucket_number=0;
        int x=arr[i]-smallest+1;
        if(x%range==0)
        {
            bucket_number=x/range-1;
        }
        else
        {
            bucket_number=x/range;
        }
        v[bucket_number].push_back(arr[i]);
        
    }
    for(int i=0;i<m;i++)
    {
       sort(v[i].begin(),v[i].end());
    //    insertion_sort(v[i]);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
    }


}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int largest;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int smallest;
    cin>>smallest;
    cin>>largest;
    int m;
    cin>>m;
    bucket_sort(arr,n,m,largest,smallest);


}