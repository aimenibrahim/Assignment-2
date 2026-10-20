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
