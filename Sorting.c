#include<stdio.h>


void main()
{
//	int a[6]={2,1,6,3,7,4};
	int a[6]={12,4,4,21,66,9};
		int i;
	
//	BubbleSort(a,6);
//	SelectionSort(a,6);
//	InsertionSort(a,6);		
//	ShellSort(a,6);

	CountingSort(a,6,67);
	for(i=0;i<6;i++)
	printf(" %d ",a[i]);	
}



BubbleSort(int a[],int n)
{
int temp,i,j;
for(i=n-1;i>0;i--)
for(j=0;j<i;j++)
if(a[j]>a[j+1])
{
	temp=a[j];
	a[j]=a[j+1];
	a[j+1]=temp;
}	
}

SelectionSort(int a[],int n)
{
int temp,i,j,min;
for(i=0;i<n-1;i++)
{
temp=a[i];
min=i;
for(j=i+1;j<n;j++)
if(temp>a[j])
{
temp=a[j];
min=j;
}
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}

InsertionSort(int a[],int n)
{
int i,j,temp;	
	
for(i=1;i<n;i++)
{
	j=i;
	temp=a[i];
while(temp<a[j-1] && j>=1)
{
a[j]=a[j-1];
j--;
}
a[j]=temp;
}	
}


void ShellSort (int a[], int n)
{
    int i, j, k, h, v;
    int cols[] = {1391376, 463792, 198768, 86961, 33936, 13776, 4592,
                    1968, 861, 336, 112, 48, 21, 7, 3, 1};
    for (k=0; k<16; k++)
    {
        h=cols[k];
        for (i=h; i<n; i++)
        {
            v=a[i];
            j=i;
            while (j>=h && a[j-h]>v)
            {
                a[j]=a[j-h];
                j=j-h;
            }
            a[j]=v;
        }
    }
}
 
 
 
void CountingSort(int a[],int n,int k)
{
	int c[k],b[n],i,j;
	
	for(i=0;i<k;i++)
	c[i]=0;
	
	for(j=0;j<n;j++)
	c[a[j]]=c[a[j]]+1;
	
	for(j=1;j<k;j++)
	c[j]=c[j]+c[j-1];
	
	for(j=n-1;j>=0;j--)
	{
		b[c[a[j]]-1]=a[j];
		c[a[j]]=c[a[j]]-1;
	}
	
	for(i=0;i<n;i++)
	a[i]=b[i];		
}
