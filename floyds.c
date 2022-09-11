#include<stdio.h>
int min(int a,int b)
{
	if(a<b)
	  return a;
	else
	  return b;
}
void allpairshortest(int cost[10][10],int A[10][10],int n)
{   
     int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++){
			A[i][j]=cost[i][j];
		}
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int i,j,n,cost[10][10],A[10][10];
	printf("enter no.of vertices:");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	allpairshortest(cost,A,n);
}
/*

0 4 11
6 0 2
3 999 0
*/
