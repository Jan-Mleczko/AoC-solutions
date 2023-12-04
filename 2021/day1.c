#include <stdio.h>

int main ()
{
  FILE *infile; unsigned curr, prev = 0, ans = 0, nr = 0;
  infile = fopen ("puzzles.in", "r");
  if (!infile)
    return 1;
  while (!feof (infile))
  {
    fscanf (infile, "%u", &curr);
    if (curr > prev && nr)
      ans++;
    prev = curr;
    nr++;
  }
  fclose (infile);
  printf ("%u/%u\a\n", ans, nr);
  return 0;
}