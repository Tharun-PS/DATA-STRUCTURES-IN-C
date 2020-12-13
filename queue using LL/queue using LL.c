#include<stdio.h>
#include<stdlib.h>
void push();
void display();
void pop();
void peek();
struct node
{
    int data;
    struct node *next;
}*rear=0,*front=0,*newnode,*temp,*prevnode;
void main()
{
    int choice;
    printf("QUEUE OPERATIONS...\n");
    printf("1.push()\n2.pop()\n3.peek()\n4.exit()\n");
    printf("\nENTER THE OPERATION TO BE CARRIED IN QUEUE...");
    scanf("%d",&choice);
    if(choice==4)
    {
        printf("\n!!!THANK YOU !!!\n");
    }
    else
    {
        while(choice<0 || choice>4)
        {
            printf("\nOops...Invalid choice\n");
            printf("Enter choice again...");
            scanf("%d",&choice);
        }
        while(choice>0 && choice<4)
        {
            switch(choice)
            {
                case 1: enqueue();break;
                case 2: dequeue();break;
                case 3: peek();break;
                case 4: break;
                default: printf("Oops...Invalid choice...");break;
            }
            printf("\nENTER THE OPERATION TO BE CARRIED IN QUEUE...");
            scanf("%d",&choice);
            while(choice<0 || choice>4)
            {
                printf("\nOops...Invalid choice\n");
                printf("Enter choice again...");
                scanf("%d",&choice);
            }
            if(choice==4)
            {
                printf("\n!!!THANK YOU !!!\n");
                break;
            }
        }
    }
}
void display()
{
    if(front==0 && rear==0)
        printf("Queue is empty");
    temp=front;
    while(temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void enqueue()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be pushed...");
    scanf("%d",&newnode->data);
    if(front==0 && rear==0)
    {
        front=rear=newnode;
        newnode->next=0;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=0;
    }
    printf("Elements in the queue...");
    display();
}
void dequeue()
{
    if(front==0 && rear==0)
        printf("Queue is Empty");
    else
    {
        temp=front;
        front=front->next;
        free(temp);
        printf("Elements in the queue...");
        display();
    }
}
void peek()
{
    if(front==0 && rear==0)
        printf("Queue is Empty");
    else
        printf("The peek element of the stack is %d\n",front->data);
}

