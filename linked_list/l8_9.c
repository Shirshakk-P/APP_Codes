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

// Q8: find the smallest mumber in the doubly linked list
int findSmallest(struct Node* head, int nodes)
{
    if(head == NULL || nodes==0)
        return -1;

    int smallest = head->data;
    struct Node* current = head;

    while(nodes--)
    {
        if(current->data < smallest)
            smallest = current->data;

        current = current->next;
    }
    return smallest;
}

// Q8: delete the smallest mumber in the doubly linked list
struct Node* deleteSmallest(struct Node* head, int nodes)
{
    if(head == NULL || nodes == 0)
        return NULL;

    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* smallest = head;
    struct Node* prevsmallest = NULL;

    while(nodes--)
    {
        if(current->data < smallest->data)
        {
            smallest = current;
            prevsmallest = prev;
        }
        prev = current;
        current = current->next;
    }

    if(smallest == head)
        head = head->next;

    else 
        prevsmallest->next = smallest->next;

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

    int smallest;
    smallest = findSmallest(head, nodes);
    printf("%d\n", smallest);

    head = deleteSmallest(head, nodes);
    printDLL(head);

    freeDLL(head);
    
    return 0;
}