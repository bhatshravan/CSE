#include<stdio.h>
#include<stdlib.h>
struct node
{
    char usn[12],name[20],branch[10],phno[15];
    int sem;
    struct node * link;
};
typedef struct node * NODE;
NODE start1=NULL;
NODE start=NULL;
NODE create_node()
{
    NODE ptr;
    ptr=(NODE) malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Insufficient memory");
        exit(0);
    }
    printf("\nEnter student data like USN,NAME,BRANCH,PHNO,SEM:\n");
    scanf("%s%s%s%s%d",ptr->usn,ptr->name,ptr->branch,ptr->phno,&ptr->sem);
    ptr->link=NULL;
    return ptr;
}
NODE insert_front(NODE start)
{

    NODE ptr;
    ptr=create_node();
    if(start==NULL)
        start=ptr;
    else
    {
        ptr->link=start;
        start=ptr;
    }
    return start;
}
NODE insert_end(NODE start)
{

    NODE ptr,temp;
    ptr=create_node();
    if(start==NULL)
        start=ptr;
    else
    {
        temp=start;
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=ptr;
    }
    return start;
}

NODE delete_front(NODE start)
{
    NODE temp;
    if(start==NULL)
    {
        printf("\n\nList empty\n");
    }
    else
    {
        temp=start;
        start=start->link;
        printf("|%s|%s|%s|%s|%d|\n\n",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
        free(temp);
    }
    return start;
}
NODE delete_end(NODE start)
{
    NODE p,temp;
    if(start==NULL)
    {
        printf("\n\nList empty\n");
        return;
    }
    temp=start;
    if(temp->link==NULL)
    {
        temp=start;
    }
    else
    {
        temp=start;
        while(temp->link!=NULL)
        {
            p=temp;
            temp=temp->link;
        }
        p->link=NULL;
    }
    printf("Deleted node is:\n");
    printf("\n|%s|%s|%s|%s|%d|\n\n",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
    free(temp);
    return start;
}
void display(NODE start)
{
    NODE temp;
    if(start==NULL)
        printf("\nLIST EMPTY");
    else
    {
        int count=0;
        temp=start;
        printf("\nSingly linked list is:\n\n");
        while(temp!=NULL)
        {
            printf("\n|%s|%s|%s|%s|%d|\n\n",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
            temp=temp->link;
            count++;
        }
        printf("\nNUMBER OF NODE IN LIST ::%d\n",count);

    }
}
NODE list_stack(NODE start1)
{
    int choice;
    printf("\n\nOPERATIONS ON STACK\n");
    for(;;)
    {
        printf("\nLIST AS STACK\n\n");
        printf("\n1:PUSH\n2:POP\n3:DISPLAY\n4:EXIT\n");
        printf("\n\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:start1=insert_front(start1);break;
            case 2:start1=delete_front(start1);break;
            case 3:display(start1);break;
            default:exit(0);
        }
    }
}
void main()
{
    system("color a");
    int choice,n,i;
    for(;;)
    {
    printf("\n\nSINGLY LINKED LIST OPERATIONS\n");
    printf("\nMENU\n");
    printf("\n\n!:List creation using insert front\n2:Display and count\n3:Insert at end\n4:Delete at end\n5:List as stack");
        printf("\n\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter how many student info you want to enter:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter info of student %d\n",i);
        start=insert_front(start);
    }
    break;
    case 2:display(start);break;
    case 3:start=insert_end(start);break;
    case 4:start=delete_end(start);break;
    case 5:start1=list_stack(start1);break;
            default:exit(0);
        }

    }
}
