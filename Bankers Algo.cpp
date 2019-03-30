#include<stdio.h>
#include<conio.h>
#include <iostream>
int maxTime(int x)
{
if(x==1)
return 1;
else
{
return x+maxTime(x-1);
}

}
int main()
{
  int a[10][10],allocated[10][10],need[10][10],n,p=0,avail[10],v[10],index,d=0,k,i,flag=1,j;
	printf("Enter no. of process\n");
	scanf("%d",&n);
	printf("Enter no. of Resources\n");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{	a[i][0]=i+1;
		printf("enter Max Resource\n");
		for(j=1;j<=k;j++)
		{
		scanf("%d",&a[i][j]);
		}
		allocated[i][0]=i+1;
		printf("enter allocatedResource\n");
		for(j=1;j<=k;j++)
		{
		scanf("%d",&allocated[i][j]);
		}		
	}
	printf("Enter available resources\n");
	for(j=1;j<=k;j++)
	{
		scanf("%d",&avail[j]);
	}
	int max=maxTime(n);
	for( int i=0;i<n;i++)
	{
		need[i][0]=a[i][0];
		for(j=1;j<=k;j++)
		{
		need[i][j]=a[i][j]-allocated[i][j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=1;j<=k;j++)
		{
		printf("%d ",a[i][j]);
		}
		printf("   ");
		for(j=1;j<=k;j++)
		{
		printf("%d ",allocated[i][j]);
		}
		printf("   ");
		for(j=1;j<=k;j++)
		{
		printf("%d ",need[i][j]);
		}
		printf("\n");	
	}
		for(j=1;j<=k;j++)
		{
		printf("%d ",avail[j]);
		}
		printf("\n");
	i=0;
	for(j=0;j<=n;j++)
	{
		v[j]=0;
	}
	while(p<n)
	{
	for(j=1;j<=k;j++)
	{
		if(need[i][j]>avail[j])
		{
			flag=0;
			break;
		}
	}
	if(flag!=0)
	{
		for(j=1;j<=k;j++)
		{
		avail[j]=avail[j]+allocated[i][j];
		}
		int h =a[i][0]-1;
		v[h] = 1;
		p=p+1;
		printf("\nProcess no. %d is completed\n",(h+1));
		
	}
    
		if(i==n-1)
		{
			i=-1;
		}
		for(j=i+1;j<n;j++)
		{ 
		if(v[j]==0)
		 {
			i=j;
			break;
		 }
		}
		d=d+1;
		if(d>=max){
		break;
		}
		flag=1;
	}
if(p==n)
{
printf("all processes completed\n");
}
else{
printf("Process not completed\n");
for(int j=0;j<n;j++)
{
if(v[j]==0)
printf("%d ",j+1);
}
}
return 0;
}
