#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) 
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array)
        return NULL;
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char top(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}
 
 
// A utility function to check if the given character is operand
int isOperand(char ch)
{
	return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}
 
// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		return 1;
		case '*':
		case '/':
		return 2;
		case '^':
		return 3;
		break;
	}
	return -1;
}
 
 
int infixToPostfix(char* exp)
{
	int i,k=-1;
	
	struct Stack *s=createStack(strlen(exp));
	
	for(i=0;i<strlen(exp);i++)
	{
		if(isOperand(exp[i]))
		{
			exp[++k]=exp[i];
		}
		else if(exp[i]=='(')
		{
		push(s,'(');
		}
		else if(exp[i]==')')
		{
			while(top(s)!='(')
			exp[++k]=pop(s);
			if(!isEmpty(s) && top(s)!='(')
			return -1;
			else			
			pop(s);
		}
		else
		{
			while(!isEmpty(s) && (Prec(exp[i])<=Prec(top(s))))
			exp[++k]=pop(s);
			push(s,exp[i]);
		}		
	}
	while(!isEmpty(s))
	exp[++k]=pop(s);
	
	exp[++k]='\0';
	
	printf(" PostFix == %s",exp);
}
 
// Driver program to test above functions
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
