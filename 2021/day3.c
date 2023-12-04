#include <stdio.h>

int main ()
{
  unsigned most[12], gamma = 0, epsilon = 0, i;
  unsigned zeroes[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  unsigned ones[12]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char line[16];
  while (gets (line))
    for (i = 0; i < 12; i++)
      if (line[i] == '1')
        ones[i]++;
      else if (line[1] == '0')
        zeroes[i]++;
  for (i = 0; i < 12; i++)
    if (ones[i] > zeroes[i])
      most[i] = 1;
    else
      most[i] = 0;
  for (i = 0; i < 12; i++)
  {
    gamma = (gamma << 1) | most[i];
    epsilon = (epsilon << 1) | !most[i];
  }
  printf ("%ux%u=%u\n", gamma, epsilon, gamma * epsilon);
  return 0;
}