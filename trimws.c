#include <stdio.h>

#define   LIMIT   1024

int get_line(char line[], int limit);
int trim_line(char line[]);

int main(int argc, char const *argv[])
{
  char line[LIMIT];

  while (get_line(line, LIMIT) > 0)
    if (trim_line(line) > 0)
      printf("%s", line);

  return 0;
}

int trim_line(char line[])
{
  int i = 0;

  while (line[i] != '\n')
    i++;

  i--;

  while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
    i--;

  if (i >= 0) {
    line[++i] = '\n';
    line[++i] = '\0';
  }

  return i;
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
