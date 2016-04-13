#include<stdio.h>

void ReversingString(char *a,int m,int n)
{
	char temp;
	for(;m<n;m++,n--)
	{
		temp=a[m];
		a[m]=a[n];
		a[n]=temp;		
	}
}

void ReverseWordsInSentence(char *a)
{
int start=0,end,i,j;
end=strlen(a)-1;

ReversingString(a,start,end);

for(j=start;j<=end;j++)
{
	i=j;
	if(a[j]!=' ')
	{
		while(j<=end && a[j]!=' ')
		j++;
		
		j--;
	}
	ReversingString(a,i,j);
}
}


int main()
{
	char str[]="This is Shubhanshu Dixit";
	
	ReverseWordsInSentence(str);
	
	printf("%s\n\n",str);	
	return 0;
}
