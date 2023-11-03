#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *nxt;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->nxt = NULL;
    }
};

class Stack
{
private:
    Node *head;
    Node *tail;

public:
    Stack()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->nxt = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void delete_at_end()
    {
        if (head == NULL)
        {
            cout << "stack is empty" << endl;
            return;
        }
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->nxt = NULL;
        delete temp;
    }
};

int main()
{
}
