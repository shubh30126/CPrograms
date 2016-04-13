#include<stdio.h>


print(int n)
{
	static char a[50];

if(n<1)
printf("%s\n",a);
else
{
a[n-1]='0';
print(n-1);	
a[n-1]='1';
print(n-1);	
}
}

void main()
{
	int n;
	scanf("%d",&n);
	print(n);
}
