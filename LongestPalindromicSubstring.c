#include<stdio.h>

int LongestPalindromeSubstring(char str[],int n)
{
	int L[n][n];
	int i,j,k,max=0;
	for(i=0;i<n-1;i++)
	{
		L[i][i]=1;
		if(str[i]==str[i+1])
		{
			L[i][i+1]=1;
			max=2;
		}
		else
		L[i][i+1]=0;
	}
	for(k=3;k<=n;k++)
	for(i=0;i<n-k+1;i++)
	{
		j=i+k-1;
		if(str[i]==str[j] && L[i+1][j-1])
		{
			L[i][j]=1;
			max=k;
		}
		else
		L[i][j]=0;
	}
	return max;
}



int main(void)
{
	
	char str[]="forgeeksskeegfor";
	int strlen=(sizeof(str)/sizeof(str[0]));
	printf(" %d ",LongestPalindromeSubstring(str,strlen));
	
	return 0;
}
