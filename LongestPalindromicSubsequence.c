#include<stdio.h>

int LongestPalindromeSubsequence(char str[],int n)
{
	int L[n][n];
	int i,j,k,max=0;
	for(i=0;i<n;i++)
		L[i][i]=1;
	
	for(k=2;k<=n;k++)
	for(i=0;i<=n-k+1;i++)
	{
		j=i+k-1;
		if(str[i]==str[j] && k==2)
		L[i][j]=2;
		else if(str[i]==str[j])
			L[i][j]=2+L[i+1][j-1];
		else
		L[i][j]=L[i+1][j]>L[i][j-1]?L[i+1][j]:L[i][j-1];
	}
	return L[0][n-1];
}



int main(void)
{
	
	char str[]="GEEKS FOR GEEKS";
	int strlen=(sizeof(str)/sizeof(str[0]));
	printf(" %d ",LongestPalindromeSubsequence(str,strlen));
	
	return 0;
}
