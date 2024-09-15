#include<stdio.h>
#include<stdlib.h>

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

void insertAlternate(struct Node** head1, struct Node* head2)
{
    struct Node* current1 = *head1;
    struct Node* current2 = head2;
    struct Node* next1;
    struct Node* next2;

    while(current1 != NULL && current2 != NULL)
    {
        next1 = current1->next;
        next2 = current2->next;

        current1->next = current2;
        current2->next = next1;
        
        current1 = next1;
        current2 = next2;
    }
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
    int nodes1;
    scanf("%d", &nodes1);

    struct Node* head1 = NULL;
    createLL(&head1, nodes1);

    int nodes2;
    scanf("%d", &nodes2);

    struct Node* head2 = NULL;
    createLL(&head2, nodes2);

    printLL(head1);
    printLL(head2);

    insertAlternate(&head1, head2);
    printLL(head1);

    freeLL(head1);
    
    return 0;
}