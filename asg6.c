// // C Program for Implementation of Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL; //Global declaration of start node
// Function to create a new node 
struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter data for new node:");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the beginning of the singly linked list
void insertAtbeg() {
    struct Node* newNode = createNode();
    newNode->next = head;
    head = newNode;
}

// Function to insert a new element at the end of the singly linked list
void insertAtend() {
    struct Node* newNode = createNode();
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a new element at a specific position in the singly linked list
void insertAtpos() {
    
    int i,pos;
    printf("\nEnter the position to insert");
    scanf("%d",&pos);
    if (pos == 1) {
        insertAtbeg();
        return;
    }
    struct Node* newNode = createNode();
    struct Node* temp = head;
    for (i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node of the singly linked list
void deleteFrombeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = temp->next;
    free(temp);
}

// Function to delete the last node of the singly linked list
void deleteFromend() {
	 
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head,*pre=NULL;
      while (temp->next != NULL) {
    	pre=temp;
        temp = temp->next;
    }
    if(pre==NULL)//when there is only one node
     {
     	free(temp);
     	head=NULL;
	 }
	 else{
	 	   pre->next=NULL;
           free(temp);
      }
}

// Function to delete a node at a specific position in the singly linked list
void deleteAtpos() {
	int i,pos;
   
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("\nEnter the position to delete");
    scanf("%d",&pos);
    struct Node* temp = head,*pre=NULL;
    if (pos== 1) {
        deleteFrombeg();
        return;
    }
    for (i = 1; temp != NULL && i <= pos - 1; i++) {
        pre=temp;
		temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    else if(temp->next==NULL)//if it is last node
    {
    	pre->next=NULL;
    	free(temp);
	}
	else{
	     pre->next=temp->next;
          free(temp);
         }
}

// Function to print the LinkedList
void traverse() {
    struct Node* temp = head;
     if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver Code
int main() {
    
    int choice;  
    while(1)   
    {  
        
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at endt\n3.Insert at any positin\n4.Delete from Beginning\n5.Delete from end\n6.Delete node at positon\n7.Traverse\n8.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("%d",&choice);  
        switch(choice)  
         {  
            case 1:  
            insertAtbeg();      
            break;  
            case 2:  
            insertAtend();         
            break;  
            case 3:  
            insertAtpos();       
            break;  
            case 4:  
            deleteFrombeg();       
            break;  
            case 5:  
            deleteFromend();        
            break;  
            case 6:  
            deleteAtpos(); 
			case 7:
			traverse();
			break;
			case 8:exit(0);
			default: printf("\nWrong choice");
		}
    }
    return 0;
}