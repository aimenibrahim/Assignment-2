#include <iostream>
using namespace std;

class Queue {
public:
    int a[100], front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear < 99)
            a[++rear] = x;
    }

    int dequeue() {
        if (front > rear)
            return -1;
        return a[front++];
    }

    bool empty() {
        return front > rear;
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
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        q.enqueue(a[i]);

    cout << "Sorted queue: ";
    while (!q.empty())
        cout << q.dequeue() << " ";

    return 0;
}
