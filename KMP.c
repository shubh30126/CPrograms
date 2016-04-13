#include<stdio.h>
#include<string.h>

int F[7];
int occur[3];
int appear=0;


void PrefixTable(char p[],int m)
{
int i=1,j;
j=0;
F[0]=0;
while(i<m)
{
	if(p[i]==p[j])
	{
		F[i]=j+1;
		i++;
		j++;
	}
	else if(j>0)
	{
		j=F[j-1];
	}
	else
	{
		F[i]=0;
		i++;
	}	
}
}

void FindMatch(char t[],int m,char p[],int n)
{
	int i=0,j=0;
	
	PrefixTable(p,n);	
	
	while(i<m)
	{
		if(t[i]==p[j])
		{
		/*	if(j==n-1)
			return (i-j);
			else
			{
			i++;
			j++;
			}*/
			if(j==n-1)
			occur[appear++]=(i-j);
			i++;
			j++;
		}
		else if(j>0)
		j=F[j-1];
		else
		i++;
	}
}



int main(void)
{
char *P="Shubhans";
char *T="Hello Shubhanshu Here.. are you Shubhanshu !!!";
int i;

FindMatch(T,strlen(T),P,strlen(P));

for(i=0;i<appear;i++)
printf("Occurence at %d \n\n",occur[i]);


	
	return 0;
}
