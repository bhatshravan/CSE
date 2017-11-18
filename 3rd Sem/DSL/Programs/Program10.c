#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

typedef struct node* NODE;
NODE root=NULL;
NODE create_node()
{
    NODE ptr;
    ptr=(NODE) malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nInsufficient Memory\n");
        exit(0);
    }
    else
    {
        printf("Enter data:");
        scanf("%d",&ptr->data);
        ptr->lchild=ptr->rchild=NULL;
    }
    return ptr;
}

NODE create_bst(NODE root)
{
    NODE ptr,temp,p;
    ptr=create_node();
    if(root==NULL)
    {
        root=ptr;
        return root;
    }
    p=NULL;
    temp=root;
    while(temp!=NULL)
    {
        p=temp;
        if(ptr->data==temp->data)
        {
            printf("Duplicate items are not allowed\n");
            free(ptr);
            return root;
        }
        if(ptr->data<temp->data)
            temp=temp->lchild;
        else
            temp=temp->rchild;
    }
    if(ptr->data<p->data)
        p->lchild=ptr;
    else
        p->rchild=ptr;
    return root;
}

void inorder(NODE t)
{
    if(t!=NULL)
    {
        inorder(t->lchild);
        printf("%d\t",t->data);
        inorder(t->rchild);
    }
}

void preorder(NODE t)
{
    if(t!=NULL)
    {
        printf("%d\t",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void postorder(NODE t)
{
    if(t!=NULL)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d\t",t->data);
    }
}

void traverse(NODE root)
{
    if(root==NULL)
        printf("Empty tree\n\n");
    else
    {
        printf("\nPreorder traversal:\t");
        preorder(root);
        printf("\nInorder traversal:\t");
        inorder(root);
        printf("\nPostorder Traversal:\t");
        postorder(root);
    }
}

void search_bst(NODE root)
{
    int key,flag=0;
    NODE temp;
    printf("Enter key to search in bst:");
    scanf("%d",&key);
    if(root==NULL)
    {
        printf("BST is empty\n");
        return;
    }
    else
    {
        temp=root;
        while(temp!=NULL)
        {
            if(key==temp->data)
            {
                printf("Key found\n");
                flag=1;
                break;
            }
            else if(key<temp->data)
                temp=temp->lchild;
            else
                temp=temp->rchild;
        }
    }
    if(flag==0)
        printf("Key not found");
}
void main()
{
    system("color a");
    int ch;
    for(;;)
    {
        printf("Operation on BST:\n\n");
        printf("1:Create BST\n2:Traverse BST\n3:Search \n4:EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:root=create_bst(root);
            break;
            case 2:traverse(root);break;
            case 3:search_bst(root);break;
            default:exit(0);
        }
    }
}
