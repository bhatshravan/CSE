
#include<stdio.h>
int a[10][10],visited[10],n;
void dfs(int u)
{
    int v;
    visited[u]=1;
    printf("%d\t",u);
    for(v=0;v<n;v++)
    {
        if(a[u][v]==1&&visited[v]==0)
            dfs(v);
    }
}

void main()
{
    system("color a");
    int source,i,j;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the graph as adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("Enter source vertex:");
    scanf("%d",&source);
    printf("\nDFS of given graph");
    printf("\nNode visited from source node %d are:\n",source);
    dfs(source);
}
