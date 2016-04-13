#include<stdio.h>
#include<limits.h>

struct Stack
{
	int top;
	int capacity;
	int *Array;
};

struct Stack* createStack(int cap)
{
	struct Stack *s=malloc(sizeof(struct Stack));
	s->capacity=cap;
	s->top=-1;
	s->Array=malloc(sizeof(s->capacity*sizeof(int)));
}

int isStackFull(struct Stack *s)
{
	return (s->capacity==s->top+1);
}

int isStackEmpty(struct Stack *s)
{
	return (s->top==-1);
}

void push(struct Stack *s,int data)
{
	if(isStackFull(s))
	return;
	
	s->Array[++(s->top)]=data;
}

int pop(struct Stack *s)
{
	if(isStackEmpty(s))
	return INT_MIN;
	
	return s->Array[(s->top)--];
}

void reverse(struct Stack *s)
{
int data;
if(isStackEmpty(s))
return;

data=pop(s);
reverse(s);
insertAtBottom(s,data);
	
}

void insertAtBottom(struct Stack *s,int data)
{
int temp;
if(isStackEmpty(s))
{
	push(s,data);
	return;
}
temp=pop(s);
insertAtBottom(s,data);
push(s,temp);

}


int main()
{

	struct Stack *s=createStack(5);
	int i=1;
	
	while(isStackFull(s)!=1)	
		push(s,i++);
	
	
	reverse(s);
	
	while(isStackEmpty(s)!=1)	
		printf(" %d ",pop(s));
	
	
	return 0;
}
