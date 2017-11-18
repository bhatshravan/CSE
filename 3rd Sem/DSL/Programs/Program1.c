#include<stdio.h>
#define MAX 10

int a[MAX],i,n;

void create(),display(),delete(),insert();
int main();
int main(void)
{
    system("color a");
    int ch;
    printf("\nImplementation of Array operations\n");
    for(;;)
    {
        printf("\n====\nMENU\n====\n");
        printf("\n1:CREATE\n2:DISPLAY\n3:INSERT\n4:DELETE\n5:EXIT\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();break;
            case 2:display();break;
            case 3:insert();break;
            case 4:delete();break;
            case 5:exit(0);
            default:printf("\nWrong command\n");
        }
    }
}
void create()
{
    printf("\nArray creation\n");
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

}
void display()
{
    printf("\nArray display\n");
    printf("Elements of array are:\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
}
void insert()
{
    int ele,pos;
    printf("\nElement insertion\n");
    if(n==MAX)
        printf("Array is full,insertion not possible\n");
    else
    {
        printf("\nEnter position of element less than or equal to n+1 :\n");
        scanf("%d",&pos);
        if(pos<=n+1)
        {
            printf("\nEnter element to insert:\n");
            scanf("%d",&ele);
            for(i=n-1;i>=pos-1;i--)
                a[i+1]=a[i];
            a[pos-1]=ele;
            ++n;

        }
        else
            printf("Invalid position\n=======\n");
    }


}
void delete()
{
    int item,pos;
    printf("\nElement deletion\n");
    if(n==0)
        printf("Array is empty,deletion not possible\n");
    else
    {
        printf("\nEnter position of element less than or equal to n+1 to delete:\n");
        scanf("%d",&pos);
        if(pos<=n)
        {
            item=a[pos-1];
            printf("\nDeleted item is %d",item);
            --n;
            for(i=pos-1;i<n;i++)
                a[i]=a[i+1];

        }
        else
            printf("Invalid position\n=======\n");

    }
}
