#include<stdio.h>

void RemoveContinuousCharacter(char *p)
{
	int i,j=0,len;
	len=strlen(p);
	
	for(i=1;i<=len;i++)
	{
		while(p[i]==p[j]&& j>=0)
		{
			i++;
			j--;
		}
		p[++j]=p[i];
	}
	p[i]='\0';
	return;
}

int main()
{
	char a[]="abccbacbbca";
	
	RemoveContinuousCharacter(a);
	
	printf("\n\n %s \n\n",a);
	return 0;
}
