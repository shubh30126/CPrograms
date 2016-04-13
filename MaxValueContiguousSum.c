#include<stdio.h>

int Max(int a,int b,int c)
{
	return (a>b ? (a>c ? a : c) : (b>c ? b : c));
}

int MaxValueContiguousSum(int a[],int l,int r)
{
int MaxLeftSum=0,MaxRightSum=0,LeftBorderSum=0,RightBorderSum=0;
int MaxLeftBorderSum=0,MaxRightBorderSum=0,mid,i;

if(l==r)
return(a[l]>0 ? a[l] : 0);

mid=l+(r-l)/2;

MaxLeftSum=MaxValueContiguousSum(a,l,mid);
MaxRightSum=MaxValueContiguousSum(a,mid+1,r);

for(i=mid;i>=l;i--)
{
	LeftBorderSum+=a[i];
	if(LeftBorderSum>MaxLeftBorderSum)
	MaxLeftBorderSum=LeftBorderSum;
}
for(i=mid+1;i<=r;i++)
{
	RightBorderSum+=a[i];
	if(RightBorderSum>MaxRightBorderSum)
	MaxRightBorderSum=RightBorderSum;
}

return Max(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);	
}

int main()
{
	int a[]={1,-3,4,-2,-1,6};
	
	printf("Max sum is %d\n\n",MaxValueContiguousSum(a,0,5));
	
	return 0;
}
