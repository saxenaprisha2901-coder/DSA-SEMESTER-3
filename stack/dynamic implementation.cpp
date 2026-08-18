#include <bits/stdc++.h>
using namespace std;

struct Node {
    int info;
    Node* next;
};

Node* top = NULL;

void push(int x) {
    Node* temp = new Node;
    temp->info = x;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << top->info << endl;
}

void traverse() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;

    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch, val;

    while (true) {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Traverse\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter Element: ";
                cin >> val;
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                traverse();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }
}