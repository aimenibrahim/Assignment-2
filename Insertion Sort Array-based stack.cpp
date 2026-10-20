#include <iostream>
using namespace std;

class Stack {
public:
    int a[100], top;

    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top < 99)
            a[++top] = x;
    }

    int pop() {
        if (top == -1)
            return -1;
        return a[top--];
    }

    bool empty() {
        return top == -1;
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
