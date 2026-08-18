#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1,s2;
public:
  void enque(int x)
  {
      s1.push(x);
  }
  
  void deque()
  {
      if(s1.empty() && s2.empty())
      {
          cout<<"UnderFlow\n";
      }
       if(s2.empty())
      {
          while(!s1.empty())
          {
              s2.push(s1.top());
              s1.pop();
          }
      }
      s2.pop();
  }
  void peek()
  {
      if(s1.empty() && s2.empty())
      {
          cout<<"UnderFlow\n";
      }
       if(s2.empty())
      {
          while(!s1.empty())
          {
              s2.push(s1.top());
              s1.pop();
          }
      }
      cout<<s2.top()<<endl;
  }
  
};

int main() {
    Queue q;
	q.enque(10);
	q.enque(20);
	q.enque(30);
	q.peek();
	q.deque();
	q.peek();
	q.enque(40);
	q.deque();
	q.peek();

}