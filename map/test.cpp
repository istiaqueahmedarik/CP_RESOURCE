#include <bits/stdc++.h>
using namespace std;

namespace Financial
{
    namespace Mortgage
    {
        float MonthlyPayment(int p, float r, int n)
        {
            float c;
            r /= 12.0;
            c = pow(1.0 + r, n) - 1.0;
            return (p * r) / c;
        }
        float TotalPayments(int p, float r, int n)
        {
            return MonthlyPayment(p, r, n) * n;
        }
    }
    namespace Retirement
    {
        float MonthlySavings(int p, float r, int n)
        {
            float c;
            r /= 12.0;
            c = pow(1.0 + r, n) - 1.0;
            return p / ((pow(1.0 + r, n) - 1.0) / r) * c;
        }
        float TotalSavings(int p, float r, int n)
        {
            return MonthlySavings(p, r, n) * n * 12.0;
        }
    }
}

namespace Finan = Financial::Mortgage;
namespace Retir = Financial::Retirement;

int main()
{
    long long p, n;

    float r;

    cout << "Enter Principal Amount: ";
    cin >> p;

    cout << "Enter Interest Rate: ";
    cin >> r;

    cout << "Enter Number of Periods: ";
    cin >> n;

    //        cout<<Finan::MonthlyPayment(p,r,n);

    cout << "Total Mortgage Payment: " << Finan::TotalPayments(p, r, n) << endl;

    cout << "Total Retirement Savings: " << Retir::TotalSavings(p, r, n) << endl;
}