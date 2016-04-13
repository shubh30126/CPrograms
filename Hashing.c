#include<stdio.h>

#define LOADFACTOR 20

int Hash(int data,int tsize)
{
return (data%tsize);
}

struct ListNode
{
int key;
int data;
struct ListNode *next;
};

struct HashNode
{
int bcount;
struct ListNode	*next;
};

struct HashTable
{
int tsize;
int count;
struct HashNode **Table;
};

struct HashTable* createHashTable(int size)
{
	int i;
	struct HashTable *h=(struct HashTable*)malloc(sizeof(struct HashTable));

	if(!h)
	return NULL;

	h->tsize=(size/LOADFACTOR);
	h->count=0;

	h->Table=(struct HashNode **)malloc(h->tsize*sizeof(struct HashNode *));
	
	for(i=0;i<(h->tsize);i++)
	{

//		printf("i= %d\n",i);

/* abe yeh jo upar printf hai uska comment hata ke run kro to niche wala h->tsize ki value print ho rhi... 
		par agar printf ko comment kr do to saala ... upar hi chudaye le rha kahi... waha tak bhi nhi aa rha.... 
		
		Kya mara rha hai be yeh..... easy sa to hai.... phir bhi.... :( */

	h->Table[i]->bcount=0;
	h->Table[i]->next=NULL;

	}

	printf("tsize %d",h->tsize);
	getch();


return h;
}

int HashSearch(struct HashTable* h,int data)
{
	int index;
	struct ListNode *temp;

	index=Hash(data,h->tsize);

	for(temp=h->Table[index]->next;temp;temp=temp->next)
	if(temp->data==data)
	return 1;

return 0;

}

int HashInsert(struct HashTable *h,int data)
{
	int index;
	struct ListNode *temp,*NewNode;

	if(HashSearch(h,data))
	return 0;

	index=Hash(data,h->tsize);

	NewNode=(struct ListNode *)malloc(sizeof(struct ListNode));
	if(!NewNode)
	{
		printf("Memory Full");
		return 0;
	}

	NewNode->data=data;
	NewNode->next=h->Table[index]->next;
	NewNode->key=index;
	h->Table[index]->next=NewNode;
	h->count++;
	h->Table[index]->bcount++;

	if((h->count/h->tsize)>LOADFACTOR)
	Rehash(h);

	return 1;
}

int HashDelete(struct HashTable *h,int data)
{
	int index;
	struct ListNode *temp,*prev;
	index=Hash(data,h->tsize);

	for(temp=h->Table[index]->next,prev=NULL;temp;prev=temp,temp=temp->next)
	if(temp->data==data)
	{
		if(prev!=NULL)
		prev->next=temp->next;
		else
		h->Table[index]->next=temp->next;
	free(temp);
	h->count--;
	h->Table[index]->bcount--;
	return 1;
	}

return 0;
}


void Rehash(struct HashTable *h)
{
int index,i,oldsize;
struct HashNode **oldTable;
struct ListNode *temp,*temp2;

oldsize=h->tsize;
h->tsize=h->tsize*2;

oldTable=h->Table;

h->Table=(struct HashNode **)malloc(sizeof(struct HashNode)*h->tsize);

for(i=0;i<oldsize;i++)
{
	for(temp=oldTable[i]->next;temp;temp=temp2)
	{
		index=Hash(temp->data,h->tsize);
		temp2=temp->next;
		temp->next=h->Table[index]->next;
		h->Table[index]->next=temp;
	}
}

}


void main()
{
struct HashTable *h=createHashTable(40);



}

