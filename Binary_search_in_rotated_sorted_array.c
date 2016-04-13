#include<stdio.h>

void main()
{
	int a[10]={45,55,65,75,85,95,5,15,25,35},k;
	scanf("%d",&k);
	printf(" Position of %d is %d in array ",k,BinarySearch(a,0,9,k)+1);
}

int BinarySearch(int a[],int start,int finish,int data)
{
	int mid=start+((finish-start)/2);
	if(start>finish)
	return -2;
	
	if(data==a[mid])
	return(mid);
	
	if(a[start]<=a[mid])
	{
	if(data<=a[mid] && data>=a[start])
	return BinarySearch(a,start,mid,data);
	else
	return BinarySearch(a,mid+1,finish,data);	
	}
	else if(a[mid]<a[finish])
	{
		if(data>=a[mid] && data<=a[finish])
		return BinarySearch(a,mid+1,finish,data);	
		else
		return BinarySearch(a,start,mid,data);	
	}
	return -2;	
}



