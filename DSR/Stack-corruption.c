#include <stdio.h>
#include <stdlib.h>

int fn()
{
  printf("fn\n");
  exit(1);
}

int main()
{
  char a;
  char *ptr = &a + 1;
  *(void**)(ptr+2*sizeof(void*)) = &fn;
  return 0;
}
