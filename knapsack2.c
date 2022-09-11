#include<stdio.h>
int max(float pw[10],int n)
{   int i,max1=1;
	for(i=2;i<=n;i++){
		if(pw[max1]<pw[i])
		   max1=i;
	}
	return max1;
}
int main()
{
	int i,n,m,p[10],w[10],index;
	float pw[10],maxprofit,x[10];
	printf("Enter no.of items:");
	scanf("%d",&n);
	printf("Enter capacity of knapsack: ");
	scanf("%d",&m);
	printf("Enter profit values of objects: ");
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	printf("Enter weight values of objects: ");
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(i=1;i<=n;i++){
		pw[i]=(float)p[i]/w[i];
		x[i]=0;
	}
	for(i=1;i<=n;i++){
		printf("%f  ",pw[i]);
	}
	for(i=1;i<=n;i++){
		index=max(pw,n);
		pw[index]=-1;
		if(w[index]>m)
		   break;
		else{
			x[index]=1.0;
			m=m-w[index];
		}
	}
	if(i<n)
	  x[index]=(float)m/w[index];
	printf("\nOptimized solution is: \n");
	for(i=1;i<=n;i++){
		printf("%f  ",x[i]);
	} 
	for(i=1;i<=n;i++){
		maxprofit+=x[i]*p[i];
	}
	printf("maximized profit is: %f\n",maxprofit);
	
}
