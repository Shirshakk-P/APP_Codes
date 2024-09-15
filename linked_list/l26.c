#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* friend;
    struct Node* next;
};

struct Node* createNewNode(struct Node* head, int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = val;
    newNode->friend = NULL;
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
        scanf(" %d", &n);
        *head = createNewNode(*head, n);
    }
}

struct Node* cloneList(struct Node* head) 
{
    struct Node* curr = head;

    if (head == NULL) 
    {
        return NULL;
    }

    while (curr) 
    {
        struct Node* copy = createNewNode(head, curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    curr = head;
    while (curr) 
    {
        if (curr->friend) {
            curr->next->friend = curr->friend->next;
        }
        curr = curr->next->next;  
    }

    curr = head;
    struct Node* clonedHead = head->next;
    struct Node* copy = clonedHead;

    while (curr) 
    {
        curr->next = curr->next->next;  
        if (copy->next) {
            copy->next = copy->next->next;  
        }
        curr = curr->next;
        copy = copy->next;
    }

    return clonedHead;
}


void printLL(struct Node* head)
{
    while (head) 
    {
        printf("%d-> %d; ", head->data, head->friend ? head->friend->data : -1);
        head = head->next;
    }
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

    struct Node* result = cloneList(head);
    printLL(result);

    freeLL(head);
    
    return 0;
}