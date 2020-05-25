#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    unsigned int n;
    cin>>n; //consider a 16 bit number
    n++;
    unsigned sum=0;
    for(int i=0;i<16;i++)
    {
        int p=pow(2,i+1);
        sum+=(n/p)*pow(2,i);
        int x=(n%p)-pow(2,i);
        if(x<=0)
        {
            // cout<<"added:"<<n/p<<endl;
        }
        else
        {
            sum+=x;
            // cout<<"added:"<<n/p+x<<endl;
        }
        

    }
    cout<<sum;
}