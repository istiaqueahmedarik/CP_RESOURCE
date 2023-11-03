#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, x;
        scanf("%d %d", &n, &x);
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= x)
            {
                ans += b[i];
            }
        }
        printf("%d\n", ans);
    }
}