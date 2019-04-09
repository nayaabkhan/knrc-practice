#include <stdio.h>

int main(int argc, char const *argv[])
{
  long count = 0;

  while (getchar() != EOF)
    count++;

  printf("%ld\n", count);

  return 0;
}
