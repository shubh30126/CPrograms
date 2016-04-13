#include<stdio.h>

void main()
{
	int a[]={1,3,5,7,9,11,2,4,6,8,10,12};
	int i;
	Shuffle(a,0,11);
	
	for(i=0;i<12;i++)
	printf(" %d ",a[i]);
}

void Shuffle(int a[],int beg,int end)
{
	int temp,oo,i,j,k,mid=(beg+end)/2;
	for(i=1,j=mid+1;j<=end;j++,i+=2)
	{
		for(k=j;k>i;k--)
		{
			temp=a[k];
			a[k]=a[k-1];
			a[k-1]=temp;
		}
	}
}
