#include<stdio.h>

void createMatrix(int m, int n, int arr[m][n])
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void createTranspose(int m, int n, int arr[m][n], int t[n][m])
{
    for(int i=0; i<n; i++)      //transpose >> make sure to change rows iterator to n instead of m in org mat
    {
        for(int j=0; j<m; j++)
        {
            t[i][j] = arr[j][i];
        }
    }
}

void printMatrix(int m, int n, int arr[m][n])
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m; 
    int n;
    scanf("%d %d", &m, &n);

    int arr[m][n];
    createMatrix(m, n, arr);

    int t[n][m];
    createTranspose(m, n, arr, t);
    printMatrix(n, m, t);

    return 0;
}