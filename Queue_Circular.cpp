
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, rear, size;
public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full\n";
            return;
        }
        else if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        }
        else {
            rear++;
            arr[rear] = value;
        }
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        int data = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return data;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Elements in Circular Queue are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
        else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);

    q.display();

    cout << "Deleted value = " << q.dequeue() << endl;
    cout << "Deleted value = " << q.dequeue() << endl;

    q.display();

    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);

    q.display();

    q.enqueue(20);

    return 0;
}
