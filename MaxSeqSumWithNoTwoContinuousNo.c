#include<stdio.h>

int MaxContiguousSum(int A[],int n)
{
int M[n],max=0,i;
M[0]=0;
M[0]=A[0];

M[1]=A[0]>A[1] ? A[0]:A[1];

max=M[1];
for(i=2;i<n;i++)
{
	M[i]=(M[i-2]+A[i]>M[i-1])?(M[i-2]+A[i]):M[i-1];
	if(max<M[i])
	max=M[i];
}
return max;
}
int main()
{
	int A[]={1,2,3,-4,5,6};
	printf("%d",MaxContiguousSum(A,6));
	return 0;
}
