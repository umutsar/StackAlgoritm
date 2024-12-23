#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = new Node();
Node *tail = new Node();
int counter = 0;

void printList()
{
    Node *tempNode = head;
    while (tempNode != nullptr)
    {
        cout << tempNode->data << " | ";
        tempNode = tempNode->next;
    }
    cout << " || size of list: " << counter;
    cout << endl << endl;
    delete tempNode;
}

void enqueue(int value)
{
    counter++;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    tail->next = newNode;
    if (head->next == nullptr)
    {
        head = newNode;
    }
    tail = newNode;
    printList();
}

void dequeue()
{
    
    if (head->next != nullptr)
    {
        counter--;
        Node *tempNode = head;
        head = head->next;
        delete tempNode;
    }
    else
    {
        cout << "Queue is empty!" << endl;
    }
    printList();
}

int main()
{
    int num;
    while (1)
    {
        cout << "Add number to list (-1 for dequeue): ";
        cin >> num;
        if(num == -1) dequeue();
        else enqueue(num);
    }

    return 0;
}
