#include<iostream>
using namespace std;
class node
{
    public:
    int * key;
    node * * ptr;
    node(int m)
    {
        key=new int[m];
        for(int i=0;i<m;i++)
        {
            key[i]=-1;
        }
        ptr = new node * [m];
        for(int i=0;i<m;i++)
        {
            ptr[i]=NULL;
        }
        
    }
};
bool isleaf(node * root)
{
    if(root->ptr[0]==NULL)
        {
            // leaf node
            return true;
        }
        else
        {
            // non leaf node
            return false;
        }
}
bool isfull(node * root,int m)
{
    if(root->key[m-1]==-1)
    {
        return false;
    }
    return true;
}
node * insert(int data,node * root,int m)
{
    if(root==NULL)
    {
        root=new node(m);
        root->key[0]=data;
        return root;
    }
    else
    {
        if(isleaf(root))
        {
            // leaf node
            if(isfull(root,m))
            {
                int i;
            }
            else
            {
                int i;
                for(i=0;i<m;i++)
                {
                    if(root->key[i]==-1||root->key[i]>data)
                    {
                        break;
                    }
                    if(root->key[i]==-1)
                    {
                        root->key[i]=data;
                    }
                    else
                    {
                        int d=root->key[i];
                        root->key[i]=data;
                        root=insert(d,root,m);
                    }
                }
            }

        }
        else
        {
            // non leaf node
            for(int i=0;i<m;i++)
            {
                if(root->key[i]>data||root->key[i]==-1)
                {
                    break;
                }
            }
            root->ptr[i]=insert(data,root->ptr[i],m);
        }
        
    }
}

int main()
{
    // int * * ptr;
    // ptr=new int *[10];
}