#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNewNode(struct Node* head, int val)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));	
	struct Node* temp = head;

	new_node->data = val;
	new_node->next = NULL;
	
	if(head == NULL)
	{
		return new_node;
	}
	
	while(temp->next != NULL)
	{
		temp = temp->next;

	}
	temp->next = new_node;

	return head;
}

void createLL(struct Node** head, int nodes)
{
    while(nodes--)
    {
        int n;
        scanf("%d",&n);
        *head = createNewNode(*head, n);
    }
}

struct Node* deleteNode(struct Node* head, int position)
{
    // Empty list check
    if (head == NULL)
        return NULL;

    struct Node* temp = head;

    // Deleting the head node 
    if (position == 1) 
    {
        head = temp->next;  
        free(temp);
        return head;
    }

    // Deleting non-head
    struct Node* prev = NULL;
    int currentPosition = 1;

    while (temp != NULL && currentPosition < position) 
    {
        prev = temp;
        temp = temp->next;
        currentPosition++;
    }

    if (temp != NULL && currentPosition == position) 
    {
        prev->next = temp->next; 
        free(temp); 
    }

    return head;
}

void printLL(struct Node* head)
{
	struct Node* current =  head;
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
    int pos;
    scanf("%d", &pos);
    scanf("%d", &nodes);
    
    struct Node* head = NULL;
    createLL(&head, nodes);

    printLL(head);

    // Other position Deletion
    head = deleteNode(head, pos);
    printLL(head);   

    // End deletion
    head = deleteNode(head, nodes-1);     // nodes-1 neccessary else goes to last pointer
    printLL(head); 

    // Head Deletion
    head = deleteNode(head, 1);
    printLL(head);  
    freeLL(head);  

    return 0;
}