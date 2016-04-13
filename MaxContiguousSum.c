#include<stdio.h>

int MaxContiguousSum(int A[],int n)
{
int M[n],max=0,i;
M[0]=0;
if(A[0]>0)
max=M[0]=A[0];

for(i=1;i<n;i++)
{
	if(M[i-1]+A[i]>0)
	M[i]=M[i-1]+A[i];
	else
	M[i]=0;	
	if(max<M[i])
	max=M[i];
}
return max;
}
int main()
{
	int A[]={-2,11,-4,13,-5,2};
	printf("%d",MaxContiguousSum(A,6));
	return 0;
}
