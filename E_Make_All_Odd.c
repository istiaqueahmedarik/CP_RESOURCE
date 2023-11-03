#include <stdio.h>
int main()
{
    long long t;
    scanf("%lld", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        long long arr[n];
        for (long long i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        long long count = 0;
        for (long long i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                count++;
            }
        }
        if (count == n)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", count);
        }
    }
}