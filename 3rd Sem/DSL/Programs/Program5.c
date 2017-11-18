#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define STACK_SIZE 50

int stack[STACK_SIZE];
int top=-1;
void push(int a)
{
    stack[++top]=a;
    return;
}
int pop()
{
    return (stack[top--]);
}
int eval(char s[])
{
    int i,temp,op1,op2,result;
    char symbol[1];
    for(i=0;i<strlen(s);i++)
    {
        if(isalnum(s[i]))
        {
            if(isdigit(s[i]))
            {
                symbol[0]=s[i];
                temp=atoi(symbol);
                push(temp);
            }
            else
            {
            printf("\nEnter value of %c:",s[i]);
            scanf("%d",&temp);
            push(temp);
            }
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(s[i])
            {

                case '^':result=pow(op1,op2) ;break;
                case '*':result= op1*op2;break;
                case '/':
                    if(op2==0)
                    {
                        printf("Invalid expr");
                        exit(0);
                    }
                    else
                        result=op1/op2;
                    break;
                case '%':
                    if(op2==0)
                    {
                        printf("Invalid expression");
                        exit(0);
                    }
                    else
                        result=op1%op2;
                    break;
                case '+':result= op1+op2;break;
                case '-':result=op1-op2 ;break;
                default:printf("Invalid expr");
                        exit(0);
            }
            push(result);
        }
    }
    result=pop();
    if(top!=-1)
    {
        printf("Invalid expr");
        exit(0);
    }
    return result;
}
void main()
{

    system("color a");
    char s[50];
    printf("Evaluation of postfix expression");
    printf("\nEnter postfix expression:\n");
    gets(s);
    printf("Result of evaluation is %d",eval(s));
}
