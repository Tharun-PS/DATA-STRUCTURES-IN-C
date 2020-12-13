#include<stdio.h>
#include<stdlib.h>
void create();
void print();
void insertatbegining();
void insertatend();
void insertatposition();
void deleteatbegining();
void deleteatend();
void deleteatposition();
struct node
{
    int data;
    struct node *next;
}*head='\0',*newnode,*temp,*prevnode;
void main()
{
    printf("...CREATING LINKED LIST...\n");
    create();
    printf("\n...PRINTING LINKED LIST...\n");
    print();
    printf("\n...INSERTING ELEMENT AT BEGINING...\n");
    insertatbegining();
    printf("\n...INSERTING ELEMENT AT END...\n");
    insertatend();
    printf("\n...INSERTING ELEMENT AT A SPECIFIC POSITION...\n");
    insertatposition();
    printf("\n...DELETING ELEMENT AT BEGINING...\n");
    deleteatbegining();
    printf("\n...DELETING ELEMENT AT END...\n");
    deleteatend();
    printf("\n...DELETING ELEMENT AT A SPECIFIC POSITION...\n");
    deleteatposition();
}
void create()
{
    int i,n;
    printf("Enter the number of elements...: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element %d : ",i);
        scanf("%d",&newnode->data);
        newnode->next='\0';
        if(head=='\0')
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
}
void print()
{
    temp=head;
    printf("The elements in the list are...\n");
    while(temp!='\0')
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void insertatbegining()
{
    int a;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be inserted : ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    print();
}
void insertatend()
{
    int a;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be inserted : ");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!='\0')
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next='\0';
    print();
}
void insertatposition()
{
    int a,j,i;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be inserted : ");
    scanf("%d",&newnode->data);
    printf("Enter the position of insertion : ");
    scanf("%d",&j);
    if(j>0)
    {
        temp=head;
        for(i=1;i<j-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        print();
    }
    else
    {
        printf("Enter positive number as position...");
    }
}
void deleteatbegining()
{
    temp=head;
    head=head->next;
    free(temp);
    print();
}
void deleteatend()
{
    temp=head;
    while(temp->next!='\0')
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next='\0';
    free(temp);
    print();
}
void deleteatposition()
{
    int a;
    printf("Enter the element to be deleted : ");
    scanf("%d",&a);
    temp=head;
    while(temp->data!=a)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=temp->next;
    free(temp);
    print();
}
