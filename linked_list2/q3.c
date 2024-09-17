#include<stdio.h>
#include<stdlib.h>

// Dynamic Table with deletion via indexes

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

    if(size>0 && size<= capacity/4)
    {
        table = halfCapacity(table);
    }

    return table;
}

void deleteByIndex(int *table, int index)
{
    if(index<0 || index>size)
        return;
    
    for(int i=index; i<size-1; i++)
    {
        table[i] = table[i+1];
    }

    size--;
}

void deleteFirstByValue(int *table, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (table[i] == val)
        {
            for (int j = i; j < size - 1; j++)
            {
                table[j] = table[j + 1];
            }
            size--;
            
            if (size > 0 && size <= capacity / 4)
            {
                table = halfCapacity(table);
            } 
            break;
        }
    }     
}

void deleteAllByValue(int *table, int val)
{
    int i = 0;

    while(i<size)
    {
        if(table[i] == val)
        {
            for(int j=i; j<size-1; j++)
                table[j] = table[j+1];

            size--;
        }
        else
            i++;
    }   

    if (size > 0 && size <= capacity / 4)
    {
        table = halfCapacity(table);
    } 
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
    int delIndex;
    int indexValue;
    int allValue;
    scanf("%d", &capacity);
    scanf("%d", &size);

    int *table = malloc(capacity*sizeof(int));

    scanElements(size, table);
    scanf("%d", &delIndex);
    scanf("%d", &indexValue);
    scanf("%d", &allValue);

    //printTable(table);
    deleteByIndex(table, delIndex);
    printTable(table);

    deleteFirstByValue(table, indexValue);
    printTable(table);

    deleteAllByValue(table, allValue);
    printTable(table);

    free(table);
    return 0;
}