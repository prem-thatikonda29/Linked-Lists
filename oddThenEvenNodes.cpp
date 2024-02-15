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

void insertAtTail(Node* &head, int val){
    if(head == NULL){
        Node* n = new Node(val);
        n->next = head;
        head = n;
        return;
    }

    Node * ptr = head;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }

    Node * n = new Node(val);
    ptr->next = n;
    n->next = NULL;
}

int getLengthOfList(Node * &head){
    int count = 0;
    Node * ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

void appendKNodes(Node*& head, int k) {
    if (head == NULL || k <= 0) {
        return; 
    }

    int length = getLengthOfList(head);
    k = k % length;

    if (k == 0) {
        return; 
    }

    Node* newHead;
    Node * newTail;
    Node* tail = head;
    int count = 1;

    while (tail->next != NULL) {
        if(count == length - k){
            newHead = tail->next;
            newTail = tail;
        }
        tail = tail->next;
        count++;
    }

    tail->next = head;
    newTail->next = NULL;
    head = newHead;
}

void swapOddAndEven(Node* &head) {
    Node * odd = head;
    Node * evenStart = odd->next;
    Node * even = evenStart;

    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if(odd->next == NULL){
        even->next = NULL;
    }
}


void displayList(Node* &head) {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data;
        if (ptr->next != NULL) {
            cout << " -> ";
        }
        ptr = ptr->next;
    }
    cout << endl;
}


int main(){
    Node * head = NULL;
    int nums[] = {1,2,3,4,5,6};
    for(int i = 0; i < 6; i++){
        insertAtTail(head,nums[i]);
    }

    displayList(head);
    swapOddAndEven(head);
    displayList(head);

    return 0;
}