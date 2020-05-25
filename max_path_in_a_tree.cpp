#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node * left=NULL;
    node * right=NULL;
};
int max(int a,int b);
{
    if(a<b){return a;}
    return b;
}
int findmaxpath(node * root,int &res) // res stands for result
{
    //if NULL return 0
    if(root==NULL)
    {
        return 0;
    }
    //if leaf node return the data;
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    //if non leaf node
    int l=findmaxpath(root->left);
    int r=findmaxpath(root->right);
    // Max path for parent call of root. This path must 
    // include at-most one child of root 
    int max_single=max(root->data,root->data+max(l,r));
    // Max Top represents the sum when the Node under 
    // consideration is the root of the maxsum path and no 
    // ancestors of root are there in max sum path 
    int max_top=max(max_single,root->data+l+r);
    res =max(res,max_top); // Store the Maximum Result.
    return max_single;
}
int findMaxSum(Node *root) 
{ 
    // Initialize result 
    int res = INT_MIN; 
  
    // Compute and return result 
    findMaxUtil(root, res); 
    return res; 
} 