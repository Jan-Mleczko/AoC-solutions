#include <stdio.h>
char tform (char sgn)
{ if (sgn >= 'A' && sgn <= 'C')
    return sgn - 65;
  else
    return sgn - 89;
}
int main ()
{ unsigned int points = 0, gameval;
  char mysign, result, oppsign;
  while (scanf ("%c %c\n", &oppsign, &result) == 2)
  { oppsign = tform (oppsign);
    result = tform (result);
    mysign = oppsign + result;
    if (mysign > 2)
      mysign -= 3;
    if (mysign < 0)
      mysign += 3;
    gameval = 3 + result * 3;
    points += gameval + mysign + 1;
  }
  printf ("Total points: %u.\n", points);
  return 0;
}

    
