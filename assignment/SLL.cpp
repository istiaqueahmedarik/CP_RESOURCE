#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
class SLL
{
    Node *head;

public:
    SLL()
    {
        head = NULL;
    }
    Node *createNewNode(int data)
    {
        Node *newNode = new Node(data);
        return newNode;
    }
    void insert_at_head(int data)
    {
        Node *newNode = createNewNode(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void insert_at_tail(int data)
    {
        Node *newNode = createNewNode(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insert_at_any_index(int val, int index)
    {
        Node *newNode = createNewNode(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void delete_at_head()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
    }
    void delete_at_tail()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
    void delete_at_any_index(int index)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        for (int i = 0; i < index; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    bool search(int val)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    ~SLL()
    {
        if (head != NULL)
        {
            delete head;
        }
    }
};
int main()
{
    SLL sll;
    sll.insert_at_head(10);
    sll.insert_at_head(20);
    sll.insert_at_head(30);
    sll.insert_at_head(40);
    sll.insert_at_head(50);
    sll.insert_at_head(60);
    sll.insert_at_head(70);
    sll.insert_at_head(80);
    sll.insert_at_head(90);
    sll.insert_at_head(100);

    cout << endl;
    sll.print();
    sll.insert_at_tail(200);

    sll.print();
    sll.insert_at_any_index(500, 3);
    sll.print();
    sll.delete_at_head();
    sll.print();
    sll.delete_at_tail();
    sll.print();
    sll.delete_at_any_index(3);
    sll.print();
    sll.reverse();
    sll.print();
    return 0;
}