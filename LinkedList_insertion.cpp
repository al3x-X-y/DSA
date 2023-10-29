#include <cstddef>
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    //! Constructor
    Node(int data) {
        this->data = data;
        next = NULL;
    }

    //! Destructor
    ~Node (){
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout <<"memory is free for node with data "<<data<<endl;
    }
};

void insertAtTail(Node* &head, int val) {
    Node* n = new Node(val);

    if (head == NULL) {
        head = n;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void insertAtHead(Node* &head, int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtMiddle(Node* &head,Node* &tail, int val, int pos) {
    Node* n = new Node(val);

    if (pos == 1) {
        // n->next = head;
        // head = n;
        insertAtHead(head, val);
    } else {
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            insertAtTail(head, val);
            tail = n; // update tail pointer
            return;
        }
        n->next = temp->next;
        temp->next = n;
    }
}


//! delete Node by position
void deleteNodebyPos(Node* &head , Node* &tail, int pos){
    
    //! deleting first Node
    if (pos == 1){
        Node* temp = head;
        head = head->next;
        //memory free for start Node 
        temp -> next = NULL;
        delete temp;
        return;
    }else {
        //! deleting last or middle Node
        Node* current = head;
        Node* prev = NULL;
        for (int i = 1; i < pos; i++){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        if (current == tail){
            tail = prev; // update tail pointer
        }
        current->next = NULL;
        delete current;
    }
}

//! delete Node by value
void deleteNodebyVal(Node* &head , Node* &tail, int val){
    Node * current = head;
    Node * prev = NULL;

  while ( current != NULL){
        if (current->data == val){
        if(prev == NULL){   
            // deleting first Node 
            head = current->next;
            if (current == tail){
                tail = NULL; // list is now empty
            }
        } else {
            prev->next = current->next;
            if (current == tail){
                tail = prev; // update tail pointer
            }
        }
        current->next = NULL;
        delete current;
        return;
    }
    prev = current;
    current = current->next; 
  }
}

bool search(Node* &head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL; 
    Node* tail = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    insertAtMiddle(head, tail, 10, 4);
    display(head);
    deleteNodebyVal(head,tail, 10);
    display(head);
    deleteNodebyPos(head,tail, 2);
    display(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    // cout << search(head, 5) << endl;
    // cout << search(head, 2) << endl;
}