#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
class node
{
    public:
    int data;
    node * left=NULL;
    node * right=NULL;
};


node * insert(int d,node * root)
{
    if(root==NULL)
    {
        root=new node;
        root->data=d;
        return root;
    }
    else
    {
        if(root->data>=d)
        {
            root->left=insert(d,root->left);
        }
        else{
            root->right=insert(d,root->right);
        }
        return root;

    }
}

void display(node * root)
{
    if(root==NULL)
    {
       
    }
    else
    {
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}
int numberofchild(node * root)
{
    int counter=0;
    if(root->left!=NULL)counter++;
    if(root->right!=NULL)counter++;
    return counter;
}
node * del(node * root,int d)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(root->data==d)
        {
            int noc=numberofchild(root);
            if (noc==0)
            {
                delete root;
                return NULL;
            }
            else if(noc==1)
            {
                if(root->left==NULL)
                {
                    return root->right;
                }
                else
                {
                    return root->left;
                }
            }
            else
            {
                node * temp=root->left;
                node * temp2=root;
                while(temp->right!=NULL)
                {
                    temp2=temp;
                    temp=temp->right;
                }
                int x=temp->data;
                root->data=x;
                temp2->right=NULL;
                delete temp;
                return root;

            }
        }
        else if (root->data>d)
        {
            root->left=del(root->left,d);
            return root;
        }
        else
        {
            root->right=del(root->right,d);
            return root;
        }
    }
}

void bfs(node * root)
{
    if(root==NULL)
    {
        cout<<"nothin' to be printed"<<endl;
    }
    else
    {
        queue <node *> q;
        q.push(root);
        while(!q.empty())
        {
            node * temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
            cout<<temp->data<<" ";
            q.push(temp->left);
            q.push(temp->right);
            }


        }
        
    }
}

int height(node * root)
{
    if(root==NULL)
    {
        return -1;

    }
    else
    {
        return 1+max(height(root->left),height(root->right));
    }
}
void arr(int *a,int n,node * root)
{
    // ht=height(root);
    if(root==NULL)
    {
        cout<<"nothin' to be added"<<endl;
    }
    else
    {
        int i=0;
        queue <node *> q;
        q.push(root);
        while(!q.empty()&&i<n)
        {
            node * temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
            cout<<temp->data<<" ";
            a[i]=temp->data;
            q.push(temp->left);
            q.push(temp->right);
            }
            else{a[i]=0;}
            i++;


        }
        
        
    }


}

int main()
{
    // cout<<pow(2,3); 
    char a;
    node * root=NULL;
    while(1)
    {
        int element;
        cout<<"enter the element:";
        cin>>element;
        root=insert(element,root);

        cout<<"do you want to continue?(y/n) : ";
        cin>>a;
        if(a=='n')
        {
            break;
        }

    }
    cout<<"display:";
    bfs(root);
    while(1)
    {
        int element;
        cout<<"enter the element to be deleted:";
        cin>>element;
        root=del(root,element);

       cout<<"display:";
        bfs(root);
        cout<<"height :";
        cout<<height(root);
        cout<<"do you want to continue?(y/n) : ";
        cin>>a;
        if(a=='n')
        {
            break;
        }

    }
    int x=(pow(2,height(root)+1)-1);
    int *ar=new int[x];
    arr(ar,(pow(2,height(root)+1)-1),root);
    for(int i=0;i<x;i++)
        {
            cout<<ar[i]<<" "<<endl;
        }



}