#include<stdio.h>
#include<stdlib.h>

typedef struct QNode
{
	unsigned pagenumber;
	struct QNode *next,*prev;
}QNode;

typedef struct Queue
{
	unsigned count;
	unsigned TotalFrames;
	QNode *front,*rear;
}Queue;

typedef struct Hash
{
	int capacity;
	QNode* *array;
}Hash;

QNode* newQNode(unsigned no)
{
QNode *q=(QNode*)malloc(sizeof(QNode));	
q->pagenumber=no;
q->prev=q->next=NULL;
return q;
}

Queue* createQueue(int frame)
{
	Queue* queue=(Queue*)malloc(sizeof(Queue));
	queue->front=queue->rear=NULL;
	queue->TotalFrames=frame;
	queue->count=0;
	return queue;
}

Hash* createHash(int capacity)
{
int i;
Hash *h=(Hash*)malloc(sizeof(Hash));
h->capacity=capacity;

h->array=(QNode**)malloc(capacity*sizeof(QNode*));
	
for(i=0;i<capacity;i++)
h->array[i]=NULL;

return h;	
}

int isEmptyQueue(Queue *q)
{
	return (q->rear==NULL);
}

int areAllFramesFull(Queue *q)
{
	return (q->count==q->TotalFrames);
}

void dequeue(Queue *q)
{
QNode* temp;
if(isEmptyQueue(q))
return;

if(q->front==q->rear)
q->front=NULL;

temp=q->rear;
q->rear=q->rear->prev;

if(q->rear)
q->rear->next=NULL;

free(temp);

q->count--;	
}

void enqueue(Queue *q,Hash *h,unsigned pageNumber)
{
QNode *temp;
if(areAllFramesFull(q))
{
	h->array[q->rear->pagenumber]=NULL;
	dequeue(q);
}

temp=newQNode(pageNumber);
temp->next=q->front;

if(isEmptyQueue(q))
q->front=q->rear=temp;
else
{
q->front->prev=temp;
q->front=temp;	
}

h->array[q->front->pagenumber]=q->front;

q->count++;	
}

void ReferencePage(Queue *q,Hash *h,unsigned pageNumber)
{
	QNode *qn=h->array[pageNumber];
	if(qn==NULL)
	{
		enqueue(q,h,pageNumber);
	}
	else if(qn!=q->front)
	{
	qn->prev->next=qn->next;
	if(qn->next)
	qn->next->prev=qn->prev;
	
	
	
	if(qn==q->rear)
	{
	q->rear=qn->prev;
	q->rear->next=NULL;
	}
		
	qn->next=q->front;
	qn->next->prev=qn;
	qn->prev=NULL;
	q->front=qn;	
	
	}
}


int main(void)
{
	
	Queue* q = createQueue( 4 );
 
     Hash* hash = createHash( 10 );
 
    ReferencePage( q, hash, 1);
    ReferencePage( q, hash, 2);
    ReferencePage( q, hash, 3);
    ReferencePage( q, hash, 1);
    ReferencePage( q, hash, 4);
    ReferencePage( q, hash, 5);

    printf ("%d ", q->front->pagenumber);
    printf ("%d ", q->front->next->pagenumber);
    printf ("%d ", q->front->next->next->pagenumber);
    printf ("%d ", q->front->next->next->next->pagenumber);
	return 0;
}
