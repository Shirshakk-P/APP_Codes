#include<stdio.h>
#include<stdlib.h>

// Dynamic Table with pop_back() function, reducing to half

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

    return table;
}

int* halfCapacity(int *table)
{
    capacity = capacity / 2 > 1 ? capacity / 2 : 1;

    table = realloc(table, capacity*sizeof(int));

    if(table==NULL)
    {
        exit(1);
    }
    return table;
}

int* pop_back(int *table)
{
    if(size==0)
        return table;

    size--;

    if(size>0 && size<=(capacity/4))
        table = halfCapacity(table);

    return table;
}

void printTable(int *table)
{
    printf("capacity = %d; size = %d; elements = ", capacity, size);
    for(int i=0; i<size; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");
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
    scanf("%d", &capacity);
    scanf("%d", &size);

    int *table = malloc(capacity*sizeof(int));

    scanElements(size, table);

    int popCount;
    scanf("%d", &popCount);

    for(int i=0; i<popCount; i++)
    {
        table = pop_back(table);
        printTable(table);
    }

    free(table);
    return 0;
}