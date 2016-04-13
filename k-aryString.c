#include<stdio.h>

char a[50];
int No=0;

print(int n,int k)
{

	int i;
if(n<1)
printf("%s\n",a,No++);
else
{
	for(i=0;i<k;i++)
	{
		a[n-1]=(char)(i+(int)'0');
		print(n-1,k);	
	}
}

}

void main()
{
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	print(n,k);
	printf("Total =%d",No);
}
