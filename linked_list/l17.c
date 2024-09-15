#include<stdio.h>
#include<stdlib.h>

#define size 2

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNewNode(struct Node* head, int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;

    return head;
}

void createLL(struct Node** head, int nodes)
{
    while(nodes--)
    {
        int n;
        scanf("%d", &n);
        *head = createNewNode(*head, n);
    }
}

struct Node* reverseLLPairs(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    int count = 0;

    while(current != NULL && count < size)
    {
        next = current->next; 
        current->next = prev;
        prev = current;
        current = next; 
        count++; 
    }

    if(next != NULL)
    {
        head->next = reverseLLPairs(next);
    }

    return prev;
}

void printLL(struct Node* head)
{
    struct Node* current = head;
    while(current != NULL)
    {
        printf(" %d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeLL(struct Node* head)
{
    struct Node* current = head;
    struct Node* nextNode; 

    while(current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main()
{
    int nodes;
    scanf("%d", &nodes);

    struct Node* head = NULL;
    createLL(&head, nodes);
    printLL(head);

    head = reverseLLPairs(head);
    printLL(head);
    freeLL(head);
    
    return 0;
}