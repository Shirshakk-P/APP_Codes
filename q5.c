#include<stdio.h>
#include<string.h>

void getInputStrings(int n, char str[n][100])
{
    for(int i=0; i<n; i++)
    {
        scanf("%s", str[i]);
    }
}

void sortStrings(int n, char str[n][100])
{
    char temp[100];

    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
           if(strcmp(str[i], str[j])>0)
           {
            strcpy(temp, str[i]);
            strcpy(str[i], str[j]);
            strcpy(str[j],temp);
           }
        }   
    }
}

void printStrings(int n, char str[n][100])
{
    for(int i=0; i<n; i++)
    {
        printf("%s ",str[i]);
    }
}

void getUnique(int n, char str[n][100])
{
    for (int i = 0; i < n; i++)
    {
        int count=1;
        for(int j=0; j<i; j++)
        {
            if(strcmp(str[i], str[j])==0)
            {
                count=0;
                break;
            }
        }
        if(count)
        {
            printf("%s ", str[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char str[n][100];
    getInputStrings(n, str);

    sortStrings(n, str);
    printf("Sorted:\n");
    printStrings(n, str);

    printf("\nUnique:\n");
    getUnique(n, str);

    return 0;
}