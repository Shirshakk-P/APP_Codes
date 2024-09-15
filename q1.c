#include<stdio.h>
#include<math.h>

int inputDiagonalElements(int n, int arr[n][n])
{
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i][i]);
	}
}

int diagonalSum(int n, int arr[n][n])
{
	int sum=0;
	for(int i=0; i<n; i++)
	{
		sum += arr[i][i];
	}
	return sum;
}

int findMinX(int n, int diagonalSum)
{
	int nonDiaCount = (pow(n,2)-n);
	int x = ceil(diagonalSum/nonDiaCount)+1;

	return x;
}

void returnMatrix(int n, int arr[n][n], int x)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i!=j)
			{
				arr[i][j]=x;
			}
		}
	}
}

void printMatrix(int n, int arr[n][n])
{
	for(int i=0; i<n; i++)
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
	int n;
	scanf("%d",&n);

	int arr[n][n];
	inputDiagonalElements(n, arr); 

	int sum = diagonalSum(n, arr);
	int minX = findMinX(n, sum);
	returnMatrix(n, arr, minX);

	printMatrix(n, arr);
	return 0;
}
