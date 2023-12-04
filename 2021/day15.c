#include <stdio.h>

char map[128][128] = {0};
unsigned rows, cols;

void init ()
{
  char digit;
  rows = cols = 0;
  while ((digit = getchar ()) != EOF)
    if (digit == '\n')
      { cols = 0; rows++; }
    else if (digit >= '1' && digit <= '9')
      map[rows][cols++] = digit - '0';
}

main ()
{
  init ();
  printf ("rows=%u cols=%u\n", rows, cols);
}