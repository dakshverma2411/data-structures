#include<iostream>
using namespace std;
int main()
{
    int p[5];
    int r[5];
    for(int i=0;i<5;i++)
    {
        cin>>p[i];

    }
    int ntbr=0;
    for(int i=0;i<5;i++)
    {
        int y;
        cin>>y;
        r[i]=y;
        for(int j=0;j<5;j++)
        {
            if(p[j]%y==0)ntbr++;
        }
    }
    cout<<ntbr;
    
}