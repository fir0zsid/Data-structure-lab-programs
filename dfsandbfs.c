#include <stdio.h>
int n,c,am[100][100],visited[100],q[100],f=0,r=-1;
void dfs(int c)
{
	printf("\t%d",c);
	visited[c]=1;
	int i=0;
	for(i=0;i<n;i++)
	{
		if(!visited[i]&&am[c][i]==1)
		{
			dfs(i);
		}
	}
}

void bfs()
{
	printf("\t%d",c);
	visited[c]=1;
	int i;
	for(i=0;i<n;i++);
	{
		if(!visited[i]&&am[c][i]==1)
		{
			q[++r]=i;
		}
	}

	if(f<=r)
	{
		visited[q[f]]=1;
		bfs(f++);
	}

			
}

int main()
{
	int choice,i,j;
	printf("\nEnter the number of cities:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("\n%d",&am[i][j]);
		}
	}
		
	printf("\nWhich city?");
	scanf("%d",&c);
	for(i=0;i<n;i++)
	{
		q[i]=0;
		visited[i]=0; //marking as not visited
	}
		
	while(1)
	{
		printf("\n GRAPTH OPERATIONS\n-------------------------\n");
		printf("\n1.Depth first search\n2.Breadth first search\n3.Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: dfs(c);
				break;
			case 2: bfs(c);
				break;
			case 3: return 0;
			default: printf("\nInvalid choice");
		}
	}
	return 0;
}
