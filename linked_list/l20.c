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

void frequencyCheck(struct Node* head, int freq[])
{
    struct Node* current = head;

    while(current != NULL)
    {
        freq[current->data]++;
        current = current->next;
    }
}

void printResult(struct Node* head, int freq[])
{
    struct Node* current = head;
    struct Node* check;

    while(current != NULL)
    {
        check = head;
        int printed=0;

        while(check != current)
        {
            if(check->data == current->data)
            {
                printed=1;
                break;
            }
            check = check->next;
        }
        if(!printed)
            printf("Freq(%d) = %d\n", current->data, freq[current->data]);

        current = current->next;
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
    int nodes;
    scanf("%d", &nodes);

    struct Node* head = NULL;
    createLL(&head, nodes);
    printLL(head);

    int freq[100] = {0};
    frequencyCheck(head, freq);

    printResult(head, freq);
    freeLL(head);
    
    return 0;
}