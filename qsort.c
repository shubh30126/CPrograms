#include <stdio.h>
#include <stdlib.h>

char values[] ="2853746";

char cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

int main()
{
   printf("Before sorting the list is: \n");
    printf("%s ", values);
   
   qsort(values, 7, sizeof(char), cmpfunc);

   printf("\nAfter sorting the list is: \n");
      printf("%s ", values);
   
  return(0);
}