#include <stdio.h>
int main ()
{ unsigned int min1, max1, min2, max2, count = 0;
  while (scanf ("%u-%u,%u-%u\n", &min1,&max1,&min2,&max2) == 4)
    count += (min1 <= max2 && max1 >= min2);
  printf ("Overlap count: %u.\n", count);
  return 0;
}
