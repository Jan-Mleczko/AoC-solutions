#include <stdio.h>
#include <string.h>

struct pair
{
  char left;
  char right;
};

struct rule
{
  struct pair from;
  char to;
};

struct rule rules[1024];
unsigned nrules;
char polymer[1073741824] = {0};
char gen[1073741824] = {0};

void init ()
{
  nrules = 0;
  gets (polymer);
  getchar ();
  while (scanf ("%c%c -> %c\n", &rules[nrules].from.left,
         &rules[nrules].from.right, &rules[nrules].to) != EOF)
    nrules++;
}

void step ()
{
  unsigned i, j, len = 1; struct pair curr;
  for (i = 0; i < 1073741824; i++)
    gen[i] = 0;
  gen[0] = polymer[0];
  for (i = 0; i < strlen (polymer) - 1; i++)
  {
    curr.left = polymer[i];
    curr.right = polymer[i + 1];
    for (j = 0; j < nrules; j++)
      if (rules[j].from.left == curr.left && rules[j].from.right == curr.right)
      {
        gen[len++] = rules[j].to;
        break;
      }
    gen[len++] = curr.right;
  }
  strcpy (polymer, gen);
}

unsigned solve ()
{
  unsigned len = strlen (polymer);
  unsigned counts[25] = {0}, i;
  unsigned most = 0, least = 0;
  for (i = 0; i < len; i++)
    counts[polymer[i] - 'A']++;
  for (i = 0; i < 25; i++)
    if (counts[i])
    {
      if (!most || counts[i] > most)
        most = counts[i];
      else if (!least || counts[i] < least)
        least = counts[i];
    }
  return most - least;
}

main ()
{
  unsigned i;
  init ();
  puts (polymer);
  for (i = 0; i < 40; i++)
    step ();
  printf ("%u\n", solve ());
  return 0;
}