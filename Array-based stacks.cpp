#include <iostream>
using namespace std;

class Stack {
public:
    int a[100], top;

    Stack() {
        top = -1;
    }

    bool empty() {
        return top == -1;
    }

    void push(int x) {
        if (top < 99)
            a[++top] = x;
    }

    int pop() {
        if (empty())
            return -1;
        return a[top--];
    }
};

class Queue {
    Stack s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty())
                s2.push(s1.pop());
        }

        if (s2.empty())
            cout << "Queue is empty\n";
        else
            cout << "Deleted: " << s2.pop() << endl;
    }

    void display() {
        Stack temp = s2;
        Stack temp2 = s1;
        Stack result;

        while (!temp.empty())
            result.push(temp.pop());

        while (!temp2.empty())
            result.push(temp2.pop());

        cout << "Queue: ";
        while (!result.empty())
            cout << result.pop() << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.dequeue();
    q.display();

    return 0;
}
