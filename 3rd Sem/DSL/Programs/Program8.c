#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *llink;
    int ssn;
    struct node *rlink;
    char name[20],dept[20],desi[20],phno[20];
    float sal;
};
typedef struct node * NODE;
NODE start=NULL;
NODE create_node()
{
    NODE ptr;
    ptr=(NODE) malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nINSUFFICIENT MEMORY");
        exit(0);
    }
    printf("ENTER employee data such as SSN,NAME,DEPARTMENT,DESIGNATION,PHNO AND SALARY\n");
    scanf("%d%s%s%s%s%f",&ptr->ssn,ptr->name,ptr->dept,ptr->desi,ptr->phno,&ptr->sal);
    ptr->llink=NULL;
    ptr->rlink=NULL;
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
        ptr->rlink=start;
        start->llink=ptr;
        start=ptr;
    }
    return start;
}
NODE insert_end(NODE start)
{
    NODE temp,ptr;
    ptr=create_node();
    if(start==NULL)
        start=ptr;
    else
    {
        temp=start;
        while(temp->rlink!=NULL)
            temp=temp->rlink;
        temp->rlink=ptr;
        ptr->llink=temp;
    }
    return start;
}
NODE delete_front(NODE start)
{
    NODE temp;
    if(start==NULL)
        printf("\n\nDoubly linked list is empty\n");
    else
    {
        temp=start;
        start=start->rlink;
        if(start!=NULL)
        {
            start->llink=NULL;
        }
        printf("\nDeleted node is ::\n");
        printf("\n|%d|%s|%s|%s|%s|%f|\n",temp->ssn,temp->name,temp->dept,temp->desi,temp->phno,temp->sal);
        free(temp);
    }
    return start;
}
NODE delete_end(NODE start)
{
    NODE temp,p;
    if(start==NULL)
    {
        printf("\nDOUBLY LINKED LIST IS EMPTY:\n");
        return NULL;
    }
    temp=start;
    if(temp->rlink==NULL)
        start=NULL;
    else
    {
        while(temp->rlink!=NULL)
            temp=temp->rlink;
        p=temp->llink;
        p->rlink=NULL;
    }
     printf("\nDeleted node is ::\n");
     printf("\n|%d|%s|%s|%s|%s|%f|\n",temp->ssn,temp->name,temp->dept,temp->desi,temp->phno,temp->sal);
    free(temp);

    return start;
}
void display(NODE start)
{
    NODE temp;
    int count=0;
    if(start==NULL)
    {
        printf("\nDOUBLY LINKED LIST IS EMPTY:\n");
        return NULL;
    }
    temp=start;
    printf("\n\nThe nodes of doubly linjked list is:\n");
    while(temp!=NULL)
    {
         printf("<->|%d|%s|%s|%s|%s|%f|\n",temp->ssn,temp->name,temp->dept,temp->desi,temp->phno,temp->sal);
         temp=temp->rlink;
         count++;
    }
    printf("The number of nodes in doubly linked list are %d",count);
}
void main()
{
    system("color a");
    int ch,n,i;
    for(;;)
    {
        printf("\n\nMENU\n\n");
        printf("\n1:CREATE DLL OF N EMPLOYEE USING INSERT END\n2:DISPLAY \n3:INSERT END\n4:DELETE END\n5:INSERT FRONT\n6:DELETE FRONT\n7:DLL AS EQUEUE\n8:EXIT\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter how many employees:");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("\nEnter info of employee %d:\n",i);
                start=insert_end(start);
            }
            break;
            case 2:display(start);break;
            case 4:start=delete_end(start);break;
            case 3:start=insert_end(start);break;
            case 5:start=insert_front(start);break;
            case 6:start=delete_front(start);break;
            case 7:printf("\n\nDEQUEUE INSERTION AND DELETION\n");
            printf("\n\nINSERTION AT FRONT OF DEQUEUE\n\n");
            start=insert_front(start);
            display(start);
            printf("\n\nINSERTION AT END  OF DEQUEUE\n\n");
            start=insert_end(start);
            display(start);
            printf("\n\nDELETEION AT FRONT OF DEQUEUE\n\n");
            start=delete_front(start);
            display(start);
            printf("\n\nDELETION AT END  OF DEQUEUE\n\n");
            start=delete_end(start);
            display(start);
            break;
            default:exit(0);
        }
    }
}

