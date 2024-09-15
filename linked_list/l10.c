#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node
{
    struct Node* previous;
    int data;
    struct Node* next;
};

struct Node* createNewNodeDLL(struct Node* head, int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->previous = NULL;;
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->previous = temp;

    return head;
}

void createDLL(struct Node** head, int nodes)
{
    while(nodes--)
    {
        int n;
        scanf("%d", &n);
        *head = createNewNodeDLL(*head, n);
    }
}

struct Node* reverseDLL(struct Node* head)
{
    struct Node* current = head;
    struct Node* temp = NULL;

    if(head == NULL)
        return NULL;

    while(current != NULL)
    {
        temp = current->previous; 
        current->previous = current->next;
        current->next = temp;

        current = current->previous; 
    }

    if(temp != NULL)
        head = temp->previous;

    return head;
}



void printDLL(struct Node* head)
{
    struct Node* current = head;
    printf("NULL <-");
    while(current != NULL)
    {
        printf("%d<->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeDLL(struct Node* head)
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
    createDLL(&head, nodes);
    printDLL(head);

    head = reverseDLL(head);
    printDLL(head);
    freeDLL(head);
    
    return 0;
}