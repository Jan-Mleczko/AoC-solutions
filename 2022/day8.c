#include <stdio.h>
char heights[9801];
#define validpos(x) ((x)>=0&&(x)<99)
char* treeloc (int x, int y)
{ return
    heights + (y * 99 + x);
}
int visible (int x, int y)
{ char heightval;
  heightval = *(treeloc (x, y));
  int xpos, ypos;
  puts ("Called visible()");
  if (x == 0 || x == 99 || y == 0 || y == 99)
    return 1;
  for (xpos = x, ypos = y; validpos (xpos); ++xpos)
  { if (*(treeloc (xpos, ypos)) >= heightval)
      return 0;
  }
  for (xpos = x, ypos = y; validpos (xpos); --xpos)
  { if (*(treeloc (xpos, ypos)) >= heightval)
      return 0;
  }
  for (xpos = x, ypos = y; validpos (ypos); ++ypos)
  { if (*(treeloc (xpos, ypos)) >= heightval)
      return 0;
  }
  for (xpos = x, ypos = y; validpos (ypos); ++ypos)
  { if (*(treeloc (xpos, ypos)) >= heightval)
      return 0;
  }
  return 1;
}
int main ()
{ char c; unsigned int i, j, count;
  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9')
      { *(treeloc (i, j)) = c - 48;
        ++i;
      }
    else ++j;
  count = 0;
  for (i = 0; i < 99; ++i)
  { for (j = 0; j < 99; ++j)
      count += visible (i, j);
  }
  printf ("\nVisible trees: %u.\n", count);
  return 0;
}
