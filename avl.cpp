#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    int height=0;
    node* left=NULL;
    node* right=NULL;


};
node * insert(int d,node * root)
{
    if(root == NULL)
    {   
        root=new node;
        root->data=d;
        return root;
    }
    else
    {
        if(root->data>d)
        {
            root->left=insert(d,root->left);
        }
        else
        {
            root->right=insert(d,root->right);
        }
        root->height=1+max(heightfun(root->left),heightfun(root->right));

        if(balancefactor(root)>1 || balancefactor(root)<-1)
        {
            if(balancefactor==2)
            {
                // left case
                if(d<root->left->data)
                {
                    // left left case
                    root=rightrotation(root);

                }
                else
                {
                    // left right case
                    root->left=leftrotation(root->left);
                    root=rightrotation(root);
                }
            }
            else
            {
                // right case
                if(d<root->right->data)
                {
                    // right left case
                    root->right=rightrotation(root->right);
                    root=leftrotation(root);

                }
                else
                {
                    // right right case
                    root=leftrotation(root);
                }
            }
        }
        return root;

    }
   
}
node * rightrotation(node * root)
{
    node * z=root;
    node * y=root->left;
    node * x=y->right;
    y->right=z;
    z->left=x;
    z->height=1+max(heightfun(z->left),heightfun(z->right));
    y->height=1+max(heightfun(y->left),heigtfun(y->right));
    return y;
}
node * leftrotation(node * root)
{
    node * z=root;
    node * y=root->right;
    node * x=y->left;
    y->left=z;
    z->right=x;
    z->height=1+max(heightfun(z->left),heightfun(z->right));
    y->height=1+max(heightfun(y->left),heigtfun(y->right));
    return y;

}
int heightfun(node * t)
{
    if(t==NULL)
    {
        return -1;
    }
    return t->height;
}
int max(int a,int b)
{
    if(a>b)
    {
        return a;

    }
    else return b;
}
int balancefactor(node * t)
{
    return heightfun(t->left)-heightfun(t->right);
}
void display_in_order(node * root)
{
    if(root==NULL)
    {
        // does nothing
    }
    else
    {
        display_in_order(root->left);
        cout<<root->data<<" ";
        display_in_order(root->right);
    }
}
node * del(int d,node * root)
{
    if(root==NULL)
    {
        cout<<"nothing to delete\n";
        return root;
    }
    else
    {
        if(root->data==d)
        {
            int noc=number_of_child(node * root);
            if(noc==0)
            {
                delete root;
                root=NULL;
            }
            else if(noc==1)
            {
                if(root->left==NULL)
                {
                    y=root->right;
                    root=root->right;
                    delete y;
                }
                else
                {
                    y=root->left;
                    root=root->left;
                    delete y;
                }
            }
            else
            {
                int x;
                node * temp=root->left;
                node * temp1=root;
                while(temp->right!=NULL)
                {
                    temp1=temp;
                    temp=temp->right;
                }
                temp->data=x;
                temp1=del(x,temp1);
                root->data=x;



            }
        }
        else if(root->data>d)
        {
            root->left=del(d,root->left);
        }
        else
        {
            root->right=del(d,root->right);
        }
        root->height=1+max(heightfun(root->left),heightfun(root->right));
        if(balancefactor(root)>1 || balancefactor(root)<-1)
        {
            if(heightfun(root->left)>heightfun(root->right))
            {
                // left case
                node * y=root->left;
                if(heightfun(y->left)< heightfun(y->right))
                {
                    // left right
                    root->left=leftrotation(root->left);
                    root=rightrotation(root);
                }
                else
                {
                    // left left
                    root=rightrotation(root);
                }

            }
            else
            {
                //right case
                node * y=root->right;
                if(heightfun(y->left) > heightfun(y->right))
                {
                    // right left
                    root->right=rightrotation(root->right);
                    root=leftrotation(root);

                }
                else
                {
                    // right right
                    root=leftrotation(root);

                }
            }
        }
        return root;

    }
}

int number_of_child(node * root)
{
    int count=0;
    if(root->left!=NULL)count++;
    if(root->right!=NULL)count++;
    return count;
}
int main()
{

}