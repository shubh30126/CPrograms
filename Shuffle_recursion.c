#include<stdio.h>

void main()
{
	int a[]={1,3,5,7,9,11,13,15,2,4,6,8,10,12,14,16};
	int i;
	Shuffle(a,0,15);
	
	for(i=0;i<16;i++)
	printf(" %d ",a[i]);
}

void Shuffle(int a[],int beg,int end)
{
	int mid,i;
	if(end-beg==1)
	return;
	
	mid=(beg+end)/2;
	
	swap(a,beg,mid);

	Shuffle(a,beg,mid);

	Shuffle(a,mid+1,end);		

}

void swap(int a[],int beg,int mid)
{
	int i,temp,length=((mid-beg)/2)+1;
	for(i=0;i<length;i++)
	{
		temp=a[mid+i+1];
		a[mid+i+1]=a[mid+i+1-length];
		a[mid+i+1-length]=temp;
	}
}


