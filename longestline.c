#include <stdio.h>

#define   LIMIT   1024

int get_line(char line[], int limit);
void copy(char from[], char to[]);

int main(int argc, char const *argv[])
{
  int longest = 0;
  int length;
  char line[LIMIT];
  char longest_line[LIMIT];

  while ((length = get_line(line, LIMIT)) > 0) {
    if (length > longest) {
      longest = length;
      copy(line, longest_line);
    }
  }

  if (longest > 0)
    printf("%s", longest_line);

  return 0;
}

int get_line(char line[], int limit) {
  int i, j, c;

  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < limit - 2)
      line[j++] = c;
  }

  if (c == '\n') {
    line[j] = c;
    i++;
    j++;
  }
  line[j] = '\0';

  return i;
}

void copy(char from[], char to[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    i++;
}
