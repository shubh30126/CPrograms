#include<stdio.h>
#include<math.h>

void reverse(char res[],int m)
{
	int start=0,end=m;	
	char c;
	while(start<end)
	{
	c=*(res+start);
	*(res+start)=*(res+end);
	*(res+end)=c;
	
	start++;
	end--;
	}
	
}

int IntToString(int a,char res[])
{
	int i=0;
	while(a!=0)
	{
	*(res+i)='0'+(a%10);
	a/=10;
	i++;
	}
	
	reverse(res,i-1);
	
	return i;
}

void FloatToString(float a,char res[],int Afterpoint)
{
int i;
i=IntToString((int)a,res);

if(Afterpoint!=0)
{
	res[i]='.';

a=fabs(a)-(int)a;
a=a*pow(10,Afterpoint);

i=i+IntToString((int)a,res+i+1)+1;
*(res+i)='\0';	
}
}


int main()
{
	float a=100.668123;
	char res[20];
	printf(" main %f ",a);

	FloatToString(a,res,4);
	printf("\n\n%s\n\n",res);
	return 0;
}
