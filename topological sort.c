#include<stdio.h>
int visited[10],stack[15],adj[10][10],n,top=-1,i,j,w;
void dfs(int);
void push(int x)
{ 
 top++;
 stack[top]=x; 	
}
void print()
{
  for(i=top;i>=0;i--){
  	printf("%d ",stack[i]);
  }
}
void topological()
{  for(i=1;i<=n;i++){
	visited[i]=0;
    }
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		   dfs(i);
	}
	print();
}
void dfs(int v)
{
	visited[v]=1;
	for(w=1;w<=n;w++){
		if(adj[v][w]==1){
		if(!visited[w])
		   dfs(w);
	}
	}
	push(v);
}
int main()
{
  printf("Enter no.of vertices: ");
  scanf("%d",&n);
  printf("Enter adjacency matrix: ");
  for(i=1;i<=n;i++){
  	for(j=1;j<=n;j++){
	  	scanf("%d",&adj[i][j]);
	  }
  }	
  topological();
  return 0;
}
/*
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 1 0 0 0 0
1 1 0 0 0 0
1 0 1 0 0 0
*/
