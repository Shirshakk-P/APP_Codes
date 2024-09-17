#include <stdio.h>
#include <stdlib.h>

// Doubly LL as a file with Store, Search, Delete functions

struct Node {
    int data;
    int next;
    int prev;
};

#define NODE_SIZE sizeof(struct Node)

struct Node readNode(FILE *file, int index) 
{
    struct Node node;
    fseek(file, index * NODE_SIZE, SEEK_SET);
    fread(&node, NODE_SIZE, 1, file);
    return node;
}

void writeNode(FILE *file, int index, struct Node node) 
{
    fseek(file, index * NODE_SIZE, SEEK_SET);
    fwrite(&node, NODE_SIZE, 1, file);
}

int getNodeCount(FILE *file) 
{
    fseek(file, 0, SEEK_END);
    return ftell(file) / NODE_SIZE;
}

void insertNode(FILE *file, int value) 
{
    struct Node newNode;
    newNode.data = value;
    newNode.next = -1;

    int nodeCount = getNodeCount(file);

    if (nodeCount == 0) {
        newNode.prev = -1;
        writeNode(file, nodeCount, newNode);
    } 
    else 
    {
        struct Node lastNode = readNode(file, nodeCount - 1);
        lastNode.next = nodeCount;
        writeNode(file, nodeCount - 1, lastNode);

        newNode.prev = nodeCount - 1;
        writeNode(file, nodeCount, newNode);
    }
}

int searchNode(FILE *file, int value) 
{
    int nodeCount = getNodeCount(file);

    for (int i = 0; i < nodeCount; i++) 
    {
        struct Node node = readNode(file, i);
        if (node.data == value) 
        {
            return i; 
        }
    }
    return -1; 
}

void deleteNode(FILE *file, int value) 
{
    int nodeIndex = searchNode(file, value);
    if (nodeIndex == -1) 
    {
        printf("Node with value %d not found.\n", value);
        return;
    }

    struct Node nodeToDelete = readNode(file, nodeIndex);

    if (nodeToDelete.prev != -1) 
    {
        struct Node prevNode = readNode(file, nodeToDelete.prev);
        prevNode.next = nodeToDelete.next;
        writeNode(file, nodeToDelete.prev, prevNode);
    }

    if (nodeToDelete.next != -1) 
    {
        struct Node nextNode = readNode(file, nodeToDelete.next);
        nextNode.prev = nodeToDelete.prev;
        writeNode(file, nodeToDelete.next, nextNode);
    }
}

void printList(FILE *file) 
{
    int nodeCount = getNodeCount(file);
    if (nodeCount == 0) 
    {
        printf("List is empty.\n");
        return;
    }

    int i = 0;
    struct Node node = readNode(file, i);
    while (node.next != -1)
    {
        printf("%d <-> ", node.data);
        i = node.next;
        node = readNode(file, i);
    }
    printf("%d\n", node.data);
}

int main() 
{
    FILE *file = fopen("doubly_linked_list.dat", "w+b");
    if (!file) 
    {
        printf("Error opening file.\n");
        return 1;
    }

    insertNode(file, 10);
    insertNode(file, 20);
    insertNode(file, 30);
    insertNode(file, 40);

    printList(file);

    int searchValue = 20;
    int index = searchNode(file, searchValue);

    if (index != -1) 
    {
        printf("Node with value %d found at index %d.\n", searchValue, index);
    } 

    else 
    {
        printf("Node with value %d not found.\n", searchValue);
    }

    int deleteValue = 30;
    deleteNode(file, deleteValue);

    printList(file);

    fclose(file);
    return 0;
}
