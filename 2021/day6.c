#include <stdio.h>

unsigned long fish[9] = {0, 0, 0, 0, 0, 0, 0, 0};

void readfish ()
{
  char delim = ',';
  short timer;
  while (delim == ',')
  {
    scanf ("%d%c", &timer, &delim);
    fish[timer]++;
  }
}

unsigned long nfish ()
{
  unsigned long sum = 0; char i;
  for (i = 0; i < 9; i++)
    sum += fish[i];
  return sum;
}

void generate ()
{
  char i;
  unsigned long rise = fish[0];
  for (i = 0; i < 8; i++)
    fish[i] = fish[i + 1];
  fish[8] = rise; fish[6] += rise;
}

int main ()
{
  unsigned long i;
  readfish ();
  for (i = 0; i < 256; i++)
    generate ();
  /*printf ("%15u %15u %15u %15u\n%15u %15u %15u %15u\n\n", fish[0], fish[1], fish[2], fish[3], fish[4],
                                                          fish[5], fish[6], fish[7], fish[8]);*/
  printf ("SCREAM %lu\n", nfish ());
  return 0;
}