// #include <stdio.h>
// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
//     int data;
//     struct Node* next;
// };

// struct Node* createNewNode(struct Node* head, int val)
// {
//     struct Node* new = (struct Node*)malloc(sizeof(struct Node));
//     new->data=val;
//     new->next=NULL;

//     if(head==NULL)
//     {
//         return new;
//     }

//     struct Node* temp = head;

//     while(temp->next!=NULL)
//     {
//         temp=temp->next;
//     }
//     temp->next=new;
//     return head;
// }

// struct Node* circular(struct Node* head)
// {
//     struct Node* temp=head;

//     while(temp->next!=NULL)
//     {
//         temp=temp->next;
//     }

//     temp->next=head;
//     return head;
// }

// int length(struct Node* head)
// {
//     if(head==NULL)
//     {
//         return 0;
//     }

//     int count=0;
//     struct Node* temp =head;

//     do
//     {
//         count++;
//         temp=temp->next;
//     }while(temp != head);

//     return count;
// }

// void list(struct Node* head, int k, int len)
// {
//     if(head == NULL)
//         return;

//     struct Node* temp = head;
//     //struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
//     //curr->data = head->data;
//     //curr->next = NULL;
//     //len--;

//     int count = 1;
//     //temp=temp->next;

//     //while(len>0)
//     do
//     {
//         if(count%k == 0)
//         {
//             //struct Node* new = (struct Node*)malloc(sizeof(struct Node));
//             //new->data=temp->data;
//             //curr->next=new;
//             //curr=curr->next;
//             printf("%d -> ", temp->data);
//             len--;
//         }
//         temp=temp->next;
//         count++;

//         // if(temp == head)
//         //     break;

//     }while(len>0 && temp != head);

//     //curr->next=NULL;
    
//     printf("NULL\n");
// }    

// void printLL(struct Node* head)
// {
//     struct Node* temp = head;
//     while(temp!=NULL)
//     {
//         printf("%d -> ",temp->data);
//         temp=temp->next;
//     }
//     printf("NULL\n");
// }

// void createCircularLL(struct Node** head, int nodes)
// {
//     while(nodes--)
//     {
//         int n;
//         scanf("%d", &n);
//         *head = createNewNode(*head, n);
//     }
// }

// void freeCLL(struct Node* head)
// {
//     if(head == NULL)
//         return;

//     struct Node* current = head;
//     struct Node* nextNode; 

//     do
//     {
//         nextNode = current->next;
//         free(current);
//         current = nextNode;
//     }
//     while(current != head);
// }

// int main()
// {
//     struct Node* head=NULL;
//     int n;
//     scanf("%d",&n);

//     createCircularLL(&head, n);

//     int k;
//     scanf("%d", &k);

//     int len = length(head);
//     struct Node* new_node = NULL;

//     new_node = circular(head);
//     list(new_node,k,len);

//     //printLL(new_node);

//     freeCLL(new_node);
    
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createLinkedList(struct Node* head, int val){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    if(head==NULL){
        return new;
    }
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    return head;
}

struct Node* circular(struct Node* head){
    struct Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    return head;
}

int length(struct Node* head){
    if(head==NULL){
        return 0;
    }
    int count=0;
    struct Node* temp =head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void list(struct Node* head, int k, int len){
    struct Node* temp = head;
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr->data=head->data;
    curr->next=NULL;
    printf("%d -> ",curr->data);
    len--;
    int cnt = 1;
    temp=temp->next;
    while(len>0){
        if(cnt%k==0){
            struct Node* new = (struct Node*)malloc(sizeof(struct Node));
            new->data=temp->data;
            curr->next=new;
            curr=curr->next;
            printf("%d -> ",curr->data);
            len--;
        }
        temp=temp->next;
        cnt++;
    }
    curr->next=NULL;
    printf("NULL");
}
    

void print(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;
    int n;
    scanf("%d",&n);
    while(n--){
        int v;
        scanf("%d",&v);
        head = createLinkedList(head,v);
    }
//  print(head);

    int k;
    scanf("%d",&k);
    int len = length(head);
    //printf("%d     \n ",len);
    struct Node* new_node = NULL;
    new_node = circular(head);
//  print(new_node);
    list(new_node,k,len);
//  print(head);
        return 0;
}