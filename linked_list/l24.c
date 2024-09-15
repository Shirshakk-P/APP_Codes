#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node* next;
};

struct Node* createNewNode(struct Node* head, char val)
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
        char n;
        scanf(" %c", &n);
        *head = createNewNode(*head, n);
    }
}

struct Node* copyList(struct Node* head) 
{
    if (head == NULL) return NULL;

    struct Node* newHead = NULL;
    struct Node* temp = head;

    newHead = (struct Node*)malloc(sizeof(struct Node));
    newHead->data = temp->data;
    newHead->next = NULL;
    
    struct Node* current = newHead;
    temp = temp->next;

    while (temp != NULL) 
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = temp->data;
        newNode->next = NULL;
        
        current->next = newNode;
        current = newNode;
        temp = temp->next;
    }
    return newHead;
}

void appendSelf(struct Node** head) 
{
    if (*head == NULL) 
        return;

    struct Node* temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    struct Node* copyHead = copyList(*head);
    temp->next = copyHead;
}

void printLL(struct Node* head)
{
    struct Node* current = head;
    while(current != NULL)
    {
        printf(" %c->", current->data);
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

    appendSelf(&head);
    printLL(head);
    freeLL(head);
    
    return 0;
}