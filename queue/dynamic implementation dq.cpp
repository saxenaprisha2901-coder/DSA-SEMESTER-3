#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* prev;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void insertFront(int x)
{
    Node* newNode = new Node;
    newNode->info = x;

    if (front == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        front = rear = newNode;
    }
    else
    {
        newNode->prev = NULL;
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear(int x)
{
    Node* newNode = new Node;
    newNode->info = x;

    if (rear == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        front = rear = newNode;
    }
    else
    {
        newNode->prev = rear;
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteFront()
{
    if (front == NULL)
    {
        cout << "Deque is empty\n";
        return;
    }

    Node* temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }

    delete temp;
}

void deleteRear()
{
    if (rear == NULL)
    {
        cout << "Deque is empty\n";
        return;
    }

    Node* temp = rear;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }

    delete temp;
}

void peekFront()
{
    if (front == NULL)
        cout << "Deque is empty\n";
    else
        cout << "Front element = " << front->info << endl;
}

void peekRear()
{
    if (rear == NULL)
        cout << "Deque is empty\n";
    else
        cout << "Rear element = " << rear->info << endl;
}

void display()
{
    if (front == NULL)
    {
        cout << "Deque is empty\n";
        return;
    }

    Node* temp = front;

    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, x;

    do
    {
        cout << "\n--- DEQUE MENU ---\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Peek Front\n";
        cout << "6. Peek Rear\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            insertFront(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            insertRear(x);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            peekFront();
            break;

        case 6:
            peekRear();
            break;

        case 7:
            display();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}