#include <stdio.h>
#include <stdlib.h>

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

int getLength(struct Node* head) 
{
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

void swapKthNode(struct Node** head, int k) 
{
    int length = getLength(*head);
    
    if (k > length || 2*k - 1 == length) {
        return;
    }

    struct Node *x_prev = NULL, *x = *head;
    struct Node *y_prev = NULL, *y = *head;
    
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    for (int i = 1; i < length - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev)
        x_prev->next = y;
    else
        *head = y; 

    if (y_prev)
        y_prev->next = x;
    else
        *head = x;  

    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
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

void printLL(struct Node* head) 
{
    while (head) 
    {
        printf("%d-> ", head->data);
        head = head->next;
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

    int k;
    scanf("%d", &k);

    swapKthNode(&head, k);

    printLL(head);
    freeLL(head);

    return 0;
}
