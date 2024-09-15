#include <stdio.h>

#define MAX_NODES 100 

struct Node {
    int data;
    int next;  
};

struct Node nodePool[MAX_NODES];
int freeIndex = 0; 
int head = -1;  

int malloc_arr() 
{
    if (freeIndex >= MAX_NODES) {
        printf("Out of memory!\n");
        return -1;  
    }
    return freeIndex++;  
}

void freeArray(int index) 
{
    printf("Node at index %d is freed (but not reused in this simple simulation).\n", index);
}

void append(int data) 
{
    int newIndex = malloc_arr();
    if (newIndex == -1) 
    {
        return;  
    }
    
    nodePool[newIndex].data = data;
    nodePool[newIndex].next = -1;  
    
    if (head == -1) 
    {
        head = newIndex; 
    } 
    else 
    {
        int current = head;
        while (nodePool[current].next != -1) 
        {
            current = nodePool[current].next;
        }
        nodePool[current].next = newIndex;
    }
}

void printList() {
    if (head == -1) 
    {
        return;
    }
    
    int current = head;
    while (current != -1) 
    {
        printf("%d -> ", nodePool[current].data);
        current = nodePool[current].next;
    }
    printf("NULL\n");
}

void deleteNode(int data) 
{
    if (head == -1) 
    {
        return;
    }

    int current = head;
    int prev = -1;

    while (current != -1 && nodePool[current].data != data) 
    {
        prev = current;
        current = nodePool[current].next;
    }

    if (current == -1) 
    {
        return;
    }

    if (prev == -1) 
    {
        head = nodePool[current].next;
    } 
    else 
    {
        nodePool[prev].next = nodePool[current].next;
    }

    free_arr(current); 
}

int main() {
    append(10);
    append(20);
    append(30);
    
    printf("Initial list:\n");
    printList();
    
    deleteNode(20);
    
    printf("List after deleting node with data 20:\n");
    printList();
    
    return 0;
}
