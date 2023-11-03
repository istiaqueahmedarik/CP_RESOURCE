#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);
        int a[n];
        int flag = 0;
        a[0] = l + 2;
        a[1] = l;
        int curSum = a[0] + a[1];
        if (a[0] > r || a[1] > r)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 2; i < n; i++)
        {
            curSum++;
            a[i] = curSum - a[i - 1];
            if (a[i] > r)
            {
                printf("-1\n");
                flag = 1;
                break;
            }
        }

        if (flag)
            continue;
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}