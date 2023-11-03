
#include <iostream>
#include <cstring>
using namespace std;
class User
{
    char *id;
    char *name;

public:
    User(char *id, char *name)
    {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    ~User()
    {
        delete[] id;
        delete[] name;
    }
    void setId(char *x)
    {
        strcpy(id, x);
    }
    void setName(char *x)
    {
        strcpy(name, x);
    }
    char *getId()
    {
        return id;
    }
    char *getName()
    {
        return name;
    }
};
class Account
{
    User *user;
    char *phone;
    int balance;

public:
    Account(char *id, char *name, char *phone)
    {
        user = new User(id, name);
        this->phone = new char[strlen(phone) + 1];
        strcpy(this->phone, phone);
        balance = 500;
    }
    ~Account()
    {
        delete user;
        delete[] phone;
    }
    void setPhone(char *x)
    {
        strcpy(phone, x);
    }
    void print()
    {
        cout << "ID: " << user->getId() << ", Name: " << user->getName() << ", Phone: " << phone << ", Balance: " << balance << endl;
    }
    void transferMoney(Account &receiver, int amount)
    {
        if (strcmp(phone, receiver.phone) == 0)
        {
            cout << "Invalid transaction" << endl;
            return;
        }
        if (balance >= amount)
        {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transaction successful" << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
};

void transferMoney(Account &sender, Account &receiver, int amount)
{
    if (strcmp(sender.phone, receiver.phone) == 0)
    {
        cout << "Invalid transaction" << endl;
        return;
    }
    if (sender.balance >= amount)
    {
        sender.balance -= amount;
        receiver.balance += amount;
        cout << "Transaction successful" << endl;
    }
    else
    {
        cout << "Insufficient balance" << endl;
    }
}

int main()
{
    Account acc[4] = {Account("10", "Rafi", "010"), Account("15", "Binita", "015"), Account("29", "Nabil", "029"), Account("36", "Maisha", "036")};
    Account admin("10", "Rafi", "010");
    admin.setPhone("01511");
    admin.setId("A-11");
    admin.setName("Admin");
    transferMoney(acc[2], acc[0], 100);
    transferMoney(acc[1], acc[0], 150);
    transferMoney(acc[1], acc[1], 100);
    transferMoney(acc[2], acc[3], 800);
    for (int i = 0; i < 4; i++)
    {
        acc[i].print();
    }
    admin.print();
    return 0;
}
