#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *prev;
  Node *next;

  //! Constructor
  Node(int d) {
    this->data = d;
    this->prev = NULL;
    this->next = NULL;
  }
};
 void print(Node * head) {
    Node *temp = head;

    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  int getLength(Node * &head) {
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
      count++;
      temp = temp->next;
    }
    return count;
  }

void insertAtHead(Node *&head, int val) {
  Node *temp = new Node(val);
  temp->next = head;
  if (head != NULL) {
    head->prev = temp;
  }
  head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int val) {
  Node *temp = new Node(val);
  if (tail == NULL) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int val) {
  if (pos == 1) {
    insertAtHead(head, val);
    return;
  }
  int len = getLength(head);
  if (pos > len + 1) {
    cout << "Error: position out of range" << endl;
    return;
  }
  Node *temp = head;
  for (int i = 1; i < pos - 1; i++) {
    temp = temp->next;
  }
  if (temp->next == NULL) {
    insertAtTail(head,tail, val);
    return;
  }
  Node *n = new Node(val);
  n->next = temp->next;
  temp->next->prev = n;
  temp->next = n;
  n->prev = temp;
}


 
  int main() {
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    

    insertAtHead(head, 11);
    print(head);

    insertAtTail(head,tail, 10);
    print(head);

    insertAtPosition(head, tail, 2, 15);
    print(head);

    cout << getLength(head) << endl;

    return 0;
}