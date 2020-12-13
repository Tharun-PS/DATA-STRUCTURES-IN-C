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
}*top=0,*newnode,*temp;
void main()
{
    int choice;
    printf("STACK OPERATIONS...\n");
    printf("1.push()\n2.pop()\n3.peek()\n4.exit()\n");
    printf("\nENTER THE OPERATION TO BE CARRIED IN STACK...");
    scanf("%d",&choice);
    while(choice<=0 || choice>4)
    {
        printf("\nOops...Invalid choice\n");
        printf("Enter choice again...");
        scanf("%d",&choice);
    }
    if(choice==4)
    {
        printf("\n!!!THANK YOU !!!\n");
    }
    while(choice>0 && choice<4)
    {
        switch(choice)
        {
            case 1: push();break;
            case 2: pop();break;
            case 3: peek();break;
            case 4: break;
            default: printf("Oops...Invalid choice...");break;
        }
        printf("\nENTER THE OPERATION TO BE CARRIED IN STACK...");
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
void display()
{
    temp=top;
    while(temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void push()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be pushed...");
    scanf("%d",&newnode->data);
    if(top==0)
    {
        newnode->next=0;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
    printf("Elements in the stack...");
    display();
}
void pop()
{
    if(top==0)
        printf("Stack is Empty");
    else
    {
        temp=top;
        top=top->next;
        free(temp);
        printf("Elements in the stack...");
        display();
    }
}
void peek()
{
    if(top==0)
        printf("Stack is Empty");
    else
        printf("The peek element of the stack is %d\n",top->data);
}
