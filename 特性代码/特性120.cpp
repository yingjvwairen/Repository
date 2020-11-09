#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  switch (n)
  {
  case 0:
    printf("it's 0\n");
    break;
  case 1:
    int i = 2;
    printf("it's 1, i = 2\n");
    break;
  }
  return 0;
}