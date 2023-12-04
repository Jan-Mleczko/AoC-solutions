#include <stdio.h>

char sheet[2048][2048] = {0};
unsigned ysize, xsize;

void plot ()
{
  unsigned ypos, xpos;
  ysize = xsize = 0;
  while (scanf ("%u,%u\n", &xpos, &ypos))
  {
    if (ypos > ysize) ysize = ypos + 1;
    if (xpos > xsize) xsize = xpos + 1;
    sheet[ypos][xpos] = 1;
  }
}

void xfold (unsigned line)
{
  unsigned x, y;
  if (line < xsize / 2)
    { puts ("Unimplemented!"); return; }
  for (x = line; x < xsize; x++)
  {
    for (y = 0; y < ysize; y++)
      sheet[y][x - (xsize - x)] |= sheet[y][x];
  }
  xsize = line;
}

void yfold (unsigned line)
{
  unsigned x, y;
  if (line < ysize / 2)
    { puts ("Unimplemented!"); return; }
  for (y = line; y < ysize; y++)
  {
    for (x = 0; x < xsize; x++)
      sheet[y - (ysize - y)][x] |= sheet[y][x];
  }
  ysize = line;
}

void fold ()
{
  char axis; unsigned line;
  scanf ("fold along %c=%u\n", &axis, &line);
  if (axis == 'x')
    xfold (line);
  else if (axis == 'y')
    yfold (line);
}

unsigned inspect ()
{
  unsigned dots = 0, y, x;
  for (y = 0; y < ysize; y++)
  for (x = 0; x < xsize; x++)
    if (sheet[y][x]) dots++;
  return dots;
}

main ()
{
  plot ();
  printf ("%ux%u %u\n", ysize, xsize, inspect ());
  fold ();
  printf ("%ux%u %u\n", ysize, xsize, inspect ());
}