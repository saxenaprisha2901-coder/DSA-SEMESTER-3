#include <bits/stdc++.h>
using namespace std;
#define Max 5

class Stack {
    int s[Max];
    int top;
public:
    Stack() { top = -1; }

    bool isoverflow() { return top == Max - 1; }
    bool isunderflow() { return top == -1; }

    void push(int x) {
        if(isoverflow()) {
            cout << "Stack is full\n";
            return;
        }
        s[++top] = x;
        cout << x << " is Pushed into the stack\n";
    }

    void pop() {
        if(isunderflow()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << s[top] << " is Popped\n";
        top--;
    }

    void peek() {
        if(isunderflow()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top Element is : " << s[top] << "\n";
    }

    void traverse() {
        if(isunderflow()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack Elements : ";
        for(int i = top; i >= 0; i--) {
            cout << s[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack s1;
    int ch, val;
    while(true) {
        cout << "1 for Push\n";
        cout << "2 for Pop\n";
        cout << "3 for Peek\n";
        cout << "4 for Traverse\n";
        cout << "5 for Exit\n";
        cin >> ch;
        switch(ch) {
            case 1: 
                cout << "Enter Element: ";
                cin >> val;
                s1.push(val);
                break;
            case 2: 
                s1.pop();
                break;
            case 3: 
                s1.peek();
                break;
            case 4: 
                s1.traverse();
                break;
            case 5: 
                cout << "Exiting...\n";
                return 0;
            default: 
                cout << "Invalid Choice\n";
        }
    }
}