#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void createSqMatrix(int n, int arr[n][n])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d ", &arr[i][j]);
		}
	}
}

bool isUnique(int n, int arr[], int value)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i] == value)
		return false;
	}
	return true;
}

int* uniqueInRow(int n, int arr[n][n], int row, int* uniqueCount)
{
		int* uniqueRow = (int*)malloc(n*sizeof(int));
		int count=0;
		for(int j=0; j<n; j++)
		{
			int currentElement = arr[row][j];
			if(isUnique(n, uniqueRow, currentElement))
			{
				uniqueRow[count] = currentElement;
				count++;
			}
		}
		*uniqueCount = count;
		return uniqueRow;	
}

int* uniqueInColumn(int n, int arr[n][n], int column, int* uniqueCount)
{
	int* uniqueColumn = (int*)malloc(n*sizeof(int));
	int count=0;
	for(int i=0; i<n; i++)
	{
		int currentElement = arr[i][column];
		if(isUnique(n, uniqueColumn, currentElement))
		{
			uniqueColumn[count] = currentElement;
			count++;
		}
	}
	*uniqueCount = count;
	return uniqueColumn;
}

void printUniqueInColumn(int n, int uniqueColumn[n])
{
	for(int i=0; i<n; i++)
	{
		printf("%d ", uniqueColumn[i]);
	}
	printf("\n");
}

void printUniqueInRow(int n, int uniqueRow[n])
{
	for(int i=0; i<n; i++)
	{
		printf("%d ", uniqueRow[i]);
	}
	printf("\n");
}

int compare(const void *a, const void *b)
{
	return(*(int*)a - *(int*)b);
}

void sort(int n, int arr[n])
{
	qsort(arr, n, sizeof(int), compare);
}

void printUniqueInMatrix(int n, int arr[n][n])
{

}

int main()
{
	int n=0;
	scanf("%d", &n);

	int arr[n][n];
	createSqMatrix(n, arr);

	int uniqueCount=0;

	printf("Along rows:\n");
	for(int i=0; i<n; i++)
	{
		int* rowArray = uniqueInRow(n, arr, i, &uniqueCount);
		sort(n, rowArray);
		printUniqueInRow(n, rowArray);
		free(rowArray);
	}


	printf("\nAlong columns:\n");
	for(int i=0; i<n; i++)
	{
		int* columnArray = uniqueInColumn(n, arr, i, &uniqueCount);
		sort(n, columnArray);
		printUniqueInColumn(n, columnArray);
		free(columnArray);
	}

	printf("\nMatrix:\n");	
	//printUniqueInMatrix(n, arr);

	return 0;
}
