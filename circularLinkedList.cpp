#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int val){
        data = val;
        next = NULL;
    }
};


void insertAtHead(Node * &head, int val){
    Node * n = new Node(val);

    if(head==NULL){
        n->next = n;
        head = n;
        return;
    }

    Node * ptr = head;
    while(ptr->next != head){
        ptr=ptr->next;
    }
    ptr->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(Node*& head, int val) {
    Node* n = new Node(val);

    if (head == NULL) {
        n->next = n;
        head = n;
        return;
    }

    Node* ptr = head;
    while (ptr->next != head) {
        ptr = ptr->next;
    }

    ptr->next = n;
    n->next = head;
}

void deleteHead(Node * &head){
    Node * ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    Node * temp = head;
    ptr->next = head -> next;
    head = head->next;
    delete temp;
}

void deleteNodeAtPosition(Node * &head, int pos){
    if(head == NULL) return;

    if(pos == 1){
        deleteHead(head);
        return; 
    }

    Node * ptr = head;
    int count = 1;
    while(count != pos-1){
         ptr = ptr->next;
         count++;
    }

    Node * deletedNode = ptr->next;
    ptr->next = ptr->next->next;
    delete deletedNode;
    cout << "Node at position " << pos << " deleted successfully\n"; 
}

void display(Node * head){
    Node * ptr = head;
    do{
        cout <<  ptr->data << "->"; 
        ptr=ptr->next;
    }while(ptr != head);
    cout<<endl;
}

int main(){
    Node * start = NULL;
    insertAtTail(start,1);
    insertAtTail(start,2);
    insertAtTail(start,3);
    insertAtTail(start,4);
    display(start);
    insertAtHead(start,5);
    display(start); 
    deleteNodeAtPosition(start,3);
    display(start);
    deleteHead(start);
    display(start); 
    return 0;
}
