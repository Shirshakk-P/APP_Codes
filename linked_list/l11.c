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

struct Node* multipleElement(struct Node* head, int nodes, int k)
{
    struct Node* result = NULL;
    struct Node* temp = head;
    struct Node* tail = NULL;

    int counter=0;

    while(temp!= NULL && nodes--)
    {
        if(counter%k == 0)
        {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = temp->data;            
            newNode->next = NULL;

            if(result == NULL)
            {
                result = newNode;
                tail = result;
            }
            else 
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        temp = temp->next;
        counter++;
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
    int k;
    scanf("%d",&k);

    struct Node* head = NULL;
    createLL(&head, nodes);
    printLL(head);

    struct Node* multiple = multipleElement(head, nodes, k);
    printLL(multiple);

    freeLL(head);
    freeLL(multiple);
    
    return 0;
}