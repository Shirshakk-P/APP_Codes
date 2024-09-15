#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node
{
    int data;
    struct Node* next;
};

struct MinMax
{
    int max;
    int min;
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

struct MinMax findMaxMinLL(struct Node* head)
{
    struct MinMax result;
    struct Node* current = head;

    if(head == NULL)
    {
        result.max = INT_MIN;
        result.min = INT_MAX;
        return result;
    }

    result.max = head->data;
    result.min = head->data;

    while (current != NULL)
    {
        if(current->data > result.max)
            result.max = current->data;

        if(current->data < result.min)
            result.min = current->data;

        current = current->next;
    }
    return result;    
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

    struct MinMax result = findMaxMinLL(head);

    printf("%d\n",result.max);
    printf("%d\n",result.min);
    printf("%d\n", (result.max - result.min));

    freeLL(head);
    
    return 0;
}