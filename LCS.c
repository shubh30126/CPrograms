#include<stdio.h>
#include<string.h>

int count=0;
int len=0;
int m,n;

void LCS(char X[],int m,char Y[],int n,int C[][n+1],char D[][n])
{

	int i,j;

	for(i=0;i<=m;i++)
	C[i][0]=0;
	for(i=0;i<=n;i++)
	C[0][i]=0;

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i-1]==Y[j-1])
			{
			C[i][j]=C[i-1][j-1]+1;
				D[i-1][j-1]='S';
			}
			else
			{
			if(C[i][j-1]>C[i-1][j])
			{
				D[i-1][j-1]='L';
				C[i][j]=C[i][j-1];
			}
			else if(C[i][j-1]<C[i-1][j])
			{
				D[i-1][j-1]='U';
				C[i][j]=C[i-1][j];
			}
			else
			{
				D[i-1][j-1]='X';
				C[i][j]=C[i][j-1];
			}
			}


		}
	}


printf(" length %d \n",C[m][n]);

}

void Reverse(char s[],int l)
{
    int i=0;
    char temp;

    while(i<l)
    {
        temp=s[i];
        s[i]=s[l];
        s[l]=temp;

        i++;
        l--;
    }

}

void Print(char X[],char D[][n],int i,int j)
{
static char str[3];
static int len;
static check[6][3]={{0,},};


if(i<0 || j<0)
{
    if(count<len)
    {
    str[len]='\0';
    Reverse(str,len-1);
	printf("%s\n",str);
    Reverse(str,len-1);
	}
return;
}
if(D[i][j]=='S')
{
    int old=count;
    if(check[i][j])
    count++;
    check[i][j]=1;
    str[len++]=X[i];
    Print(X,D,i-1,j-1);
    len--;
    count=old;
}


if(D[i][j]=='L')
{
    Print(X,D,i,j-1);
}

if(D[i][j]=='U')
{
    Print(X,D,i-1,j);
}
if(D[i][j]=='X')
{
    Print(X,D,i,j-1);
	Print(X,D,i-1,j);
}


}



int main(void)
{

char X[]="AGCAT";
char Y[]="GAC";
m=strlen(X);
n=strlen(Y);
int C[m+1][n+1];
char D[m][n];
LCS(X,m,Y,n,C,D);

Print(X,D,m-1,n-1);

return 0;
}
