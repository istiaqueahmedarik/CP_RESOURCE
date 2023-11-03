#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, r, l;
        scanf("%d %d %d", &n, &r, &l);
        int A[n];
        if ((l - r) % 2 == 0 && l - r >= n)
        {
            for (int i = r, j = 0; i <= l, j < n; i = i + 2, j++)
            {
                A[j] = i;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
        }
        else if ((l - r) % 2 != 0 && l - r >= n)
        {
            int i = r;
            int j = 0;
            int m;
            for (; j < n;)
            {

                A[j] = i;
                j = j + 1;
                m = j;
                i = i + 3;
                if (i > l)
                {
                    break;
                }
            }
            if (i > l && m < n)
            {
                i = i - 3;
                i = i - 2;
                while (i > 1, m < n)
                {
                    A[m] = i;
                    i = i - 2;
                    m++;
                }
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
}