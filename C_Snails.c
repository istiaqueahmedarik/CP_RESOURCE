#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        if (a >= n)
            printf("1\n");
        else if (a <= b)
            printf("-1\n");
        else
            printf("%d\n", (n - b - 1) / (a - b) + 1);
    }
}