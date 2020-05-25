#include<iostream>
using namespace std;
void bs(int *a ,int start,int end,int element)
{
    if(start>end)
    {
        cout<<"-1";
        return;
    }
    else 
    {
        int middle=(start+end)/2;
        if(a[middle]==element)
        {
            cout<<middle;
        }
        else if(a[middle]>element)
        { 
            bs(a,start,middle-1,element);
        }
        else
        {
            bs(a,middle+1,end,element);
        }
    }

}

int main()
{
    int a[7]={1,2,3,4,5,6,7};
    bs(a,0,6,7);
}