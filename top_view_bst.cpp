#include<iostream>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// int max=-1;
// int min=1;
class node
{
    public:
    int data;
    node * left=NULL;
    node * right=NULL;
    int horizontal_distance;
};


node * insert(int d,node * root,int &min,int &max,int hd=0)
{
    if(root==NULL)
    {
        root=new node;
        root->data=d;
        root->horizontal_distance=hd;
        if(hd<min){
            min=hd;
        }
        if(hd>max)
        {
            max=hd;
        }
        return root;
    }
    else
    {
        if(root->data>=d)
        {
            root->left=insert(d,root->left,min,max,root->horizontal_distance-1);
        }
        else{
            root->right=insert(d,root->right,min,max,root->horizontal_distance+1);
        }
        return root;

    }
}
deque <node *> bfs(node * root,int min,int max)
{
    // cout<<"hereee";
    deque <node *> dq;
    int a=0;
    int b=0;
    cout<<dq.size()<<endl<<endl;
    if(root==NULL)
    {
        
    }
    else
    {
        queue <node *> q;
        q.push(root);
        while(!q.empty())
        {
            // cout<<"here1";
            node * temp=q.front();
            // cout<<temp->horizontal_distance<<endl;
            
            q.pop();
            if(temp!=NULL)
            {
                // cout<<temp->data<<" ";
                int x=temp->horizontal_distance;
                if(x==a && a<=max)
                {
                    cout<<"pushing "<<temp->data<<"---"<<dq.size()+1<<endl;
                    dq.push_back(temp);
                    if(a==b)
                    {
                        b--;
                    }
                    a++;
                    
                }
                else if(x==b && b>=min)
                {
                    // cout<<"pushin1'"<<endl;
                    
                    {
                        cout<<"pushing "<<temp->data<<"---"<<dq.size()+1<<endl;
                    dq.push_front(temp);
                    }
                    b--;
                }
                // if((x)<0 && (x)>=min)
                // {
                //     // cout<<"pushin2'"<<endl;
                //     cout<<"pushing "<<temp->data<<"---"<<dq.size()+1<<endl;
                    
                //     {
                //     dq.push_front(temp);
                //     }
                // }
                 q.push(temp->left);
                q.push(temp->right);
            }


        }
        
    }
    cout<<"dq size:"<<dq.size()<<endl;
    return dq;
}
int main()
{
    int min,max;
    min=1;
    max=-1;
    node * root=NULL;
    root=insert(10,root,min,max);
    root=insert(5,root,min,max);
    root=insert(20,root,min,max);
    root=insert(15,root,min,max);
    root=insert(25,root,min,max);
    root=insert(1,root,min,max);
    root=insert(8,root,min,max);
    // cout<<"max,min:"<<max<<"-"<<min;
    deque <node *> dqq=bfs(root,min,max);
    // cout<<dqq.size()<<endl;
    for(int i=0;i<dqq.size();i++)
    {
        // cout<<"here"<<endl;
        cout<<dqq[i]->data<<" ";
    }

}