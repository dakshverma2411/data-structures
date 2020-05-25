#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
class vertex
{
    public:
    // string vertex_name;
    int data;
    vector <vertex * > list;
    int label;


};
class adjacency_list
{
    public:
    vector <vertex * > v;
    void add_vertex(int d)
    {
        vertex * temp=new vertex;
        temp->data=d;
        v.push_back(temp);
        int label=INT_MAX;
        
    }
    void add_edge(int a,int b)
    {
        int i;
        for(i=0;i<v.size();i++)
        {
            if(v[i]->data==a)
            {
                break;
            }
        }
        int one=i;
        for(i=0;i<v.size();i++)
        {
            if(v[i]->data==b)
            {
                break;
            }
        }
        int two=i;
        v[one]->list.push_back(v[two]);
        v[two]->list.push_back(v[one]);

        
    }
    void delete_edge(int a,int b)
    {
        int i;
        for(i=0;i<v.size();i++)
        {
            if(v[i]->data==a)
            {
                break;
            }
        }
        int one=i;
        for(i=0;i<v.size();i++)
        {
            if(v[i]->data==b)
            {
                break;
            }
        }
        int two=i;
        vector <vertex *> ::iterator iter1;
        vector <vertex *> ::iterator iter2;
        iter1=find(v[one]->list.begin(),v[one]->list.end(),v[two]);
        v[one]->list.erase(iter1);

        iter2=find(v[two]->list.begin(),v[two]->list.end(),v[one]);
        v[two]->list.erase(iter2);


        

    }
    void print()
    {
        int i;
        for(i=0;i<v.size();i++)
        {
            int d=v[i]->data;
            int s=v[i]->list.size();
            cout<<d<<" is adjacent to ";
            for(int j=0;j<s;j++)
            {
                cout<<v[i]->list[j]->data<<" ";
            }
            cout<<endl;
        }
    }
    void bfs()
    {
        deque <vertex *> dq;
        int i;
        int source;
        for(i=0;i<v.size();i++)
        {
            v[i]->label=-1;
        }
        dq.push_back(v[0]);
        v[0]->label=0;
        while(!dq.empty())
        {
            // cout<<"here\n";
            vertex * temp=dq.front();
            dq.pop_front();
            int s=temp->list.size();
            for(int j=0;j<s;j++)
            {
                // cout<<"label "<<temp->list[j]->label<<endl;
                if(temp->list[j]->label!=-1)
                {

                }
                else
                {
                    temp->list[j]->label=temp->label+1;
                    dq.push_back(temp->list[j]);
                }
            }
        }

    }
    void print_labels()
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]->data<<"-"<<v[i]->label<<endl;
        }
    }
    
};
int main()
{
    cout<<"starting...\n";
    adjacency_list obj;
    obj.add_vertex(0);
    obj.add_vertex(1);
    obj.add_vertex(2);
    obj.add_vertex(3);
    obj.add_edge(0,1);
    obj.add_edge(0,3);
    obj.add_edge(1,3);
    obj.add_edge(2,3);
    obj.print();
    obj.bfs();

// obj.delete_edge(2,3);
cout<<"after bfs"<<endl;
// obj.print();
    obj.print_labels();


    

}