#include <stdio.h>

char reactor[101][101][101] = {0};

int range (int x, int y, int z)
{ return x >= -50 && y >= -50 && z >= -50
      && x <= 50 && y <= 50 && z <= 50;
}

int limit (int c)
{
  if (c < -50)
    return -51;
  else if (c > 50)
    return 51;
  else
    return c;
}

void rset (int x, int y, int z, int s)
{ if (range (x, y, z))
    reactor[x + 50][y + 50][z + 50] = s;
}

void rget (int x, int y, int z)
{ if (range (x, y, z))
    return reactor[x + 50][y + 50][z + 50];
  return 0;
}

void target (int x1, int y1, int z1, int x2, int y2, int z2, int s)
{ int x, y, z;
  x1 = limit (x1); y1 = limit (y1); z1 = limit (z1);
  x2 = limit (x2); y2 = limit (y2); z2 = limit (z2);
  for (x = x1; x <= x2; x++)
  for (y = y1; y <= y2; y++)
  for (z = z1; z <= z2; z++)
    rset (x, y, z, s);
}

unsigned stat ()
{
  int x, y, z; unsigned cubes = 0;
  for (x = -50; x <= 50; x++)
  for (y = -50; y <= 50; y++)
  for (z = -50; z <= 50; z++)
    if (rget (x, y, z)) cubes++;
  return cubes;
}

int main ()
{
  int x1, y1, z1, x2, y2, z2, s; char mode[4];
  while (scanf ("%3s x=%d..%d,y=%d..%d,z=%d..%d\n", mode, &x1, &x2, &y1, &y2, &z1, &z2) != EOF)
  { if (mode[1] == 'n') s = 1;
    else if (mode[1] == 'f') s = 0;
    target (x1, y1, z1, x2, y2, z2, s);
  }
  printf ("%u\n", stat ());
  return 0;
}