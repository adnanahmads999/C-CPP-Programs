#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    
    //constructor to initialize
    Node(int data)
    {
        this->data= data;
        this->next= NULL;
    }
};

void insertAtHead(Node* &head, int d)
{
    //create new Node
    Node* temp= new Node(d);
    temp->next= head;
    head=temp;
}

void insertAtTail(Node* &tail, int d)
{
    //create new Node
    Node* temp= new Node(d);
    tail->next= temp; //adding address of new node to next of tail
    tail= temp; //updating tail and sending it to last again
}

void insertAtPosition(Node* &head, Node* &tail, int d, int pos)
{
    //insert at begining
    if(pos==1)
    {
        insertAtHead(head,d);
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
        insertAtTail(tail, d);
        return;
    }
    
    //create new Node
    Node* nodetoinsert= new Node(d);
    nodetoinsert->next= temp->next;
    temp->next= nodetoinsert;
    
}

void deleteNode(Node* &head, int pos)
{
    
}

void print(Node* &head)
{
    Node* temp= head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{
    Node *node1=new Node(5);
    // std::cout << node1->data << std::endl;
    // std::cout << node1->next << std::endl;
    
    //head pointing to node1
    Node* head= node1;
    
    //tail pointing to node1
    Node* tail= node1;
    
    print(head);
    
    insertAtHead(head, 11);
    cout<<"Insert at begining: ";
    print(head);
    
    insertAtTail(tail, 25);
    cout<<"Insert at end: ";
    print(head);
    
    insertAtPosition(head, tail, 36, 26);
    cout<<"Insert in between: ";
    print(head);
    
    cout<<head->data<<endl;
    cout<<tail->data<<endl;

    return 0;
}
