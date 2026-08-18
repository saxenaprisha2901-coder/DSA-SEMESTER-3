#include <iostream>
using namespace std;

class CircularQueue
{
    int *q;
    int front, rear, size;

public:
    CircularQueue(int n)
    {
        size = n;
        q = new int[size];
        front = rear = -1;
    }

    void enqueue(int x)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % size;
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
            front = (front + 1) % size;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        int i = front;

        while (true)
        {
            cout << q[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }

    ~CircularQueue()
    {
        delete[] q;
    }
};

int main()
{
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    CircularQueue cq(n);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cout << "Queue: ";
    cq.display();

    cq.dequeue();

    cout << "After deletion: ";
    cq.display();

    cq.enqueue(50);

    cout << "After insertion: ";
    cq.display();

    return 0;
}   