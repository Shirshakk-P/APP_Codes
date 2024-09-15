#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coefficient;
    int power;
    struct Node* next;
};

struct Node* createNewNode(struct Node* head, int coeff, int pow)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->coefficient = coeff;
    newNode->power = pow;
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
        int c;
        int p;
        scanf(" %d %d", &c, &p);
        *head = createNewNode(*head, c, p);
    }
}

struct Node* addPolynomials(struct Node* head1, struct Node* head2)
{
    struct Node* result = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->power == head2->power)
        {
            int sumC = head1->coefficient + head2->coefficient;
            if(sumC == 0)
            {
                result = createNewNode(result, sumC, head1->power);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->power > head2->power)
        {
            result = createNewNode(result, head1->coefficient, head1->power);
            head1 = head1->next;
        }
        else 
        {
            result = createNewNode(result, head2->coefficient, head2->power);
            head2 = head2->next;
        }
    } 

    while(head1 != NULL)
    {
        result = createNewNode(result, head1->coefficient, head1->power);
        head1 = head1->next;
    }

    while(head2 != NULL)
    {
        result = createNewNode(result, head2->coefficient, head2->power);
        head2 = head2->next;
    }

    return result;
}


void printLL(struct Node* head)
{
    struct Node* current = head;
    while(current != NULL)
    {
        printf("| %d| %d|->", current->coefficient, current->power);
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
    int nodes1, nodes2;
    scanf("%d", &nodes1);

    struct Node* head1 = NULL;
    createLL(&head1, nodes1);
    printLL(head1);

    scanf("%d", &nodes2);

    struct Node* head2 = NULL;
    createLL(&head2, nodes2);
    printLL(head2);

    struct Node* result = NULL;
    result = addPolynomials(head1, head2);

    printLL(result);
    freeLL(result);
    
    return 0;
}