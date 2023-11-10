#include <iostream>
#include <queue>

using namespace std;

class Queue {
  int *arr;
  int front;
  int rear;
  int size;

public:
  Queue() {
    size = 1000;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  bool isEmpty() { return front == rear; }

  void pop() {
    if (isEmpty()) {
      cout << "Queue Underflow" << endl;
      return;
    }
    front++;
  }
  void push(int element) {
    if (rear == size) {
      cout << "Queue Overflow" << endl;
      return;
    }
    arr[rear] = element;
    rear++;
  }
  int peek() {
    if (isEmpty()) {
      cout << "Queue Underflow" << endl;
      return -1;
    }
    return arr[front];
  }
  int getFront() {
    if (isEmpty()) {
      cout << "Queue Underflow" << endl;
      return -1;
    }
    return arr[front];
  }
};