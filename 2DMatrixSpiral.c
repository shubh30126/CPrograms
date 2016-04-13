#include <stdio.h>
#define R 5
#define C 5
 
void spiralPrint(char a[R][C])
{
int i,r=0,c=0,m=R-1,n=C-1;
while(r<=m && c<=n)
{
for(i=c;i<=n;i++)
printf(" %c",a[r][i]);
r++;

for(i=r;i<=m;i++)	
printf(" %c",a[i][n]);
n--;

if(r<=m)
for(i=n;i>=c;i--)	
printf(" %c",a[m][i]);
m--;

if(c<=n)
for(i=m;i>=r;i--)	
printf(" %c",a[i][c]);
c++;
}	
}
 
/* Driver program to test above functions */
int main()
{
   char a[R][C] = { 	{'i',	'l', 	'o', 	'v', 	'e' },
			{'d',	'i', 	'n', 	't', 	'e' },
			{'n', 	'e', 	'w', 	'e', 	'p' }, 
			{'a', 	'i', 	'v', 	'r', 	'i' }, 
			{'m',	'a', 	'x', 	'e', 	'c' } };
      spiralPrint(a);
    return 0;
}
