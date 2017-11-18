#include<stdio.h>
int tower(int n,char s,char t,char d)
{
    if(n==0)
        return 0;
    tower(n-1,s,t,d);
    printf("\nMove disk %d from %c to %c\n",n,s,d);
    tower(n-1,t,s,d);
    return 0;
}
void main()
{
    char A,B,C;
    int n;
    system("color 3a");
    printf("Enter number of disks:\n");
    scanf("%d",&n);
    printf("\nSequence of disks:\n");
    tower(n,'A','B','C');
    printf("\n");
}
