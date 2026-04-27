#include <iostream>
using namespace std;

#define MAX 100

// ========== Queue ADT ==========
class Queue {
private:
    int data[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() { return front == -1; }
    bool isFull()  { return rear == MAX - 1; }

    // Enqueue
    void enqueue(int val) {
        if (isFull()) { cout << "Queue Overflow.\n"; return; }
        if (isEmpty()) front = 0;
        data[++rear] = val;
        cout << "Enqueued: " << val << "\n";
    }

    // Dequeue
    int dequeue() {
        if (isEmpty()) { cout << "Queue Underflow.\n"; return -1; }
        int val = data[front];
        if (front == rear)
            front = rear = -1; // Reset
        else
            front++;
        cout << "Dequeued: " << val << "\n";
        return val;
    }

    // Peek front
    int peek() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return -1; }
        return data[front];
    }

    // Display
    void display() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++)
            cout << data[i] << " ";
        cout << "\n";
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    cout << "Front element: " << q.peek() << "\n";

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}
