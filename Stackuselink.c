#include <stdio.h>  

#include <stdlib.h>  

void push(int);  

void pop();  

void display();  

struct node   

{  

int val;  

struct node *next;  

};  

struct node *top=NULL;  

  

int main ()  

{  

    int choice=0;  

	int val;   

    printf("\n*********Stack operations using linked list*********\n");  

    printf("\n----------------------------------------------\n");  

    while(1)  

    {  

        printf("\n\nChose one from the below options...\n");  

        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");  

        printf("\nEnter your choice: ");        

        scanf("%d",&choice);  

        switch(choice)  

        {  

            case 1:  

                printf("Enter the value: ");  

                scanf("%d",&val);

                push(val);  

                break;  

            case 2:  

                pop();  

                break;  

            case 3:  

                display();  

                break;  

            case 4:   

                printf("Exiting....");  

                exit(0);   

            default:  

                printf("Please Enter valid choice ");  

          }

     }

	 return 0;  

}  

void push (int val)  

  {  

     

    struct node *ptr = (struct node*)malloc(sizeof(struct node));   

    if(ptr == NULL)  

     {  

        printf("stack Overflow");   

     }  

    else   

     {  

            ptr->val = val;  

            ptr->next=top;  

            top=ptr;   

            printf("Item pushed %d",top->val);  

      }  

  }  

  

void pop()  

{  

    int item;  

    struct node *ptr;  

    if (top == NULL)  

    {  

        printf("\nUnderflow");  

    }  

    else  

    {  

        item = top->val;  

        ptr = top;  

        top = top->next;  

        free(ptr);  

        printf("\nItem popped %d ",item);  

          

    }  

}  

void display()  

{  

    int i;  

    struct node *ptr;  

    ptr=top;  

    if(ptr == NULL)  

    {  

        printf("Stack is empty\n");  

    }  

    else  

    {  

        printf("Printing Stack elements \n");  

        while(ptr!=NULL)  

        {  

            printf("%d\t",ptr->val);  

            ptr = ptr->next;  

        }  

    }  

}
