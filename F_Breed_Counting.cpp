#include <stdio.h>
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int r;
    scanf("%d", &r);
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }
    if (r == 1)
        a[0] = 1;
    if (r == 2)
        b[0] = 1;
    if (r == 3)
        c[0] = 1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &r);
        if (r == 1)
        {
            a[i] += a[i - 1] + 1;
            b[i] += b[i - 1];
            c[i] += c[i - 1];
        }
        if (r == 2)
        {
            a[i] += a[i - 1];
            b[i] += b[i - 1] + 1;
            c[i] += c[i - 1];
        }
        if (r == 3)
        {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
            c[i] += c[i - 1] + 1;
        }
    }
    while (q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        if (l == 0)
            printf("%d %d %d\n", a[r], b[r], c[r]);
        else
            printf("%d %d %d\n", a[r] - a[l - 1], b[r] - b[l - 1], c[r] - c[l - 1]);
    }
}