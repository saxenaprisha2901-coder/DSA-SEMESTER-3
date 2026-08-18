#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
    string postfix;

    cout << "Enter Postfix Expression: ";
    getline(cin, postfix);

    stack<int> st;
    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        // If token is a number
        if (isdigit(token[0]))
        {
            st.push(stoi(token));
        }
        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int r;

            switch (token[0])
            {
                case '+':
                    r = a + b;
                    break;

                case '-':
                    r = a - b;
                    break;

                case '*':
                    r = a * b;
                    break;

                case '/':
                    r = a / b;
                    break;

                case '^':
                    r = pow(a, b);
                    break;

                default:
                    cout << "Invalid Operator";
                    return 0;
            }

            st.push(r);
        }
    }

    cout << "Result = " << st.top() << endl;

    return 0;
}