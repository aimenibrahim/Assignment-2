#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }

    bool empty() {
        return top == NULL;
    }

    void push(int x) {
        Node* n = new Node(x);
        n->next = top;
        top = n;
    }

    int pop() {
        if (empty())
            return -1;

        Node* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return x;
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
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    q.dequeue();

    return 0;
}
