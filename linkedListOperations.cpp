#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};


void insertAtTail(Node*& head, int val) {
    Node* n = new Node(val);

    if (head == NULL) {
        head = n;
    }

    Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = n;
    n->next = NULL;
}


void insertAtHead(Node*& head, int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}


void deleteFirstNode(Node*& head) {
    if (head == NULL) {
        return;
    }

    Node* deletedNode = head;
    head = head->next;
    delete deletedNode;
}


void deleteAfterValue(Node*& head, int val) {
    if (head == nullptr) {
        cout << "Error: The list is empty." << endl;
        return;
    }

    Node* ptr = head;

    while (ptr != nullptr && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == nullptr || ptr->next == nullptr) {
        cout << "Error: Node with value " << val << " not found or no node after it to delete." << endl;
        return;
    }

    Node* nodeToDelete = ptr->next;
    ptr->next = ptr->next->next;

    delete nodeToDelete;

    cout << "Node after " << val << " deleted." << endl;
}


void deleteNode(Node*& head, int val) {
    if (head == NULL) {
        return;
    }

    if (head->data == val) {
        deleteFirstNode(head);
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL && ptr->next->data != val) {
        ptr = ptr->next;
    }

    if (ptr->next == NULL) {
        cout << val << " not found in the list." << endl;
        return;
    }

    Node* deletedNode = ptr->next;
    ptr->next = ptr->next->next;

    delete deletedNode;
    cout << val << " deleted from the list." << endl;
}

void deleteBeforeValue(Node*& head, int val) {
    if (head == nullptr || head->next == nullptr) {
        cout << "Not enough nodes to delete before value " << val << "." << endl;
        return;
    }

    Node* ptr = head;
    Node* prev = nullptr;

    while (ptr->next != nullptr && ptr->next->data != val) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr->next == nullptr) {
        cout << "Node with value " << val << " not found or not enough nodes to delete before it." << endl;
        return;
    }

    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = ptr->next;
    }

    delete ptr;
    cout << "Node before value " << val << " deleted." << endl;
}


void deleteLastNode(Node * &head){
    if(head->next == NULL){
        cout << "Underflow"<<endl;
        return;
    }

    Node * ptr = head;
    Node * prevPtr;
    while(ptr->next!=NULL){
        prevPtr = ptr;
        ptr=ptr->next;
    }
    prevPtr->next = NULL;
    delete ptr;
    cout << "Last Node deleted from the list." <<endl;
}


void insertAfterValue(Node*& head, int val, int newValue) {
    Node* ptr = head;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Node with value " << val << " not found." << endl;
        return;
    }

    Node* newNode = new Node(newValue);
    newNode->next = ptr->next;
    ptr->next = newNode;

    cout << newValue << " inserted after value " << val << "." << endl;
}


void insertBeforeValue(Node*& head, int val, int newValue) {
    Node* ptr = head;
    Node * prev = nullptr;
    while (ptr != NULL && ptr->data != val) {
        prev= ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Node with value " << val << " not found." << endl;
        return;
    }

    Node* newNode = new Node(newValue);

    if (ptr==head){
        head = newNode;
        newNode->next = ptr;
    }
    else if(prev==nullptr){
        insertAtHead(head,val);
    }
    else{
        newNode->next = ptr;
        prev->next = newNode;
    }

    cout << newValue << " inserted before value " << val << "." << endl;
}


void displayList(Node* head) {
    Node* ptr = head;
    cout << "The list is: ";
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}


int countNodes(Node * &head){
    int cnt = 0;
    if (head==NULL){
        return (0);
    }
    if(head->next == NULL){
        return 1;
    }

    Node *ptr = head;

    while(ptr->next!=NULL){
        cnt++;
        ptr = ptr->next;
    }

    return cnt+1;
}

bool search(Node* head, int val) {
    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == val)
            return true;
        else {
            ptr = ptr->next;
        }
    }
    return false;
}


Node * reverseList(Node * &head){ 
    Node * prevPtr = NULL;
    Node * ptr = head;
    Node * nextPtr;

    while(ptr!=NULL){
        nextPtr = ptr->next;
        ptr->next = prevPtr;

        prevPtr=ptr;
        ptr = nextPtr;
    }

    return prevPtr; 
}


void displayMenu() {
    cout << "\nLinked List Operations:" << endl;
    cout << "1. Insert at Head" << endl;
    cout << "2. Insert at Tail" << endl;
    cout << "3. Insert Before Value" << endl;
    cout << "4. Insert After Value" << endl;
    cout << "5. Delete First Node" << endl;
    cout << "6. Delete Before a Node" << endl;
    cout << "7. Delete After a Node" << endl;
    cout << "8. Delete a particular node" << endl;
    cout << "9. Delete last node" << endl;
    cout << "10. Display List" << endl;
    cout << "11. Reverse List" << endl;
    cout << "12. Search" << endl;
    cout << "13. Count nodes" << endl;
    cout << "14. Exit" << endl;
}

int main() {
    Node* start = NULL;
    int choice, value, newValue;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            insertAtHead(start, value);
            cout << value << " inserted at the head." << endl;
            break;

        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            insertAtTail(start, value);
            cout << value << " inserted at the tail." << endl;
            break;

        case 3:
            cout << "Enter value before which to insert: ";
            cin >> value;
            cout << "Enter new value to insert: ";
            cin >> newValue;
            insertBeforeValue(start,value,newValue);
            break;

        case 4:
            cout << "Enter value after which to insert: ";
            cin >> value;
            cout << "Enter new value to insert: ";
            cin >> newValue;
            insertAfterValue(start, value, newValue);
            break;
            
        case 5:
            deleteFirstNode(start);
            cout << "First node deleted." << endl;
            break;

        case 6:
            cout << "Enter value before which's node to delete: ";
            cin >> value;
            deleteBeforeValue(start,value);
            break;
        case 7:
            cout << "Enter value after which's node to delete: ";
            cin >> value;
            deleteAfterValue(start,value);
            break;
        case 8:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(start, value);
            break;
        case 9:
            deleteLastNode(start);
            break;
        case 10:
            displayList(start);
            break;
        case 11:
            start = reverseList(start);
            cout << "Linked list reversed successfully\n"<<endl;
            displayList(start);
            break;
        case 12:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(start, value)) {
                cout << value << " found in the list." << endl;
            } else {
                cout << value << " not found in the list." << endl;
            }
            break;
        case 13:
            cout << countNodes(start) << " nodes present" <<endl;
            break;
        case 14:
            cout << "Exiting program."<<endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 13);

    return 0;
}