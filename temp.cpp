#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

int main()
{
#pragma omp parallel for
    for (int i = 0; i < 10; i++)
    {
#pragma omp critical
        {
            cout << " " << i << endl;
        }
    }
    return 0;
}