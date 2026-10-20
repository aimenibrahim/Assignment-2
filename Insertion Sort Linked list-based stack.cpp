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

    void push(int x) {
        Node* n = new Node(x);
        n->next = top;
        top = n;
    }

    int pop() {
        if (top == NULL)
            return -1;

        Node* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }

    bool empty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    int n, a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    for (int i = n - 1; i >= 0; i--)
        a[i] = s.pop();

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    for (int i = n - 1; i >= 0; i--)
        s.push(a[i]);

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
