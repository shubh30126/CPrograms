#include <stdio.h>
#include <conio.h>


int cal(int a,char b, int c)
{
	switch(b)
	{
		case '+':
		return a+c;
		case '-':
		return a-c;
		case '*':
		return a*c;
		case '/':
		return a/c;
		default:
		printf(" -1  ");
		break;
	}
}


int main(void) {

char a[8]="2*3/3-4";

int i,op1=0,op2=0,oprflag=0,op2flag=0,op1flag=0;
char opr;

for(i=0;i<8;i++)
{
	if(oprflag==0 && op1flag==0 && a[i]>=48 && a[i]<=57)
	{
	op1=(op1*10)+(a[i]-48);
	op1flag=1;
	}
	else if(oprflag==0)
	{
		oprflag=1;
		opr=a[i];
	}
	else if (oprflag==1 && a[i]>=48 && a[i]<=57)
	{
		op2flag=1;
	op2=(op2*10)+(a[i]-48);
	}
	else if(op2flag==1)
	{
		op1=cal(op1,opr,op2);
		oprflag=0;
		op2flag=0;
		op2=0;
	i--;	
	}
	else 
	printf("%d ", -1);
	
	
//	printf("%d = %d %c %d \n",i,op1,opr,op2);
//	getch();
}
printf("Answer is %d ",op1);
	return 0;
}
