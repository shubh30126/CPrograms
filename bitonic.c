#include<stdio.h>

int bitonic(int a[],int last)
{
int first=0,mid;
		if(first==last)
		return first;
		if(first==last-1)
		return (a[first]>a[last]?first:last);
	
	while(first<=last)
	{
		mid = (first+last)/2;	
	if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
	return mid;
	else if(a[mid]>a[mid-1] && a[mid]<a[mid+1])
	first=mid+1;
	else if(a[mid]<a[mid-1] && a[mid]>a[mid+1])
	last=mid-1;	
	}
return -1;
}	

int main()
{
	int a[8]={5,6,5,4,3,2,1,0};
	
	printf(" %d ",bitonic(a,7));
	
	return 0;
}