#include<iostream>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = NULL;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = NULL;
            this->tail = NULL;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode * temp=new SinglyLinkedListNode(node_data);
            if(tail!=NULL)
            {
                
                tail->next=temp;
                tail=temp;

            }
            else
            {
                head=temp;
                tail=temp;
            }
            
		}
};

void print_singly_linked_list(SinglyLinkedListNode* node) {
    SinglyLinkedListNode * temp=node;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void rearrange(SinglyLinkedListNode* head) {
	SinglyLinkedListNode * current=head;
    SinglyLinkedListNode * tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
      if(current!=NULL)
      {
         
      while((current->next!=tail)&&(current!=tail))
      {
        
          SinglyLinkedListNode * temp1;
            if(head->next==NULL)
            {
            temp1=NULL;
            }
            else
            {
                SinglyLinkedListNode * temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
                
            }
            SinglyLinkedListNode * temp2=temp->next;
            temp->next=NULL;
            tail=temp;
            temp1=temp2;
            }
          temp1->next=current->next;
          current->next=temp1;
          current=temp1->next;
        
      }
     
      }
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        SinglyLinkedList *LS = new SinglyLinkedList();
        while(n--)
        {
            int element;
            cin>>element;
            LS->insert_node(element);
        }
	    
	     rearrange(LS->head);
	    print_singly_linked_list(LS->head);
	    delete LS;

    }
	return 0;
}