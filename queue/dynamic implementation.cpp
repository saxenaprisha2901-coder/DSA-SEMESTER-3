#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;


void enqueue(int value)
{
    Node *newNode = new Node();
    newNode->info = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}


void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    Node *temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }

    delete temp;
}


void peek()
{
    if (front == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Front Element = " << front->info << endl;
    }
}


void traverse()
{
    if (front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    Node *temp = front;

    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    cout << "Queue: ";
    traverse();

    peek();

    dequeue();

    cout << "After Dequeue: ";
    traverse();

    peek();

    return 0;
}