#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNewNodeCLL(struct Node* head, int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = val;

    if(head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;       //Null for Linked List, but for circular, last node must point back to head 

    return head;
}

void createCircularLL(struct Node** head, int nodes)
{
    while(nodes--)
    {
        int n;
        scanf("%d", &n);
        *head = createNewNodeCLL(*head, n);
    }
}

int sumEven(struct Node* head, int nodes)
{
    int sum = 0;

    if(head == NULL)
        return sum;

    struct Node* current = head;

    while(nodes--)
    {
        if((current->data)%2 == 0)
            sum += current->data;
        
        current = current->next;
    }

    return sum;
}

void printCircularLL(struct Node* head)
{
    if(head == NULL)
        return;

    struct Node* current = head;
    
    do
    {
        printf(" %d->", current->data);
        current = current->next;
    }
    while(current != head);

    printf("HEAD\n");
}

void freeCircularLL(struct Node* head)
{
    if(head == NULL)
        return;

    struct Node* current = head;
    struct Node* nextNode; 

    do
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    while(current != head);
}

int main()
{
    int nodes;
    scanf("%d", &nodes);

    struct Node* head = NULL;
    createCircularLL(&head, nodes);
    printCircularLL(head);

    int sum;
    sum = sumEven(head, nodes);
    printf("%d\n", sum);

    freeCircularLL(head);

    return 0;
}