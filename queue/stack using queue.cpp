#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:

    void push(int x)
    {
        q2.push(x);

       
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

       
        swap(q1, q2);
    }

    
    void pop()
    {
        if (q1.empty())
        {
            cout << "UnderFlow\n";
            return;
        }

        q1.pop();
    }

   
    void top()
    {
        if (q1.empty())
        {
            cout << "UnderFlow\n";
            return;
        }

        cout << q1.front() << endl;
    }

    
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.top();    // 30

    s.pop();

    s.top();    // 20

    s.push(40);

    s.top();    // 40

    s.pop();

    s.top();    // 20

    return 0;
}