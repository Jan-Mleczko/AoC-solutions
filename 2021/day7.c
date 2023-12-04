#include <stdio.h>

int pos[1024];
unsigned crabs;

void readcrabs ()
{
  char delim = ',';
  crabs = 0;
  while (delim == ',')
    scanf ("%d%c", &pos[crabs++], &delim);
}

int maxpos ()
{
  int result = pos[0], i;
  for (i = 1; i < crabs; i++)
    if (pos[i] > result) result = pos[i];
  return result;
}

int minpos ()
{
  int result = pos[0], i;
  for (i = 1; i < crabs; i++)
    if (pos[i] < result) result = pos[i];
  return result;
}

int abs (int a)
{
  if (a < 0)
    return 0 - a;
  else
    return a;
}

int bestpos ()
{
  int search, bound, result = -1, fuel, consum, i;
  search = minpos (); bound = maxpos ();
  while (search <= bound)
  {
    fuel = 0;
    for (i = 0; i < crabs; i++)
      fuel += abs (search - pos[i]);
    if (fuel < consum || result == -1)
    {
      consum = fuel;
      result = search;
    }
    search++;
  }
  return consum;
}

int main ()
{
  readcrabs ();
  printf ("%d\n", bestpos ());
  return 0;
}