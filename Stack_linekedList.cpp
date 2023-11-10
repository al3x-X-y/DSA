#include <iostream>

struct Node {
  int data;
  Node *next;
};

Node *top = nullptr;

Node *createNode(int data) {
  Node *newNode = new Node();
  if (!newNode) {
    std::cout << "Heap overflow";
    exit(1);
  }
  newNode->data = data;
  newNode->next = nullptr;
  return newNode;
}

void push(int data) {
  Node *newNode = createNode(data);
  newNode->next = top;
  top = newNode;
}

bool isEmpty() { return top == nullptr; }

int peek() {
  if (!isEmpty())
    return top->data;
  else
    exit(1);
}

void pop() {
  Node *temp;
  if (top == nullptr) {
    std::cout << "Stack underflow" << std::endl;
    exit(1);
  } else {
    temp = top;
    top = top->next;
    delete temp;
  }
}

void display() {
  Node *temp;
  if (top == nullptr) {
    std::cout << "Stack underflow";
    exit(1);
  } else {
    temp = top;
    while (temp != nullptr) {
      std::cout << temp->data << "-> ";
      temp = temp->next;
    }
  }
}

int main() {
  push(10);
  push(20);
  push(30);

  std::cout << "Top element is: " << peek() << std::endl;
  pop();
  std::cout << "Top element is: " << peek() << std::endl;

  display();

  return 0;
}