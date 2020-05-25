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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
		SinglyLinkedListNode * temp=head;
        if(temp!=NULL)
        {
            int var=temp->data;
            while(temp->next!=NULL)
            {
                if(temp->next->data==var)
                {
                    SinglyLinkedListNode* t=temp->next;
                    temp->next=temp->next->next;
                    delete t;
                }
                else
                {
                    var=temp->next->data;
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                    break;
                }
            }
        }
        return head;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        SinglyLinkedList *LS = new SinglyLinkedList();
        int n;
        cin>>n;
        while(n--)
        {
            int element;
            cin>>element;
            LS->insert_node(element);
            
        }
        LS->head = removeDuplicates(LS->head);
        print_singly_linked_list(LS->head);
        delete LS;
        
    }
	return 0;
}