#include<stdio.h>

int Cat[100];
int Catalan(int n)
{
int i;
if(n<1)
return 1;

Cat[1]=1;

if(Cat[n]!=0)
return Cat[n];

Cat[n]=0;
for(i=1;i<=n;i++)	
{
Cat[n]+=Catalan(i-1)*Catalan(n-i);	
}
return Cat[n];
}

int main()
{
	int n;
	
	printf("\nEnter the no. of Nodes ");
	scanf("%d",&n);
	
	printf("Total possible tree %d",Catalan(n));;
	return 0;
}
