#include<stdio.h>
typedef enum{lparen,rparen,plus,minus,mul,div,mod,pow,eos,op}pred;
int isp[]={0,19,12,12,13,13,13,14,0};
int icp[]={20,19,12,12,13,13,13,15,0};
char exp[50],symbol;
pred stack[50];
int top=0,n=0;
pred readtoken()
{
   // printf("READTOKEN\n");
    symbol = exp[n++];
    switch(symbol)
    {
        case '(':return lparen;
        case ')':return rparen;
        case '+':return plus;
        case '-':return minus;
        case '*':return mul;
        case '/':return div;
        case '%':return mod;
        case '^':return pow;
        case '\0':return eos;
        default : return op;
    }
}
void push(pred item)
{
    stack[++top]=item;
}
pred pop()
{
    return stack[top--];
}
void displaytoken(pred token)
{


//printf("DISPKL token\n");
    switch(token)
    {
        case plus:printf("+");break;
        case minus:printf("");break;
        case mul:printf("*");break;
        case div:printf("/");break;
        case mod:printf("%%");break;
        case pow:printf("^");break;
    }
}
void infixtopostfix()
{
    pred token1,token;
    stack[0]=eos;
    token=readtoken();
    while(token!=eos)
    {
        if(token==op)
           {
               printf("%c",symbol);
           }
        else if(token==rparen)
        {
            while(stack[top]!=lparen)
            {
                token1=pop();
                displaytoken(token1);
            }
            pop();
        }
        else
        {
            while(isp[stack[top]]>=icp[token])
            {
                token1=pop();
                displaytoken(token1);
            }
            push(token);
        }
        token=readtoken();
    }
    while((token=pop())!=eos)
        {
            displaytoken(token);
        }
        printf("\n");
}
void main()
{
    system("color a");
    printf("\nProgram to convert infix to postfix expression\n===========\n\n");
    printf("Enter infix expression:");
    gets(exp);
    printf("Postfix expression:");
    infixtopostfix();
}
