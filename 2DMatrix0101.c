#include <stdio.h>
#define R 6
#define C 5
 
void spiralPrint(int m, int n, int a[R][C])
{
int i,j=1,r=0,c=0;
while(r<=m && c<=n)
{
for(i=c;i<=n;i++)
a[r][i]=j;
r++;

for(i=r;i<=m;i++)	
a[i][n]=j;
n--;

if(r<=m)
for(i=n;i>=c;i--)	
a[m][i]=j;
m--;

if(c<=n)
for(i=m;i>=r;i--)	
a[i][c]=j;
c++;

j=1-j;
}	
}
 
/* Driver program to test above functions */
int main()
{
   int a[R][C],i,j;
      spiralPrint(R-1, C-1, a);
   for(i=0;i<R;i++,printf("\n"))
   for(j=0;j<C;j++)
   printf(" %d",a[i][j]);
   
    return 0;
}
