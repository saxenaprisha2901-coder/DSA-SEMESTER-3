#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string fun(string infix) {
    reverse(infix.begin(), infix.end());
   for(char &ch : infix)
   {
    if(ch == '(')
        ch = ')';
    else if(ch == ')')
        ch = '(';
    }
    string postfix = "";
    stack<char> st;

    for(char ch : infix) {
        if(isalnum(ch)) {
            postfix += ch;
        }
        else if(ch == '(') {
            st.push(ch);
        }
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // remove '('
        }
        else {
            while(!st.empty() && 
                 (precedence(st.top()) > precedence(ch) || 
                 (precedence(st.top()) != precedence(ch) && ch == '^'))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix;
   
    cin >> infix;

  
    cout <<fun(infix);

    return 0;
}