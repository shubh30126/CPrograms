#include<stdio.h>

void PrintAlternateString(char *s,char *p,char *Astr,int m,int n,int i)
{
static count=0;	
if(m==0 && n==0)
{
	printf("\n%d .  %s\n",++count,Astr);
	return;
}

if(m!=0)
{
Astr[i]=s[0];	
PrintAlternateString(s+1,p,Astr,m-1,n,i+1);
}
if(n!=0)
{
Astr[i]=p[0];	
PrintAlternateString(s,p+1,Astr,m,n-1,i+1);	
}	
}

int main()
{
	char *s="AB",*p="CD";
	char *Astr;
	int m,n;
	m=strlen(s);
	n=strlen(p);
	
	Astr=(char *)malloc((m+n+1)*sizeof(char));
	
	*(Astr+m+n)='\0';
	
	PrintAlternateString(s,p,Astr,m,n,0);
	
	return 0;
		
}
