#include <iostream>
using namespace std;

class CircularQueue
{
    int q[5];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if ((rear + 1) % 5 == front)
        {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % 5;
        q[rear] = x;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << q[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % 5;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;

        while (true)
        {
            cout << q[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 5;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
} 