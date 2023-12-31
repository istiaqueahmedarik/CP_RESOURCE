#include <stdio.h>

void matrix_mul(int **matA, int **matB, int **res, int n, int m, int q)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                res[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main()
{
    int n, m, p, q;
    scanf("%d %d", &n, &m);
    int **matA = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matA[i] = (int *)malloc(m * sizeof(int));
    scanf("%d %d", &p, &q);
    int **matB = (int **)malloc(p * sizeof(int *));
    for (int i = 0; i < p; i++)
        matB[i] = (int *)malloc(q * sizeof(int));
    if (m != p)
    {
        printf("Invalid");
        return 0;
    }
    int **res = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        res[i] = (int *)malloc(q * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }

    matrix_mul(matA, matB, res, n, m, q);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(matA[i]);
    free(matA);
    for (int i = 0; i < p; i++)
        free(matB[i]);
    free(matB);
    for (int i = 0; i < n; i++)
        free(res[i]);
    free(res);

    return 0;
}