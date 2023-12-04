#include <stdio.h>

char diagram[1024][1024];

void reset ()
{
  int x, y;
  for (x = 0; x < 1024; x++)
  for (y = 0; y < 1024; y++)
    diagram[x][y] = 0;
}

void plot (int x, int y)
{
  diagram[x][y]++;
}

void swap (int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void hline (int y, int x1, int x2)
{
  if (x1 > x2) swap (&x1, &x2);
  while (x1 <= x2)
    plot (x1++, y);
}

void vline (int x, int y1, int y2)
{
  if (y1 > y2) swap (&y1, &y2);
  while (y1 <= y2)
    plot (x, y1++);  
}

void dline (int x1, int y1, int x2, int y2)
{
  plot (x1, y1);
  while (x1 != x2 && y1 != y2)
  {
    if (x1 < x2) x1++;
            else x1--;
    if (y1 < y2) y1++;
            else y1--; 
    plot (x1, y1);
  }
}

void line (int x1, int y1, int x2, int y2)
{
  if (x1 == x2)
    vline (x1, y1, y2);
  else if (y1 == y2)
    hline (y1, x1, x2);
  else
    dline (x1, y1, x2, y2);
}

int check (int pt)
{
  int x, y, n = 0;
  for (x = 0; x < 1024; x++)
  for (y = 0; y < 1024; y++)
    if (diagram[x][y] >= pt) n++;
  return n;
}

int main ()
{
  int x1, y1, x2, y2;
  reset ();
  while (scanf ("%u,%u -> %u,%u", &x1, &y1, &x2, &y2) != EOF)
    line (x1, y1, x2, y2);
  printf ("%d\n", check (2));
  return 0;
}