#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    //constructor
    Node(int data)
    {
        this->data= data;
        this->next= NULL;
        this->prev= NULL;
    }
    
    //destructor
    ~Node()
    {
        int val= this->data;
        if(next!=NULL)
        {
            next=NULL;
            delete next;
        }
        std::cout << "Memory free for node with data: "<< val << std::endl;
    }
};

//traversal in Linked List
void print(Node* head)
{
    Node* temp= head;
    
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Length of Linked List
int getLength(Node* head)
{
    int ct=0;
    Node* temp= head;
    
    while(temp!= NULL)
    {
        ct++;
        temp=temp->next;
    }
    return ct;
}

void insertAtHead(Node* &head, int data, Node* &tail)
{
    if(head==NULL)
    {
        Node* temp= new Node(data);
        head=temp;
        tail=temp;
    }
    else
    {
        Node* temp= new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insertAtTail(Node* &tail, int d, Node* &head)
{
    if(head==NULL)
    {
        Node* temp= new Node(d);
        head=temp;
        tail=temp;
    }
    else
    {
        Node* temp= new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertAtPosition(Node* &head, int pos, int d, Node* &tail)
{
    //insert at begining
    if(pos==1)
    {
        insertAtHead(head,d,tail);
        return;
    }
    
    int cnt=1;
    Node* temp= head; //so that head don't lost
    
    while(cnt<pos-1 && temp != NULL)
    {
        temp=temp->next;
        cnt++;
    }
    //insert at end and update tail
    if(temp == NULL)
    {
        insertAtTail(tail, d, head);
        return;
    }
    
    //create new Node
    Node* nodetoinsert= new Node(d);
    
    nodetoinsert->next= temp->next;
    temp->next->prev= nodetoinsert;
    temp->next= nodetoinsert;
    nodetoinsert->prev=temp;
}


void deleteNode(Node* &head, int pos, Node* &tail)
{
    
    if(pos==1)
    {
        //deleting first Node
        Node* temp=head;
        temp->next->prev= NULL;
        head= temp->next;
        // temp->next= NULL;
        //Memory free of first Node
        delete temp;
    }
    else
    {
        //delete at mid or last node
        Node* curr= head;
        Node* prev= NULL;
        int cnt=1;
        while(cnt<pos && curr->next!=NULL)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        
        //Code without updating tail
        // curr->prev=NULL;
        // prev->next= curr->next;
        // curr->next= NULL;
        // delete curr;
        
        if(curr->next==NULL)
        {
            curr->prev=NULL;
            prev->next= curr->next;
            tail=prev;
            delete curr;
        }
        else
        {
            prev->next=curr->next;
            curr->next->prev= prev; 
            delete curr;
        }
        
    }
}


int main()
{
    Node* node1= new Node(11);
    Node* head= node1;
    Node* tail= node1;
    print(head);
    // cout<<"Length of Linked List: "<<getLength(head);
    
    insertAtHead(head, 7, tail);
    print(head);
    
    insertAtHead(head, 4, tail);
    print(head);
    
    insertAtTail(tail, 31, tail);
    print(head);
    
    insertAtPosition(head, 3, 5, tail);
    print(head);
    
    deleteNode(head, 1, tail);
    print(head);
    
    cout<<"Head: "<<head->data<<", Tail: "<<tail->data;
    
    return 0;
}
