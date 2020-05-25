#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,q;
		cin>>n>>m>>q;
		int pages[n+1]={0};
		
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
		
		for(int i=0;i<q;i++)
		{
			int x=r[i];
			for(int j=1;j<n+1;j++)
			{
				if(j%x==0)pages[j]++;
			}
		}
		for(int i=0;i<m;i++)
		{
			pages[p[i]]=0;
		}
		
		int sum=0;
		for(int i=1;i<n+1;i++)
		{
            if(pages[i]>0)
            {
			sum+=pages[i];
            }
		}
		cout<<sum<<endl;
	}
}