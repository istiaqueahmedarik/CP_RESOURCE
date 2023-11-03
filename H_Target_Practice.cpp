#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    char c;
    scanf("%c", &c);
    while (t--)
    {

        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                char c;
                scanf("%c", &c);
                if (c == '.')
                    continue;
                int mn = i;
                if (j < mn)
                    mn = j;
                if (9 - i < mn)
                    mn = 9 - i;
                if (9 - j < mn)
                    mn = 9 - j;
                ans += (mn + 1);
            }
            scanf("%c", &c);
        }
        printf("%d\n", ans);
    }
}