#include<stdio.h>
#include<limits.h>

#define MAXCOST 5000
#define TOTALDENOM 6
int rs;
int Table[MAXCOST];
int denomination[TOTALDENOM]={1,2,5,10,25,50};
int used[MAXCOST][TOTALDENOM];

int MakeChange(int n)
{
	int i,ans,m;
	if(n==0)
	return 0;
	
	if(Table[n]!=-1)
	return Table[n];
	
	ans=INT_MAX;
	for(i=0;i<TOTALDENOM;i++)
	{
		if((n-denomination[i])>=0)
		{
		m=MakeChange(n-denomination[i]);
		ans=(ans>m)?m:ans;	
		
		used[n][i]=m+1;
		}
	}
	
	return (Table[n]=ans+1);	
}

void Display(int coins)
{
int min=INT_MAX,i,sum=0,count=0;	
int useddenom[TOTALDENOM],perm[TOTALDENOM];

	for(i=0;i<TOTALDENOM;i++)
	min=(min>used[rs][i] && used[rs][i]!=0)?used[rs][i]:min;
	
	for(i=0;i<TOTALDENOM;i++)
	{
		if(used[rs][i]==min)
		useddenom[i]=min;
		else
		useddenom[i]=0;
	}
	
	for(perm[5]=0;perm[5]<=useddenom[5];perm[5]++)
	for(perm[4]=0;perm[4]<=useddenom[4];perm[4]++)
	for(perm[3]=0;perm[3]<=useddenom[3];perm[3]++)
	for(perm[2]=0;perm[2]<=useddenom[2];perm[2]++)
	for(perm[1]=0;perm[1]<=useddenom[1];perm[1]++)
	for(perm[0]=0;perm[0]<=useddenom[0];perm[0]++)
	{
	sum=0;
	for(i=0;i<TOTALDENOM;i++)
	sum+=perm[i];
	if(sum==coins)
	{
	sum=0;
	for(i=0;i<TOTALDENOM;i++)
	sum+=perm[i]*denomination[i];
	if(sum==rs)
	{
	for(i=0;i<TOTALDENOM;i++)
	if(useddenom[i]!=0)
	printf("\n %d*%d ",perm[i],denomination[i]);
	return;
	}
	}

	}
}




int main()
{
	int j,i,coins;
	printf("\nEnter the rupee\t");
	scanf("%d",&rs);
	
	for(i=0;i<MAXCOST;i++)
	Table[i]=-1;
			
	printf("\n\nCoins needed %d\n",coins=MakeChange(rs));
	
	Display(coins);	

/*Matrix of Calculation*/
		
/*	printf("\n-------");
	for(j=0;j<TOTALDENOM;j++)
	printf(" %2d ",denomination[j]);
	printf("\n");
	for(i=1;i<=rs;i++,printf("\n"))
	{
	printf(" Rs %2d ",i);	
	for(j=0;j<TOTALDENOM;j++)
	printf(" %2d ",used[i][j]);
	}
*/
return 0;
}
