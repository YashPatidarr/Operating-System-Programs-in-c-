#include<stdio.h>
void main()
{
	int n,p[20][10],i,j,x,temp,sum=0,time=1,time1=0,ct[20],m=0;
	printf("Enter no. of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		printf("Enter Priority arrival time and Burst time of the process\n");
		scanf("%d %d %d",&p[i][0],&p[i][1],&p[i][2]);
		p[i][3]=i+1;
		p[i][4]=0;
	}
	/*for(i=0;i<n;i++)
	{
		printf("\n%d  %d  %d",p[i][0],p[i][1],p[i][2],p[i][3]);
	}
	*/	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i][1]>p[j][1])
			{
				for(x=0;x<7;x++)
				{
					temp=p[i][x];
					p[i][x]=p[j][x];
					p[j][x]=temp;
				}
			}
			if(p[i][1]==p[j][1])
			{
				if(p[i][0]<p[j][0])
				{
					for(x=0;x<7;x++)
					{
						temp=p[i][x];
						p[i][x]=p[j][x];
						p[j][x]=temp;
					}
				}	
			}	
		}
	}
	int k=0;
	time=p[k][1];
	while(k<n)
	{
		time=time+p[k][2];
		 k=k+1;
			p[k-1][4]=time;
			p[k-1][5]=p[k-1][4]-p[k-1][1];
			p[k-1][6]=p[k-1][5]-p[k-1][2];
		for(i=k;i<n;i++)
		{
			if(p[i][1]<=time)
			{
				m=i;
			}
			else
			break;
		}
		
		for(i=k;i<=m;i++)
		{
			
		for(j=i+1;j<=m;j++)
			{
				if(p[i][0]>p[j][0])
				{
					for(x=0;x<7;x++)
					{
						temp=p[i][x];
						p[i][x]=p[j][x];
						p[j][x]=temp;
					}
				}
			
			}
			
		
		}
	
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i][3]>p[j][3])
			{
				for(x=0;x<7;x++)
				{
					temp=p[i][x];
					p[i][x]=p[j][x];
					p[j][x]=temp;
				}
			}	
		}
	}
	
	
		printf("\n		Pr	AT	BT	CT	TAT	WT");
	for(i=0;i<n;i++)
	{
		printf("\nFOR PROCESS P%d	%d	%d	%d	%d	%d	%d",p[i][3],p[i][0],p[i][1],p[i][2],p[i][4],p[i][5],p[i][6]);
	}
	
	
}

