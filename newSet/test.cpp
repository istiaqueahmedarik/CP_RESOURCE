#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node *address;
};
class link
{
    node *head;

public:
    link()
    {
        head = NULL;
    }
    void insertlast(int val)
    {
        node *newitem, *temp;
        newitem = new node;
        newitem->value = val;
        newitem->address = NULL;
        if (head == NULL)
        {
            head = newitem;
            temp = head;
        }
        else
        {
            temp->address = newitem;
            temp = newitem;
        }
    }
    void print()
    {
        node *i;
        for (i = head; i->address != NULL; i = i->address)
            cout << i->value << "  ";
        cout << i->value << endl;
    }
    void dltdup()
    {
        node *i, *j, *temp1, *temp2;
        for (i = head; i != NULL; i = i->address)
        {
            temp1 = i;
            for (j = i->address; j != NULL; j = j->address)
            {
                if (i->value == j->value)
                {
                    temp2 = j->address;
                    temp1->address = temp2;
                }
                else
                    temp1 = temp1->address;
            }
        }
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    link l;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        l.insertlast(arr[i]);
    }
    l.print();
    l.dltdup();
    l.print();
}