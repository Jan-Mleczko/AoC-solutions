#include <stdio.h>

int bugscore (char bug)
{
  putchar (bug);
  switch (bug)
  {
    case ')': puts ("YAY"); return 1;
    case ']': puts ("YAY"); return 2;
    case '}': puts ("YAY"); return 3;
    case '>': puts ("YAY"); return 4;
    default:  return 0;
  }
}

int validate (char *line)
{
  char nest[256], chr;
  int depth = 0, score = 0;
  while (chr = *line++)
    if (chr == '(')
      nest[depth++] = ')';
    else if (chr == '[')
      nest[depth++] = ']';
    else if (chr == '{')
      nest[depth++] = '}';
    else if (chr == '<')
      nest[depth++] = '>';
    else if (depth && (chr == ')' || chr == ']' || chr == '}' || chr == '>'))
      if (chr != nest[--depth])
        return 0;
  if (!depth)
    return 0;
  while (--depth)
    score += bugscore (nest[depth]);
  return score;
}

int main ()
{
  char line[256];
  int scores[1024], count = 0, i;
  while (gets (line))
    scores[count++] = bugscore (validate (line));
  for (i = 0; i < count; i++)
    printf ("%d\n", scores[i]);
  return 0;
}