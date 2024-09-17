#include<stdio.h>
#include<stdlib.h>

// Dynamic Table

int size = 0;
int capacity = 0;

int* doubleCapacity(int *table)
{
    if(capacity == 0)
        capacity++;
    
    capacity = 2*capacity;

    table = realloc(table, capacity*sizeof(int));

    if(table==NULL)
    {
        exit(1);
    }

    return table;
}

int* push_back(int *table, int value)
{
    if(size==capacity)
        table = doubleCapacity(table);

    table[size] = value;
    size++;

    printf("capacity = %d; size = %d; elements = ", capacity, size);
    for(int i=0; i<size; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");
    return table;
}

void scanElements(int n, int temp[n])
{
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp[i]);
    }
}

int main()
{
    int n;
    int *table = NULL;
    scanf("%d", &n);

    int temp[n];
    scanElements(n, temp);

    for(int i=0; i<n; i++)
    {
        table = push_back(table, temp[i]);
    }
    free(table);

    return 0;
}