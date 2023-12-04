#include <stdio.h>
#include <string.h>

int main ()
{
  unsigned hr = 0, dep = 0, aim = 0;
  char cmd[16]; unsigned par;
  while (scanf ("%s %u", cmd, &par) != EOF)
  {
    if (!strcmp (cmd, "forward"))
    {
      hr += par;
      dep += aim * par;
    }
    else if (!strcmp (cmd, "down"))
      aim += par;
    else if (!strcmp (cmd, "up"))
      aim -= par;
  }
  printf ("%ux%u=%u\n", dep, hr, dep * hr);
  return 0;
}