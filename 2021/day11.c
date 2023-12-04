#include <stdio.h>

#define PERIOD 100

char octopuses[10][10];

void init ()
{
  int row, col;
  for (row = 0; row < 10; row++)
  {
    for (col = 0; col < 10; col++)
      octopuses[row][col] = getchar () - '0';
    getchar ();
  }
}

unsigned step ()
{
  int row, col, action = 1;
  unsigned flashes = 0; char flashed[10][10];
  for (row = 0; row < 10; row++)
  for (col = 0; col < 10; col++)
  {
    octopuses[row][col]++;
    flashed[row][col] = 0;
  }
  while (action)
  {
    action = 0;
    for (row = 0; row < 10; row++)
    for (col = 0; col < 10; col++)
      if (octopuses[row][col] > 9 && !flashed[row][col])
      {
        flashed[row][col] = 1;
        action = 1; flashes++;
        if (row > 0) octopuses[row - 1][col]++;
        if (row < 9) octopuses[row + 1][col]++;
        if (col > 0) octopuses[row][col - 1]++;
        if (col < 9) octopuses[row][col + 1]++;
        if (row > 0 && col > 0) octopuses[row - 1][col - 1]++;
        if (row > 0 && col < 9) octopuses[row - 1][col + 1]++;
        if (row < 9 && col > 0) octopuses[row + 1][col - 1]++;
        if (row < 9 && col < 9) octopuses[row + 1][col + 1]++;
      }
  }
  printf ("!%u\n", flashes);
  if (flashes)
    for (row = 0; row < 9; row++)
    for (col = 0; col < 9; col++)
      if (flashed[row][col]) octopuses[row][col] = 0;
  return flashes;
}

int main ()
{
  unsigned i, flashes = 0;
  init ();
  for (i = 0; i < PERIOD; i++)
    flashes += step ();
  printf ("%u\n", flashes);
  return 0;
}