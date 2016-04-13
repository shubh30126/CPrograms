#include<stdio.h>


void main()
{
	int a[8]={1,5,9,15,19};
	int b[3]={33,37,48};
	int i;
		
	merge(a,b,5,3);
	
	for(i=0;i<8;i++)
	printf(" %d ",a[i]);
}

void merge(int a[],int b[],int m,int n)
{
	int k=m+n-1,i=n-1,j=m-1;
	
	for(;k>=0;k--)
	{
		if(a[j]<b[i] || j<0)
		{
			a[k]=b[i];
			i--;
			if(i<0)
			break;
		}
		else
		{
			a[k]=a[j];
			j--;
		}
	}
	
}
