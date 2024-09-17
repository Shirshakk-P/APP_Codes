#include <stdio.h>
#include <stdlib.h>

// Insertion Sort in a LL stored as a file

struct Node {
    int data;
    int next;  
};

#define NODE_SIZE sizeof(struct Node)

struct Node readNode(FILE *file, int index) {
    struct Node node;
    fseek(file, index * NODE_SIZE, SEEK_SET);
    fread(&node, NODE_SIZE, 1, file);
    return node;
}

void writeNode(FILE *file, int index, struct Node node) {
    fseek(file, index * NODE_SIZE, SEEK_SET);
    fwrite(&node, NODE_SIZE, 1, file);
}

int getNodeCount(FILE *file) {
    fseek(file, 0, SEEK_END);
    return ftell(file) / NODE_SIZE;
}

void insertionSortLinkedList(FILE *file) {
    int nodeCount = getNodeCount(file);
    if (nodeCount <= 1) {
        return;  
    }

    for (int i = 1; i < nodeCount; i++) 
    {
        struct Node currentNode = readNode(file, i);
        int j = i - 1;

        while (j >= 0) 
        {
            struct Node previousNode = readNode(file, j);
            if (previousNode.data <= currentNode.data) 
            {
                break;  
            }

            writeNode(file, j + 1, previousNode);
            j--;
        }

        writeNode(file, j + 1, currentNode);
    }
}

void printLinkedList(FILE *file) 
{
    int nodeCount = getNodeCount(file);
    for (int i = 0; i < nodeCount; i++)
    {
        struct Node node = readNode(file, i);
        printf("Node %d: data = %d, next = %d\n", i, node.data, node.next);
    }
}

int main() 
{
    FILE *file = fopen("linked_list.dat", "w+b");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    struct Node nodes[3];
    nodes[0].data = 10;
    nodes[0].next = 1;
    nodes[1].data = 5;
    nodes[1].next = 2;
    nodes[2].data = 20;
    nodes[2].next = -1;  

    for (int i = 0; i < 3; i++) 
    {
        writeNode(file, i, nodes[i]);
    }

    printLinkedList(file);

    insertionSortLinkedList(file);

    printLinkedList(file);

    fclose(file);
    return 0;
}
