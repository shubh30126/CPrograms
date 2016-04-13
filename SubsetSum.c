#include <stdio.h>
 
int isSubsetSum(int set[], int n, int sum)
{
int i,j,M[n+1][sum+1];

for(i=0;i<=n;i++)
M[i][0]=1;

for(i=1;i<=sum;i++)
M[0][i]=0;

for(i=1;i<=n;i++)
for(j=1;j<=sum;j++)
{
if(j-set[i-1]>=0)
M[i][j]=(M[i-1][j]||M[i-1][j-set[i-1]]);
else
M[i][j]=M[i-1][j];
}
return M[n][sum];
}
 
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 13;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum)==1)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}