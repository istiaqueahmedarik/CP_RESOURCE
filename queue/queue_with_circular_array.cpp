#include <bits/stdc++.h>
#define SIZE 5
using namespace std;
int q[SIZE], front = -1, rear = -1;
void enqueue(int);
void dequeue();
void display();
int F();
bool isEmpty();
bool isFull();

int main()
{
}

void enqueue(int n)
{
    if (isFull())
        return;
    if (front == -1)
        front = 0;
    q[rear = (rear + 1) % SIZE] = n;
}
void dequeue()
{
    if (isEmpty())
        return;
    cout << "Element deleted from queue is : " << q[front = (front + 1) % SIZE] << endl;
    if (front == rear)
        front = rear = -1;
}
void display()
{
    if (isEmpty())
        return;
    for (int i = front; i != rear; i = (i + 1) % SIZE)
        cout << q[i] << " ";
    cout << q[rear] << endl;
}

int F()
{
    if (isEmpty())
        return -1;
    return q[front];
}

bool isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}

bool isFull()
{
    if (rear - front == 1 || (front == 0 && rear == SIZE - 1))
        return true;
    else
        return false;
}