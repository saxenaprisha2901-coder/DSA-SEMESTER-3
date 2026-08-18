#include <iostream>
using namespace std;

class Queue
{
    int q[100];
    int FRONT, REAR;
    int MaxSize;

public:
    Queue(int size)
    {
        MaxSize = size;
        FRONT = REAR = -1;
    }

    bool isOverflow()
    {
        return (REAR == MaxSize - 1);
    }

    bool underflow()
    {
        return (FRONT == -1);
    }

    void enqueue(int value)
    {
        if (isOverflow())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (FRONT == -1)
        {
            FRONT = REAR = 0;
            q[REAR] = value;
        }
        else
        {
            REAR++;
            q[REAR] = value;
        }
    }

    void dequeue()
    {
        if (underflow())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else if (FRONT == REAR)
        {
            FRONT = REAR = -1;
        }
        else
        {
            FRONT = FRONT + 1;
        }
    }

    void peek()
    {
        if (underflow())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {
            cout << "Front Element = " << q[FRONT] << endl;
        }
    }

    void display()
    {
        if (underflow())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            for (int i = FRONT; i <= REAR; i++)
            {
                cout << q[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue obj(5);

    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);

    cout << "Queue: ";
    obj.display();

    obj.peek();

    obj.dequeue();

    cout << "After Dequeue: ";
    obj.display();

    obj.peek();

    return 0;
}