#include <stdio.h>
#include<string.h>
#define MAX 100
char st[MAX];
int top=-1;
void push(char st[], char);
char pop(char st[]);
void infixtopostfix(char source[], char target[]);
int getpriority(char);
void main()
{
    char infix[100],postfix[100];
    printf("...ENTER INFIX EXPRESSION...");
    scanf("%s",infix);
    strcpy(postfix,"");
    infixtopostfix(infix,postfix);
    printf("...POSTFIX EXPRESSION...");
    printf("%s\n",postfix);
}
void infixtopostfix(char source[],char target[])
{
    int i=0,j=0;
    char temp;
    strcpy(target,"");
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(st,source[i]);
            i++;
        }
        else if(source[i] == ')')
        {
            while(top!=-1 && st[top]!='(')
            {
                target[j]=pop(st);
                j++;
            }
            if(top==-1)
            {
                printf("INVALID EXPRESSION");
                exit(1);
            }
            temp=pop(st);
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' || source[i]=='%')
        {
            while(top!=-1 && st[top]!='(' && getpriority(st[top])>getpriority(source[i]))
            {
                target[j]=pop(st);
                j++;
            }
            push(st,source[i]);
            i++;
        }
        else
        {
            printf("\nINCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
    }
    while(top!=-1 && st[top]!='(')
    {
        target[j]=pop(st);
        j++;
    }
    target[j]='\0';
}
int getpriority(char op)
{
    if(op=='/' || op== '+' || op=='%')
        return 1;
    else if (op=='+' || op=='-')
        return 0;
}
void push(char st[], char val)
{
    if(top==MAX-1)
        printf("\nSTACK OVERFLOW");
    else
    {
        top++;
        st[top]=val;
    }
}
char pop(char st[])
{
    char val=' ';
    if(top==-1)
        printf("\nSTACK UNDERFLOW");
    else
    {
        val=st[top];
        top--;
    }
    return val;
}
