#include <stdio.h>
typedef long long ll;
int main()
{
    ll n;
    scanf("%lld", &n);
    ll arr[n];
    for (ll i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    ll p1 = 0;
    ll count = 0;
    ll max = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] >= arr[i])
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 0;
        }
    }
    printf("%lld\n", max + 1);
}