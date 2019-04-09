#include <stdio.h>

#define   IN        1
#define   OUT       0
#define   MAX_WORD  20
#define   MAX_HIST  15

int main(int argc, char const *argv[])
{
  int c, i, state = OUT, word_count = 0;
  int count_list[MAX_WORD];
  int overflow = 0;

  for (i = 0; i < MAX_WORD; i++)
    count_list[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      state = OUT;

      if (word_count > 0) {
        if (word_count < MAX_WORD)
          count_list[word_count]++;
        else
          overflow++;
      }

        word_count = 0;
    } else if (state == OUT) {
      state = IN;
      word_count = 1;
    } else {
      word_count++;
    }
  }

  int bar_length, max_value = 0;
  for (i = 1; i < MAX_WORD; i++)
    if (count_list[i] > max_value)
      max_value = count_list[i];

  for (i = 1; i < MAX_WORD; i++) {
    printf("%5d - %5d : ", i, count_list[i]);

    if (count_list[i] > 0) {
      if ((bar_length = count_list[i] * MAX_HIST / max_value) <= 0)
        bar_length = 1;
    } else {
      bar_length = 0;
    }

    while (bar_length > 0) {
      putchar('*');
      bar_length--;
    }

    putchar('\n');
  }

  return 0;
}
