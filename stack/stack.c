#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
void display();
void remove_duplicates();
int stack_array[10];
int top=-1;
void main()
{
    int choice;
    printf("STACK OPERATIONS...\n");
    printf("1.push()\n2.pop()\n3.peek()\n4.remove duplicates()\n5.exit\n");
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
        printf("\n\nENTER THE OPERATION TO BE CARRIED IN STACK...");
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
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack_array[i]);
    }
}
void push()
{
    int x;
    if(top==9)
        printf("Stack Overflow \n");
    else if(top==-1)
    {
        printf("Enter the element to be inserted in the stack: ");
        scanf("%d",&x);
        top=top+1;
        stack_array[top]=x;
        display();
    }
    else
    {
        printf("Enter the element to be inserted in the stack: ");
        scanf("%d",&x);
        top=top+1;
        stack_array[top]=x;
        display();
    }
}
void pop()
{
    int x;
    if(top==-1)
    {
        printf("Stack Underflow...\n");
    }
    else
    {
        x=stack_array[top];
        top--;
        printf("Element popped out from stack...%d\n",x);
    }
    display();
}
void peek()
{
    if(top==-1)
    {
        printf("Stack underflow...");
    }
    else
    {
        printf("The peek element in the stack is...%d",stack_array[top]);
    }
}
void remove_duplicates()
{
    int i,j;
    for(j=0;j<9;j++)
    {
        for (i=top-1;i>=0;i--)
        {
            if (stack_array[top]==stack_array[i])
            {
                pop();
            }
        }
    }
    display();
}
