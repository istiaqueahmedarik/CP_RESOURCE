#include <bits/stdc++.h>
#define SIZE 5
using namespace std;
int q[SIZE], front = -1, rear = -1;
void enqueue(int);
void dequeue();
void display();
int F();
bool isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}
int main()
{
    enqueue(10);
    enqueue(20);

    dequeue();

    enqueue(30);

    display();
}

void enqueue(int n)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        q[++rear] = n;
    }
}
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Element deleted from queue is : " << q[front++] << endl;
        if (front > rear)
            front = rear = -1;
    }
}
void display()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue elements are : ";
        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
}
int F()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        return q[front];
    }
}