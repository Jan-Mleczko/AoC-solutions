#include <stdio.h>
#define maxheight 128
#define maxcount 64
struct stack { char crates[maxheight]; short int height; };
void move (struct stack *src, struct stack *dest, int n)
  {
    int i = 0;
    if (dest->height > maxheight - n)
      {
        puts ("Warning: stack overflow, move ignored.");
        return;
      }
    if (src->height < n)
      {
        puts ("Warning: stack underflow, move ignored.");
        return;
      }
    while (i++ < n)
      dest->crates[dest->height++] = src->crates[--dest->height];
  }
char top (struct stack src)
{ if (src.height < 1) return '?';
  else return src.crates[src.height - 1];
}
int main ()
{ struct stack stacks[maxcount]; int nstacks = 0;
  