#include<stdio.h>


void main()
{
//	int a[6]={2,1,6,3,7,4};
	int a[10]={1,1,3,3,2,2,4,4,4,4};
		int currcntr=1,maxcntr=1,maxcan,currcan,i;


currcan=maxcan=a[i];
	
for(i=1;i<10;i++)
{
	if(currcan==a[i])
		currcntr++;
	else
	{
		currcan=a[i];
		currcntr=1;
	}
	if(currcntr>maxcntr)
	{
		maxcntr=currcntr;
		maxcan=currcan;
	}
}

printf("\n\nWinner Is  %d with %d votes\n\n",maxcan,maxcntr);

}

