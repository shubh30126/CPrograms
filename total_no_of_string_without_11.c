#include<stdio.h>

int No=0;

print(int n)
{
static char a[50];

if(n<1)
No++;
else
{
	if(a[n]=='1')
	{
	a[n-1]='0';
	print(n-1);	
	}
	else
	{
	a[n-1]='0';
	print(n-1);	
	a[n-1]='1';
	print(n-1);	
	}
}
}

void main()
{
	int n;
	scanf("%d",&n);
	print(n);
	printf("Total Strings = %d ",No);
}
