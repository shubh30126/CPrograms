#include<stdio.h>
int main()
{
	char a[50];
	char b[50],c[10];
	int i,j,k=0;
	
	FILE *ptr_file;
	ptr_file =fopen("abc.txt", "r");
	if (!ptr_file)
			return 1;


fgets(a,50,ptr_file);
			printf("%s",a);
   
fclose(ptr_file);

return 0;
}
