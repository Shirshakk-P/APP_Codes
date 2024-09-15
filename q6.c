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

int rowSum(int n, int arr[n][n], int index)
{
    if(index<0 || index>= n)
    {
        return -1;
    }
    int sum=0;
    for(int j=0; j<n; j++)
    {
        sum += arr[index][j];
    }
    return sum;
}

int columnSum(int n, int arr[n][n], int index)
{
    if(index<0 || index>= n)
    {
        return -1;
    }
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i][index];
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n][n];
    createSqMatrix(n, arr);

    int row[n];
    int column[n];

    for(int i=0; i<n; i++)
    {
        row[i]=rowSum(n, arr, i);
        column[i]=columnSum(n, arr, i);
    }

    int flag=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(row[i]==column[j])
            {
                printf("Row:%d\n", i+1);
                printf("Column:%d\n", j+1);
                flag=1;
                break;
            }
            
        }
        if(flag==1)
            break;
    }

    return 0;
}