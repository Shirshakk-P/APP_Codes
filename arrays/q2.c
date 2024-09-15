#include<stdio.h>

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

int neighbourSum(int n, int arr[][n], int i, int j)
{
	int sum=0;

	for(int x=-1; x<=1; x++)
	{
		for(int y=-1; y<=1; y++)
		{
			if(x==0 && y==0)
				continue;

			int ni = i+x;
			int nj = j+y;

			if(ni>=0 && ni<n && nj>=0 && nj<n)
			{
				sum += arr[ni][nj];
			}
		}
	}
	return sum;
}

int findDiagonalElement(int n, int arr[][n], int i)
{
	return arr[i][i];
}

int highestDiagonalSumIndex(int n, int sum[n])
{
	int index;
	for(int i=0; i<n-1; i++)
	{
		if(sum[i]<sum[i+1])
		{
			index =  i+1;
		}
	}
	return index;
}

int main()
{
	int n=0;
	int index;
	scanf("%d", &n);

	int arr[n][n];
	createSqMatrix(n, arr);

	int a[n];
	int sum[n];
	for(int i=0; i<n; i++)
	{
		a[i] = findDiagonalElement(n, arr, i);
		sum[i] = neighbourSum(n, arr, i, i);
	}

	for(int i=0; i<n; i++)
	{
	printf("%d:%d\n", a[i], sum[i]);
	}

	index=highestDiagonalSumIndex(n, sum);
	printf("index:%d", index);

	return 0;
}
