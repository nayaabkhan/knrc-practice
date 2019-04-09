#include <stdio.h>

int main(int argc, char const *argv[])
{
  int c;
  long count;

  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n')
      count++;

  printf("%ld\n", count);

  return 0;
}
