#include <stdio.h>

int main(int argc, char const *argv[])
{
  int c;
  long count = 0;

  while ((c = getchar()) != EOF)
    if (c == '\n')
      count++;

  printf("%ld\n", count);

  return 0;
}
