#include<stdio.h>
#include<limits.h>

int LongestIncreasingSubsequence(int a[],int n)
{
	int point,i,prev,j,Table[n],max=INT_MIN,seq[n],count=0;
	
	for(i=0;i<n;i++)
	Table[i]=1;
	
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a[i]>a[j] && Table[i]<Table[j]+1)
			Table[i]=Table[j]+1;
	
	for(i=0;i<n;i++)
		if(max<Table[i])
		{
		max=Table[i];	
		point=i;
		}
	
	
	count=max-1;
	seq[count--]=a[point];
	prev=point;
	for(i=point-1;i>=0;i--)
	{	
	if(Table[prev]-1==Table[i])
	{
	seq[count--]=a[i];
	prev=i;
	}
	}
	printf("\n\n LIS is \n\n ");

	for(i=0;i<max;i++)
	printf(" %d ",seq[i]);
	
		return max;
}


int main()
{
	int a[]={5,6,2,3,4,1,5,9,8,9,5};
	int n=11,i;

	printf("\n\n Sequence is \n\n ");

	for(i=0;i<n;i++)
	printf(" %d ",a[i]);

	
	printf("\n\n LIS length is %d\n\n ",LongestIncreasingSubsequence(a,n));	
	return 0;
}
