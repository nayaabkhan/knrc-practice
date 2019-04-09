#include <stdio.h>

#define IN  1
#define OUT 0

int main(int argc, char const *argv[])
{
  int c, state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
      continue;
    } else if (state == OUT) {
      state = IN;
    }

    putchar(c);
  }

  return 0;
}
