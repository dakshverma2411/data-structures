#include<iostream>

using namespace std;
int main()
{
    int n,x,y;
    cin>>n;
    int a[n+1];
    a[n]=1;
    cin>>x;
    int min=x;
    cin>>y;
    if(y<min)min=y;
    bool zeropresent=false;
    bool zeroprev=false;
    int count=0;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        int x;
        x=int(s[i])-48;
        cout<<x<<endl;
        if(x==1)
        {
            if(zeroprev==true)
            {
                count++;
            }
            zeroprev=false;
        }
        else
        {
            zeropresent=true;
            zeroprev=true;
        }
    }
    
    

    if(zeroprev==true)count++;
    cout<<count<<endl;
    if(zeropresent==false)
    {
        cout<<0;
    }
    else
    {
        cout<<y+(count-1)*min;
    }
    
}