#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxlvl 128
char *path[maxlvl], pathlvl = 0;
#define elsif else if
void cleanup ()
{ int i;
  for (i = 0; i < pathlvl; ++i)
    free (path[i]);
}
void exitc (int value)
{ cleanup ();
  exit (value);
}
void* alloc (unsigned int size)
{ void *location;
  if (location = malloc (size))
    return location;
  puts ("Memory allocation error.");
  exitc (1);
}
void navigate (char *dir)
{ if (*dir == '.')
  { if (pathlvl < 1)
    { puts ("Directory underflow.");
      exitc (1);
    }
    free (path[--pathlvl]);
  }
  elsif (*dir == '/')
    while (pathlvl > 0) navigate ("..");
  else
  { if (pathlvl >= maxlvl)
    { puts ("Directory overflow.");
      exitc (1);
    }
    path[pathlvl] = alloc (strlen (dir) + 1);
    strcpy (path[pathlvl++], dir);
  }
}