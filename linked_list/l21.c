#include <stdio.h>
#include <stdlib.h>

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

    if (head == NULL) 
    {
        newNode->next = newNode;  
        return newNode;
    }

    while (temp->next != head) 
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;  

    return head;
}

void createCircularLL(struct Node** head, int nodes) 
{
    while (nodes--) 
    {
        int n;
        scanf("%d", &n);
        *head = createNewNodeCLL(*head, n);
    }
}

struct Node* findMaxNode(struct Node* head) 
{
    struct Node* maxNode = head;
    struct Node* temp = head->next;

    while (temp != head) 
    {
        if (temp->data > maxNode->data) 
        {
            maxNode = temp;
        }
        temp = temp->next;
    }
    return maxNode;
}

struct Node* mergeListsAfterMax(struct Node* head1, struct Node* head2) 
{
    if (head1 == NULL || head2 == NULL) 
    {
        return NULL;  
    }

    struct Node* maxNode1 = findMaxNode(head1);
    struct Node* maxNode2 = findMaxNode(head2);
    struct Node* temp = head2;
    
    while (temp->next != head2) 
    {
        temp = temp->next;
    }

    temp->next = maxNode1->next;  
    maxNode1->next = maxNode2; 
    
    return head1;
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

    printf("NULL\n");
}

void freeCircularLL(struct Node* head) 
{
    if (head == NULL)
        return;

    struct Node* current = head;
    struct Node* temp;
    
    while (current != head)
    {
        temp = current->next;
        free(current);
        current = temp;
    } 
}

int main() 
{
    int nodes1; 
    scanf("%d", &nodes1);
    struct Node* head1 = NULL;
    createCircularLL(&head1, nodes1);

    int nodes2;
    scanf("%d", &nodes2);
    struct Node* head2 = NULL;
    createCircularLL(&head2, nodes2);

    printCircularLL(head1);
    printCircularLL(head2);

    head1 = mergeListsAfterMax(head1, head2);

    printCircularLL(head1);
    freeCircularLL(head1);

    return 0;
}
