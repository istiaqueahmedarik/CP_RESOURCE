#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (!a)
            cout << -1 << endl;
        else if (b % a)
            cout << -1 << endl;
        else
            cout << a << " " << b << endl;
    }
    return 0;
}
