#include <stdio.h>

int main(int argc, char const *argv[])
{
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);

    if (c == ' ') {
      while ((c = getchar()) == ' ');
      putchar(c);
    }
  }

  return 0;
}
