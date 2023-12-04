#include <stdio.h>

int main ()
{
  FILE *infile;
  unsigned data[2048], tmp, nr, len = 0, ans = 0;
  unsigned oldsum, newsum;
  infile = fopen ("puzzles.in", "r");
  if (!infile)
    return 1;
  while (!feof (infile))
  {
    fscanf (infile, "%u", &tmp);
    data[len++] = tmp;
  }
  fclose (infile);
  for (nr = 0; nr < (len - 2); nr++)
  {
    oldsum = data[nr]   + data[nr+1] + data[nr+2];
    newsum = data[nr+1] + data[nr+2] + data[nr+3];
    printf ("!%u %u\n", oldsum, newsum);
    if (newsum > oldsum)
      ans++;
  }
  printf ("%u/%u\a\n", ans, len);
  return 0;
}