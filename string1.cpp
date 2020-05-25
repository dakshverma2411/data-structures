#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    long long int len=s.size();
    long long int count=0;
    long long int sum=0;
    // long long int prev=0;
    for(long long int i=0;i<len;i++)
    {
        if(s[i]=='a')
        {
            count++;
        }
        else
        {
            sum+=pow(2,count)-1;
        }
    }
    cout<<sum%1000000007;
}