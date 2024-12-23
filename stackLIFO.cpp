#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *top = nullptr;

void push(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if(top != nullptr) {
        Node *tempNode = top;
        top = top->next;
        delete tempNode;
    }
    else {
        cout << "queue is empty!" << endl;
    }
}

void printList() {
    Node *tempNode = top;
    while(tempNode != nullptr) {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
    delete tempNode;
}

int main() {
    int num;

    while(1) {
        cout << "Enter number for append to list: (-1 is pop) ";
        cin >>num;

        if(num == -1) pop();
        else push(num);

        printList();
    }


    return 0;
}
