#include<iostream>
#include<cstring>
using namespace std;
void pallindrome(string a)
{
    int alen=a.size();
    
    int i=0;
    for(i=0;i<alen;i++)
    {
        if(a[i]==a[alen-1-i])
        {

        }
        else
        {
            break;
        }
    }
    if(i>=alen-1-i)
    {
        cout<<"it is a pallindrome"<<endl;

    }
    else 
    {
        cout<<"it is not a pallindrome"<<endl;
    }

}
int count_number_of_words(string a)
{
    bool last_char=false;
    int count_space=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==' ')
        {
            if(last_char==true)
            count_space++;
            
            last_char=false;
        }
        else
        {
            last_char=true;
        }
    }
    if(a[a.size()-1]==' ')count_space--;
    return count_space+1;
}
string concatenate(string a,string b)
{
    int alen=a.size();
    int blen=b.size();
    int i;
    string arr;
    arr.resize(alen+blen);
    for(i=0;i<alen;i++)
    {
        arr[i]=a[i];
    }
    for(i=0;i<blen;i++)
    {
        
        arr[i+alen]=b[i];
    }
    a=string(arr);
    a[alen+blen]='\0';
   
    return arr;

}
void display_backward(string a)
{
    int i=0;
    while(1)
    {
        if(a[i]=='\0')
        {
            break;
        }
        i++;
    }
    for(int j=i-1;j>=0;j--)
    {
        cout<<a[j];
    }
    cout<<endl;
}
int find_substring(string a,string b)
{
    int alen=a.size();
    int blen=b.size();
    int i=0;
    for(i=0;i<blen-alen+1;i++)
    {
        int k=i;
       
        for(int j=0;j<alen;j++)
        {
            
            if(b[k]==a[j])
            {
                k++;
            }
            else
            {
                
                break;
            }
        }
        if(k==i+alen)
        {
            return i;
        }
    }
    return -1;
}
char most_frequent(string a)
{
    int alen=a.size();
    int i;
    int max=0;
    int pos=-1;
    for(i=0;i<alen;i++)
    {
        char x=a[i];
        int count=0;
        for(int j=0;j<alen;j++)
        {
            if(a[j]==x)
            {
                count++;
            }
        }
        if(count>max)
        {max=count;
            pos=i;
        }

    }
    // cout<<pos;
    return a[pos];

    
}
int main()
{
    
    
}