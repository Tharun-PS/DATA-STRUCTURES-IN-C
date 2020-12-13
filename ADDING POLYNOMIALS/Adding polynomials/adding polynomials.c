#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff,exp;
    struct node *next;
};
void  main()
{
    int i,j,d,n,hd;
    ///scanning polynomials
    printf("Enter the number of polynomials...");
    scanf("%d",&n);
    while(n<=1)
    {
        if(n<=0)
            printf("\nEnter valid no of polynomials...");
        if(n==1)
            printf("\nSingle Polynomial can't be added...Enter again...");
        scanf("%d",&n);
    }
    struct node *head[n+1],*newnode[n+1],*temp[n+1];
    int da[n];
    for(j=0;j<n;j++)
    {
        head[j]='\0';
        printf("\nPOLYNOMIAL %d\n",j+1);
        printf("\nEnter the degree...");
        scanf("%d",&d);
        while(d<0)
        {
            printf("Enter a valid degree...");
            scanf("%d",&d);
        }
        da[j]=d;
        for(i=d;i>=0;i--)
        {
            newnode[j]=(struct node *)malloc(sizeof(struct node));
            printf("Enter the coefficient of x^%d...",i);
            scanf("%d",&newnode[j]->coeff);
            newnode[j]->exp=i;
            newnode[j]->next='\0';
            if(head[j]=='\0')
            {
                head[j]=temp[j]=newnode[j];
            }
            else
            {
                temp[j]->next=newnode[j];
                temp[j]=newnode[j];
            }
        }
    }
    ///displaying the polynomials
    printf("\nThe given polynomials...\n\n");
    for(i=0;i<n;i++)
    {
        temp[i]=head[i];
        while(temp[i]->coeff==0)
        {
            temp[i]=temp[i]->next;
        }
        if(temp[i]->next!='\0' && temp[i]->coeff!=0 && temp[i]->exp==0)
            printf("%d ",temp[i]->coeff);
        if(temp[i]->next!='\0' && temp[i]->coeff!=0 && temp[i]->coeff==1 && temp[i]->exp==1)
            printf("x ");
        if(temp[i]->next!='\0' && temp[i]->coeff!=0 && temp[i]->coeff==1 && temp[i]->exp!=1)
            printf("x^%d ",temp[i]->exp);
        if(temp[i]->next!='\0' && temp[i]->coeff!=0 && temp[i]->coeff!=1 && temp[i]->exp==1)
            printf("%dx ",temp[i]->coeff);
        if(temp[i]->next!='\0' && temp[i]->coeff!=0 && temp[i]->coeff!=1 && temp[i]->exp!=1)
            printf("%dx^%d ",temp[i]->coeff,temp[i]->exp);
        temp[i]=temp[i]->next;
        while(temp[i]!='\0')
        {
            if(temp[i]!='\0' && temp[i]->coeff>0 && temp[i]->exp==0)
                printf("+ %d ",temp[i]->coeff);
            if(temp[i]!='\0' && temp[i]->coeff<0 && temp[i]->exp==0)
                printf(" %d ",temp[i]->coeff);
            if(temp[i]!='\0' && temp[i]->coeff>0 && temp[i]->coeff==1 && temp[i]->exp==1 && temp[i]->exp!=0)
                printf("+ x ");
            if(temp[i]!='\0' && temp[i]->coeff<0 && temp[i]->coeff==1 && temp[i]->exp==1 && temp[i]->exp!=0)
                printf(" x ");
            if(temp[i]!='\0' && temp[i]->coeff>0 && temp[i]->coeff==1 && temp[i]->exp!=1 && temp[i]->exp!=0)
                printf("+ x^%d ",temp[i]->exp);
            if(temp[i]!='\0' && temp[i]->coeff<0 && temp[i]->coeff==1 && temp[i]->exp!=1 && temp[i]->exp!=0)
                printf(" x^%d ",temp[i]->exp);
            if(temp[i]!='\0' && temp[i]->coeff>0 && temp[i]->coeff!=1 && temp[i]->exp==1 && temp[i]->exp!=0)
                printf("+ %dx ",temp[i]->coeff);
            if(temp[i]!='\0' && temp[i]->coeff<0 && temp[i]->coeff!=1 && temp[i]->exp==1 && temp[i]->exp!=0)
                printf(" %dx ",temp[i]->coeff);
            if(temp[i]!='\0' && temp[i]->coeff>0 && temp[i]->coeff!=1 && temp[i]->exp!=1 && temp[i]->exp!=0)
                printf("+ %dx^%d ",temp[i]->coeff,temp[i]->exp);
            if(temp[i]!='\0' && temp[i]->coeff<0 && temp[i]->coeff!=1 && temp[i]->exp!=1 && temp[i]->exp!=0)
                printf(" %dx^%d ",temp[i]->coeff,temp[i]->exp);
            temp[i]=temp[i]->next;
        }
        printf("\n");
    }
    ///finding highest degree
    hd=da[0];
    for(i=0;i<n;i++)
    {
        if(da[i]>hd)
            hd=da[i];
    }
    ///adding polynomials
    printf("\nPolynomial after addition...\n\n");
    head[n+1]='\0';
    for(i=hd;i>=0;i--)
    {
        newnode[n+1]=(struct node *)malloc(sizeof(struct node));
        newnode[n+1]->exp=i;
        newnode[n+1]->coeff=0;
        newnode[n+1]->next='\0';
        for(j=0;j<n;j++)
        {
            temp[j]=head[j];
            if(temp[j]->exp==i)
            {
                newnode[n+1]->coeff+=temp[j]->coeff;
                temp[j]=head[j];
                head[j]=head[j]->next;
                free(temp[j]);
            }
        }
        if(head[n+1]=='\0')
        {
            head[n+1]=temp[n+1]=newnode[n+1];
        }
        else
        {
            temp[n+1]->next=newnode[n+1];
            temp[n+1]=newnode[n+1];
        }
    }
    ///displaying the added polynomial
    temp[n+1]=head[n+1];
    while(temp[n+1]!='\0')
    {
        if(temp[n+1]->next!='\0' && temp[n+1]->coeff!=0 && temp[n+1]->coeff==1 && temp[n+1]->exp==1)
            printf("x ");
        if(temp[n+1]->next!='\0' && temp[n+1]->coeff!=0 && temp[n+1]->coeff==1 && temp[n+1]->exp!=1)
            printf("x^%d + ",temp[n+1]->exp);
        if(temp[n+1]->next!='\0' && temp[n+1]->coeff!=0 && temp[n+1]->coeff!=1 && temp[n+1]->exp==1)
            printf("%dx ",temp[n+1]->coeff);
        if(temp[n+1]->next!='\0' && temp[n+1]->coeff!=0 && temp[n+1]->coeff!=1 && temp[n+1]->exp!=1)
            printf("%dx^%d + ",temp[n+1]->coeff,temp[n+1]->exp);
        if(temp[n+1]->next==0 && temp[n+1]->coeff!=0)
            printf("+ %d",temp[n+1]->coeff);
        temp[n+1]=temp[n+1]->next;
    }
    printf("\n");
}
