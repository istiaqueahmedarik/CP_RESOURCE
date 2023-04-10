#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    map<string, string> mp;
    while (n--)
    {
        string cmd, ip;
        cin >> cmd >> ip;
        mp[ip] = cmd;
    }
    while (q--)
    {
        string name, ip;
        cin >> name >> ip;
        ip.pop_back();
        cout << name << " " << ip << "; #" << mp[ip] << "\n";
    }
    return 0;
}
