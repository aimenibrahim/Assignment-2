#include <iostream>
using namespace std;

class Queue {
public:
    int a[100], front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    bool empty() {
        return front > rear;
    }

    void enqueue(int x) {
        if (rear < 99)
            a[++rear] = x;
    }

    int dequeue() {
        if (empty())
            return -1;
        return a[front++];
    }
};

class Stack {
    Queue q1, q2;

public:
    void push(int x) {
        q2.enqueue(x);

        while (!q1.empty())
            q2.enqueue(q1.dequeue());

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.empty())
            cout << "Stack is empty\n";
        else
            cout << "Popped: " << q1.dequeue() << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    return 0;
}
