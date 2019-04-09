#include <stdio.h>

#define IN  1
#define OUT 0

int main(int argc, char const *argv[])
{
  int c, line_count, word_count, char_count, state;

  state = OUT;
  line_count = word_count = char_count = 0;

  while ((c = getchar()) != EOF) {
    char_count++;

    if (c == '\n') {
      line_count++;
      state = OUT;
    } else if (c == ' ' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      word_count++;
    }
  }

  printf("%d %d %d\n", line_count, word_count, char_count);

  return 0;
}
