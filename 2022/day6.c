#include <stdio.h>
#define distinct 14
int main ()
{ char signal[distinct] = {0, 0, 0, 0}, c;
  unsigned int i, j, count = 0;
  while ((c = getchar()) != EOF)
  { for (i = 0; i < (distinct - 1); ++i)
      signal[i] = signal[i + 1];
    signal[distinct - 1] = c;
    if (++count >= distinct)
    { for (i = 0; i < distinct; ++i)
      { for (j = 0; j < distinct; ++j)
        { if (i == j) continue;
          if (signal[i] == signal[j]) goto equal;
        }
      }
      printf ("Packet start: %u.\n", count);
      goto found; equal:;
    }
  }
  puts ("No packets found.");
  found: return 0;
}

    