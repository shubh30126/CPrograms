#include<stdio.h>
#include<malloc.h>

struct Queue
{
	int front,rear;
	int capacity;
	int *array;
};

typedef struct Queue Que;

void main()
{
int ch,data;	
Que *Q=createQueue(4); 	


while(1)
{
	printf("\nEnter the Choice :: 1.Enqueue 2. Dequeue ");
scanf("%d",&ch);

switch(ch)
{
case 1:
printf("\nEnter the value  ");
scanf("%d",&data);
Enqueue(Q,data);	
break;
case 2:
Dequeue(Q);
break;
default :
break;
}
display(Q);
printf("\nQSize=%d\n",QueueSize(Q));
}

}

Que * createQueue(int size)
{
	Que *Q=malloc(sizeof(Que));
	
	if(!Q)
	return NULL;
	Q->capacity=size;
	Q->front=Q->rear=-1;
	Q->array=malloc(Q->capacity*sizeof(int));
	if(!Q->array)
	return NULL;
	
return Q;
}

int IsEmptyQueue(Que *Q)
{
	return(Q->front==-1);
}

int IsFullQueue(Que *Q)
{
	return(Q->front==((Q->rear+1)%Q->capacity));
}

int QueueSize(Que *Q)
{
	return((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}

void Enqueue(Que *Q,int data)
{
	if(IsFullQueue(Q))
	printf("\nQueue is Full\n\n");
	else
	{
	Q->rear=(Q->rear+1)%Q->capacity;
	Q->array[Q->rear]=data;
	if(Q->front==-1)
	Q->front=Q->rear;
	}
}

void Dequeue(Que *Q)
{
	int data;
	if(IsEmptyQueue(Q))
	{
	printf("\nQueue is Empty\n\n");
	printf("\nValue cannot dequeued \n");
	return;
	}
	data=Q->array[Q->front];
	if(Q->front==Q->rear)
	Q->rear=Q->front=-1;
	else
	Q->front=(Q->front+1)%Q->capacity;
	printf("\nValue dequeued is %d\n",data);
		
}

void display(Que *Q)
{
	int i,j;
		printf("\nQueue is \n");
		 if(IsEmptyQueue(Q))
		printf("\tNULL\n");
		else
		{
		for(i=Q->front;i!=(Q->rear)%Q->capacity;i=(i+1)%Q->capacity)
		printf("\t%d ",Q->array[i]);
		printf("\t%d ",Q->array[i]);
		}
}
