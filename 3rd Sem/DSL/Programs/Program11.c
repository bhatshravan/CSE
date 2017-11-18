
#include<stdio.h>
void bfs(int a[10][10],int n,int u)
{
    int front,rear,q[10],visited[10],v,i;
    for(i=0;i<n;i++)
        visited[i]=0;
    front=0;
    rear=-1;
    printf("\nThe nodes visited from %d are:\n",u);
    q[++rear]=u;
    visited[u]=1;
    printf("%d\t",u);
    while(front<=rear)
    {
        u=q[front++];
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1&&visited[v]==0)
            {
                printf("%d\t",v);
                visited[v]=1;
                q[++rear]=v;
            }
        }
    }
}

void main()
{
    system("color a");
    int a[10][10],n,source,i,j;
    printf("\nEnter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the graph as adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter source vertex:");
    scanf("%d",&source);
    printf("\nBFS of given graph");
    bfs(a,n,source);
}
