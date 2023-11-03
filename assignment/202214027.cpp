#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int val;
    Node *next;

public:
    Node()
    {
        next = NULL;
    }

    Node(int n)
    {
        val = n;
        next = NULL;
    }

    int getValue()
    {
        return val;
    }

    void setValue(int n)
    {
        val = n;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *n)
    {
        next = n;
    }

    ~Node()
    {
        delete next;
    }
};

class Stack
{
private:
    Node *head;
    int SIZE;

public:
    Stack()
    {
        head = NULL;
        SIZE = 0;
    }

    void push(int n)
    {
        /// Stack functionality: Inserts n in the stack
        /// Linked list functionality: Creates a node and inserts at the head of the list
        Node *temp = new Node(n);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->setNext(head);
            head = temp;
        }
        SIZE++;
    }

    bool isEmpty()
    {
        /// Stack functionality: Returns true if the stack is empty, otherwise returns false
        return SIZE == 0;
    }

    int top()
    {
        /// Stack functionality: Returns the last inserted value/top value of the stack (doesn't remove from stack)
        /// Linked list functionality: Returns the value located at head
        /// If the user calls this function for an empty stack, it will generate runtime error
        return head->getValue();
    }

    void pop()
    {
        /// Stack functionality: Removes the top value of the stack
        /// Linked list functionality: if the list is not empty then removes the node under head and declares new head
        /// If the user calls this function for an empty stack, it will generate runtime error
        Node *temp = head;
        head = head->getNext();
        SIZE--;
    }

    int size()
    {
        /// Returns the size of stack
        return SIZE;
    }

    void displaystack()
    {
        /// Prints the stack
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->getValue() << " ";
            temp = temp->getNext();
        }
    }
    ~Stack()
    {
        delete head;
    }
};

int main()
{
    int choice;
    Stack s;
    while (choice != 0)
    {
        cout << "0 - Exit." << endl;
        cout << "1 - Push Item." << endl;
        cout << "2 - Pop Item." << endl;
        cout << "3 - View Top Item." << endl;
        cout << "4 - Size of Stack." << endl;
        cout << "5 - Display Items (Print STACK)." << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            int n;
            cout << "Enter the value to be pushed: ";
            cin >> n;
            s.push(n);
            cout << "Item pushed successfully." << endl;
            cout << "Current Stack: ";
            s.displaystack();
            break;

        case 2:
            /// Must check whether the stack is empty or not before popping
            if (s.isEmpty())
                cout << "Stack is empty." << endl;
            else
            {
                s.pop();
                cout << "Item popped successfully." << endl;
                cout << "Current Stack: ";
                s.displaystack();
            }
            break;

        case 3:
            /// Must check whether the stack is empty or not before viewing top item
            if (s.isEmpty())
                cout << "Stack is empty." << endl;
            else
            {
                cout << "Top item: " << s.top() << endl;
            }
            break;

        case 4:
            cout << "Size of stack: " << s.size() << endl;
            break;

        case 5:
            cout << "Current Stack: ";
            s.displaystack();
            break;

        default:
            cout << "An Invalid choice." << endl;
        }

        cout << endl
             << endl;
    }

    return 0;
}
