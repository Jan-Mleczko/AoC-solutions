#include <stdio.h>
#include <stdlib.h>
int main ()
{ unsigned int elfcal = 0,
    topcal1 = 0, topcal2 = 0, topcal3 = 0, topsum;
  char line[20], *status = 1;
  while (status)
  { *line = 0;
    status = gets (line);
    if (*line)
      elfcal += atoi (line);
    else
    { if (elfcal > topcal3)
      { if (elfcal > topcal2)
        { topcal3 = topcal2;
          if (elfcal > topcal1)
          { topcal2 = topcal1;
            topcal1 = elfcal;
          }
          else
            topcal2 = elfcal;
        }
        else
          topcal3 = elfcal;
      }
      elfcal = 0;
    }
  }
  topsum = topcal1 + topcal2 + topcal3;
  printf ("Top three calorie sum: %u.\n", topsum);
  return 0;
}