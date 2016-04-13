#include<stdio.h>

int main()
{
	char a[10];
	char stack[10];
	
	int top=-1,i;	
	
	scanf("%s",a);

	
	for(i=0;a[i]!='\0';i++)
	{
	if(a[i]=='(' || a[i]=='{' || a[i]=='[')	
		stack[++top]=a[i];
	else if(a[i]==')' || a[i]=='}' || a[i]==']')
	{
		if((a[i]==')' &&  stack[top]=='(') || (a[i]=='}' &&  stack[top]=='{') || (a[i]==']' &&  stack[top]=='['))
		top--;
		else
		{
		printf(" Not Satisfy ");
		return ;	
		}
		
	}	
	}
	
	if(top==-1 && i>0)
	printf(" Satisfy ");
	else
	printf(" Not Satisfy ");
	return 0;
}