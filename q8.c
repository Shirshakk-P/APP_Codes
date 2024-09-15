#include<stdio.h>
#include<stdbool.h>

void createSqMatrix(int n, int arr[n][n])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
}

int neighbourSum(int n, int arr[n][n], int i, int j)
{
	int sum=0;
    if(i-1>=0)      //Up
        sum += arr[i-1][j];
    if(i+1<n)       //Down
        sum += arr[i+1][j];
    if(j-1>=0)      //Left
        sum += arr[i][j-1];
    if(j+1<n)      //Right
        sum += arr[i][j+1];

	return sum;
}

int checkDiagonal(int n, int arr[n][n])
{
    for (int i = 0; i<n; i++)
    {
        int diagonalElement = arr[i][i];
        int sum = neighbourSum(n, arr, i, i);

        if(diagonalElement != sum)
        {
            return 0;
        }
    }
    return 1;
}

void printResult(bool i)
{
    if (i==1)
        printf("yes\n");
    else 
        printf("no\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n][n];
    createSqMatrix(n, arr);

    bool result = checkDiagonal(n, arr);
    printResult(result);

    return 0;
}