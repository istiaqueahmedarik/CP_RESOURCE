#include <bits/stdc++.h>
using namespace std;

namespace Financial
{
    namespace Mortgage
    {
        double monthlyPayment(double principal_amount, double interest_rate, double number_of_periods)
        {
            double r = interest_rate / 12.0;
            double c = pow(1.0 + r, number_of_periods) - 1.0;
            return (principal_amount * r) / c;
        }
        double totalPayments(double principal_amount, double interest_rate, double number_of_periods)
        {
            double monthly_payment = monthlyPayment(principal_amount, interest_rate, number_of_periods);
            return monthly_payment * number_of_periods;
        }
    }
    namespace Retirement
    {
        double monthlySavings(double principal_amount, double interest_rate, double number_of_periods)
        {
            double r = interest_rate / 12.0;
            double c = pow(1.0 + r, number_of_periods) - 1.0;
            return principal_amount / ((pow(1.0 + r, number_of_periods) - 1.0) / r) * c;
        }
        double totalSavings(double principal_amount, double interest_rate, double number_of_periods)
        {
            double monthly_savings = monthlySavings(principal_amount, interest_rate, number_of_periods);
            return monthly_savings * number_of_periods * 12.0;
        }
    }
}

int main()
{
    double principal_amount, interest_rate, number_of_periods;
    cout << "Enter principal amount: ";
    cin >> principal_amount;
    cout << "Enter interest rate: ";
    cin >> interest_rate;
    cout << "Enter number of periods: ";
    cin >> number_of_periods;
    cout << "Total payments for a mortgage: " << Financial::Mortgage::totalPayments(principal_amount, interest_rate, number_of_periods) << endl;
    cout << "Total savings needed for retirement: " << Financial::Retirement::totalSavings(principal_amount, interest_rate, number_of_periods) << endl;
    return 0;
}