#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int freq[101] = {0};
        int idx[101] = {0};
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
            idx[arr[i]] = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (freq[arr[i]] == 1)
            {
                printf("%d\n", idx[arr[i]]);
                break;
            }
        }
    }
    return 0;
}