#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <int> * p=new vector <int>[5];
    // p[0]=new vector <int> ;
    p[0].push_back(2);
    cout<<p[0].size();

}