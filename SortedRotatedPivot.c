#include <stdio.h>

int search(int a[],int n)
{
	int mid,high=n-1,low=0;
	if(low==high)
		return low;	
		else if(low+1==high)
		return (a[low]>a[high])?high:low;
	
	if(a[low]<a[high])
	return low;
	
	while(low<high)
	{
		mid = (high+low)/2;
		if(a[mid]<a[mid-1] && a[mid]<a[mid+1])
		return mid;
		else if(a[mid]>a[low])
		low=mid;
		else if(a[mid]<a[low])
		high=mid;
		
	}
	return -1;
}
int main(void) {
	int a[12]={7,10,14,15,16,19,20,25,1,3,4,5};
	
	printf("Pivot is %d\n\n",search(a,12));
	
	return 0;
}
