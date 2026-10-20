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

class Queue {
public:
    Node *front, *rear;

    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* n = new Node(x);

        if (rear == NULL)
            front = rear = n;
        else {
            rear->next = n;
            rear = n;
        }
    }

    int dequeue() {
        if (front == NULL)
            return -1;

        Node* temp = front;
        int x = temp->data;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return x;
    }

    bool empty() {
        return front == NULL;
    }
};

int main() {
    Queue q;
    int n, a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    for (int i = 0; i < n; i++)
        a[i] = q.dequeue();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    for (int i = 0; i < n; i++)
        q.enqueue(a[i]);

    cout << "Sorted queue: ";
    while (!q.empty())
        cout << q.dequeue() << " ";

    return 0;
}
