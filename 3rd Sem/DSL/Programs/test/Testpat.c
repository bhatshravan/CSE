#include<stdio.h>
void main()
{
    int i,j,m=3,n,k;
    char o=' ';
    while(m<=5)
    {
        if(m==3)
        printf("  *");
        else if(m%2==0)
        {
            for(k=1;k<=4;k++)
            if(k%2==0)
                printf("*");
            else
                printf(" ");

        }
        else
        {
            for(k=1;k<=5;k++)
            {
                if(k%2==0)
                    printf(" ");
                else
                    printf("*");
            }
        }
        m=m+1;
        printf("\n");
    }}
