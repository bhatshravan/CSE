#include<stdio.h>
#include<stdlib.h>
#define max 5
void insert(),delete(),display();
char cqueue[max];
int front=0,rear=-1,count=0;
void main()
{
    system("color a");
    int ch;
    printf("Circular queue operations\n");
    for(;;)
    {
        printf("1)Insert\n2)Delete\n3)Displayrt\n4)Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2:delete();break;
            case 3:display();break;
            case 4:exit(0);break;
        }
    }
}

void insert()
{
    char ele;
    if(count==max)
        printf("Circular queue is full\n");
    else
    {
        printf("Enter element to insert:");
        fflush(stdin);
        scanf("%c",&ele);
        rear=(rear+1)%max;
        cqueue[rear]=ele;
        count++;
    }
}

void delete()
{
    char ele;
    if(count==0)
        printf("Circular queue is empty\n");
    else
    {
        ele=cqueue[front];
        front=(front+1)%max;
        count--;
        printf("Deleted element is %c\n",ele);
        putch(ele);
    }
}

void display()
{
    int i,j;
    char item;
    if(count==0)
        printf("\nCircular queue is empty\n");
    else
    {
        printf("Contents of circular queue are:\n");
        j=front;
        for(i=0;i<=count;i++)
        {
            item=cqueue[j];
            putch(item);
            j=(j+1)%max;
            printf("\t");
        }
    }
}
