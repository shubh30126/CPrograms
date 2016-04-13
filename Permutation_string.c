#include<stdio.h>

void Permutation(int depth,char *permutation,int *used,char *original)
{
	int length,i;
	static total=1;
	length=strlen(original);
	
	if(depth==length)
	{
	permutation[length]='\0';	
	printf("\n %d %s",total++,permutation);
	}
	else
	for(i=0;i<length;i++)
	{
		if(!used[i])
		{
		used[i]=1;
		permutation[depth]=original[i];
		Permutation(depth+1,permutation,used,original);
		used[i]=0;
		}
	}
}


int main()
{
	char a[]="abc";
	char p[3];
	int used[]={0,0,0};
	Permutation(0,p,used,a);
	return 0;
}
