#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        if (n - k <= 1 && n % 2 == 0)
            printf("Ayoub\n");
        else
            printf("Kilani\n");
    }
}