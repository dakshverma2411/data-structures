#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,q;
		cin>>n;
		cin>>m;
		cin>>q;
		int p[m];
		int r[q];
		for(int i=0;i<m;i++)
		{
			cin>>p[i];
		}
		for(int i=0;i<q;i++)
		{
			cin>>r[i];
		}
		int sum=0;
		for(int i=0;i<q;i++)
		{
			sum=sum+n/r[i];
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<q;j++)
			{
				if(p[i]%r[j]==0)sum--;
			}
		}
		cout<<sum<<endl;
	}
}

