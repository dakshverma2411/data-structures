#include<bits/stdc++.h>
using namespace std;
// if we give a array that represent the preorder traversal then
// we have to tell whether such bst is possible or not


// ex 40 30 20 25 35 80 70 75 100 90   
// one basic property is that if a number y is bigger than x(x is somewhere on left of y)
// the all the number after y is bigger than x
// here after 80 all the number are greater than 40

bool can representstd(int *pre ,int n)
{
    root=INT_MIN;
    stack <int> s;
    for(int i=0;i<n;i++)
    {
        if(pre[i]<root)
        {
            return false;
        }
        while(!s.empty() && s.top()<pre[i])
        {
            root=s.top();
            s.pop();
        }
        
            s.push(pre[i]);
        
    }
    return true;

}