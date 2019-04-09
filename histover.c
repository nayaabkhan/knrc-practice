#include <stdio.h>

#define   IN        1
#define   OUT       0
#define   MAX_WORD  10
#define   MAX_HIST  15

int main(int argc, char const *argv[])
{
  int c, i, j, state = OUT, word_count = 0;
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

  int max_value = 0;
  for (i = 1; i < MAX_WORD; i++)
    if (count_list[i] > max_value)
      max_value = count_list[i];

  for (i = MAX_HIST; i > 0; i--) {
    for (j = 1; j < MAX_WORD; j++) {
      if (count_list[j] * MAX_HIST / max_value >= i)
        printf(" * ");
      else
        printf("   ");
    }
    putchar('\n');
  }

  for (i = 1; i < MAX_WORD; i++)
    printf("%2d ", i);
  putchar('\n');

  for (i = 1; i < MAX_WORD; i++)
    printf("%2d ", count_list[i]);
  putchar('\n');

  return 0;
}
