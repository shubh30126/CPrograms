#include<stdio.h>

#define m 4
#define n 4

int MaxAppleSum(int a[m][n])
{
int i,j,min,S[m][n],max;
S[0][0]=a[0][0];

for(i=1;i<m;i++)
S[i][0]=S[i-1][0]+a[i][0];

for(i=1;i<n;i++)
S[0][i]=S[0][i-1]+a[0][i];

for(i=1;i<m;i++)
for(j=1;j<n;j++)
{
max=S[i-1][j]>S[i][j-1]?S[i-1][j]:S[i][j-1];
S[i][j]=a[i][j]+max;
}

for(i=0;i<m;i++,printf("\n"))
for(j=0;j<n;j++)
printf(" %2d ",a[i][j]);

printf("------------------------------------------------\n\nSumMatrix\n\n");

for(i=0;i<m;i++,printf("\n"))
for(j=0;j<n;j++)
printf(" %2d ",S[i][j]);


return S[m-1][n-1];	
}

int main()
{
	int a[m][n]={{1,2,3,4},{5,3,2,1},{6,6,7,8},{7,7,6,5}};
	printf("Max Apple Collected %d\n\n",MaxAppleSum(a));
	return 0;
}
