#include <stdio.h>
#include <string.h>
int main ()
{ char gp1[128], gp2[128], gp3[128], c, *pos;
  unsigned int sum = 0;
  while ((gets (gp1) && gets (gp2)) && gets (gp3))
  { for (pos = gp1; c = *pos; ++pos)
      if (strchr (gp2, c) && strchr (gp3, c)) break;
    sum += (c < 'a') ? (c - 38) : (c - 96);
  }
  printf ("Badge item priority sum: %u.\n", sum);
  return 0;
}
