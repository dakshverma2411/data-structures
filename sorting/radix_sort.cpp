#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
void radix_sort(int * arr,int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    cout<<"max:"<<max<<endl;
    int largest_length=log10(max)+1;
    queue <int> s[10];
    for(int i=1;i<=largest_length;i++)
    {
        int divisor=pow(10,i-1);
        
        for(int j=0;j<n;j++)
        {
            int x=arr[j]/divisor;
            s[(x%10)].push(arr[j]);
        }
        
        int k=0;
        for(int l=0;l<10;l++)
        {
            while(!s[l].empty())
            {
                arr[k++]=s[l].front();
                s[l].pop();
            }
        }
        for(int o=0;o<n;o++)
        {
            cout<<arr[o]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    radix_sort(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}