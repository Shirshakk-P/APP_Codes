#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

struct Node* middleElement(struct Node* head)
{
    struct Node* slow = head;
    struct Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node* reverseLL(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool isPalindrome(struct Node* head)
{
    if(head == NULL || head->next == NULL)
        return true;

    struct Node* middle = middleElement(head);
    struct Node* secondHalf = reverseLL(middle);
    struct Node* firstHalf = head;
    struct Node* tempSecondHalf = secondHalf;

    bool palindrome = true;

    while(tempSecondHalf != NULL)
    {
        if(firstHalf->data != tempSecondHalf->data)
        {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecondHalf = tempSecondHalf->next;
    }
    reverseLL(secondHalf);
    
    return palindrome;
}

void printResult(bool val)
{
    if(val == 1)
        printf("palindrome\n");

    else
        printf("not a palindrome\n");
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

    bool palindrome = isPalindrome(head);
    printResult(palindrome);

    freeLL(head);
    
    return 0;
}