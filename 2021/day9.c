#include <stdio.h>

char map[1024][1024];
unsigned width, height;

void readmap ()
{
  char temp; unsigned length;
  height = width = length = 0;
  while ( (temp = getchar ()) != EOF)
    if (temp == '\n')
    {
      if (!width || length < width)
        width = length;
      height++;
      length = 0;
    }
    else if (temp >= '0' && temp <= '9')
      map[height][length++] = temp - '0';
}

char look (unsigned row, unsigned column)
{
  if (row < 0 || row >= height || column < 0 || column >= width)
    return 9;
  else
    return map[row][column];
}

int islow (unsigned row, unsigned column)
{
  char point = look (row, column);
  return point < look (row - 1, column) && point < look (row + 1, column)
      && point < look (row, column - 1) && point < look (row, column + 1); 
}

unsigned risk ()
{
  unsigned row, column, risk = 0;
  for (row = 0; row < height; row++)
  for (column = 0; column < width; column++)
    if (islow (row, column)) risk += look (row, column) + 1;
  return risk;
}

main ()
{
  readmap ();
  printf ("%u/%ux%u\n", risk (), width, height);
}