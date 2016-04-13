#include<stdio.h>

struct  StackItem
{
	int index;
	int height;
}s[7];

int Histogram(int a[],int n)
{
	int i,maxArea=-1,currArea,left,top=-1;

	//struct StackItem s=(struct StackItem *)malloc(sizeof(struct StackItem)*n);

	for(i=0;i<=n;i++)
	{
	while(top>=0 && (i==n || (s[top].height)>a[i]))
	{
		if(top>0)
		left=s[top-1].index;
		else
		left=-1;

		currArea=(i-left-1)*s[top].height;
		--top;
		maxArea=currArea>maxArea ? currArea : maxArea ;
		printf(" curr %d ",currArea);
		getch();
	}
	if(i<n)
	{
		top++;
		s[top].index=i;
		s[top].height=a[i];
	}
	}

	return maxArea;
}

int main()
{
	int a[]={3,2,5,6,1,4,4};

	printf("Maximum Area = %d",Histogram(a,7));

	return 0;
}
