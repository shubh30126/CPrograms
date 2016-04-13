#include<stdio.h>

int min(int a,int b,int c)
{
	return (a>b?(b>c?c:b):(a>c?c:a));
}

void MaxSizeSubSquareMatrixAll_1(int b[][5],int m,int n)
{
int l[m][n],i,j,max_i,max_j,max_s;

for(i=0;i<m;i++)
l[i][0]=b[i][0];
	
for(i=0;i<n;i++)
l[0][i]=b[0][i];	

max_s=l[0][0];
for(i=1;i<m;i++)
	for(j=1;j<n;j++)
	{
		if(b[i][j])
		l[i][j]=min(l[i-1][j],l[i][j-1],l[i-1][j-1])+1;
		else
		l[i][j]=0;
		
		if(max_s<l[i][j])
		{
			max_s=l[i][j];
			max_i=i;
			max_j=j;
		}
	}

for(i=0;i<m;i++,printf("\n"))
	for(j=0;j<n;j++)
	printf(" %d",b[i][j]);

printf("\n\n");

for(i=0;i<m;i++,printf("\n"))
	for(j=0;j<n;j++)
	printf(" %d",l[i][j]);

printf("\n\nMax Size is %d\n\n",max_s);

}

int main()
{
	int b[6][5]={{0,1,1,0,1},{1,1,0,1,0},{0,1,1,1,0},{1,1,1,1,0},{1,1,1,1,1},{0,0,0,0,0}};
	MaxSizeSubSquareMatrixAll_1(b,6,5);
	return 0;
}
