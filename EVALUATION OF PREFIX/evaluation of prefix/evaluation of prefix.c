#include<stdio.h>
#include<string.h>
int stk[10];
int top=-1;
int pop();
void push(int);
int get_type(char);
void main()
{
    char prefix[10];
    int len,val,i,opr1,opr2,res;
    printf("ENTER THE PREFIX EXPRESSION...");
    scanf("%s",prefix);
    len=strlen(prefix);
    for(i=len-1;i>=0;i--)
    {
        switch(get_type(prefix[i]))
        {
            case 0:
                val=prefix[i]-'0';
                push(val);
                break;
            case 1:
                opr1=pop();
                opr2=pop();
                switch(prefix[i])
                {
                    case '+':
                        res=opr1+opr2;
                        break;
                    case '-':
                        res=opr1-opr2;
                        break;
                    case '*':
                        res=opr1*opr2;
                        break;
                    case '/':
                        res=opr1/opr2;
                        break;
                }
                push(res);
        }
    }
    printf("\nRESULT IS %d\n",stk[0]);
}
void push(int val)
{
    stk[++top]=val;
}
int pop()
{
    return stk[top--];
}
int get_type(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    else
        return 0;
}

