#include<stdio.h>
#include<stdlib.h>

struct Node{
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

void createLL(struct Node** head)
{
	int n=0;
	while(1)
	{
		scanf("%d",&n);
		if(n == -111)
			break;

		*head = createNewNode(*head, n);
	}
}

struct Node* insertAtPosition(struct Node* head, int nodes, int val, int position)
{
	struct Node* temp = head;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;

	int count=1;

	if(position == 1)
	{
		if(head == NULL)
		{
			newNode->next = NULL;
			return newNode;
		}
		else 
		{
			newNode->next = head;
			return newNode;
		}
	}

	while(temp != NULL && count < position-1)
	{
		temp = temp->next;
		count++;
	}

	if(temp == NULL)
	{
		free(newNode);
		return head;
	}

	newNode->next = temp->next;
	temp->next = newNode;

	return head;
}

int length(struct Node* head)
{
	int val=0;
	struct Node* temp = head;

	while(temp != NULL)
	{
		val++;
		temp = temp->next;
	}
	return val;
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
	// int nodes;
	// scanf("%d", &nodes);
	int value;
	scanf("%d", &value);
	int position;
	scanf("%d", &position);

	struct Node* head = NULL;
	createLL(&head);

	int nodes = length(head);  	       

	head = insertAtPosition(head, nodes, value, 1);
	printLL(head);
	// head = insertAtPosition(head, nodes, value, nodes);
	// printLL(head);
	// head = insertAtPosition(head, nodes, value, position);
	// printLL(head);
	freeLL(head);

	return 0;
}
