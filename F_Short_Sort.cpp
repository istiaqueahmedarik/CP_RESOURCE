#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char x, a, b, c;
        scanf("%c%c%c%c", &x, &a, &b, &c);
        // abc acb cba bac
        if ((a == 'a' && b == 'b' && c == 'c') || (a == 'a' && b == 'c' && c == 'b') || (a == 'b' && b == 'a' && c == 'c') || (a == 'c' && b == 'b' && c == 'a'))
            printf("YES\n");
        else
            printf("NO\n");
    }
}