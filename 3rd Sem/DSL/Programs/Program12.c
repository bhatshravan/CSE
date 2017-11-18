#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct record
{
    int empno,flag;
    char name[10];
}emp[100];

int hash(int m)
{
    int r;
    r=m%100;
    return r;
}
void main()
{
    system("color a");
    int m,k,eno,loc,i,n,j;
    char name[10];
    FILE *in;
    printf("Enter number of records to read:");
    scanf("%d",&n);
    in=fopen("input.txt","r");
    if(n<=10)
    {

        for(k=0;k<100;k++)
            emp[k].flag=0;
            for(i=0;i<n;i++)
            {
                fscanf(in,"%d%s",&eno,name);
                loc=hash(eno);
                if(emp[loc].flag==0)
                {
                    printf("\nRecord %d mapped to address %d\n",i,loc);
                    emp[loc].empno=eno;
                    emp[loc].flag=1;
                    strcpy(emp[loc].name,name);
                }
                else
                {
                    printf("collision occured for record %d resolved using liner probing\n",i);
                    for(j=loc+1;j<100;j++)
                    {
                        if(emp[j].flag==0)
                        {
                            printf("cRecord %d mapped to address %d by linear probing\n",i,j);
                            emp[j].empno=eno;
                            emp[j].flag=1;
                            strcpy(emp[j].name,name);
                            break;
                        }
                    }
                    if(j>=100)
                    {
                        printf("Hash table is full");
                        printf("\n-----\n");
                    }
                }
            }
            fclose(in);
                        printf("Hash table content is:");

                        for(i=0;i<100;i++)
                        {
                            if(emp[i].flag==1)
                                printf("\n%d\t%d\t%s",i,emp[i].empno,emp[i].name);
                            else
                                printf("\n######\n");
                        }
                    }
                else
                    printf("\nFile containing only 10 records\n");
                }

