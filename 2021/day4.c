#include <stdio.h>

struct board
{
  int numbers[5][5], last;
  char marked[5][5];
};

int seq[256]; unsigned seqlen;
struct board bs[4096]; unsigned bslen;

void call (struct board *board, int number)
{
  int row, col;
  board->last = number;
  for (row = 0; row < 5; row++)
  for (col = 0; col < 5; col++)
    if (board->numbers[row][col] == number)
      board->marked[row][col] = 1;
}

int score (struct board board)
{
  unsigned sum = 0;
  int row, col;
  for (row = 0; row < 5; row++)
  for (col = 0; col < 5; col++)
    if (! (board.marked[row][col]))
      sum += board.numbers[row][col];
  return sum * board.last;
}

int wins (struct board board)
{
  int row, col; char full;
  for (row = 0; row < 5; row++)
  {
    full = 1;
    for (col = 0; col < 5; col++)
      if (! (board.marked[row][col]))
        full = 0;
    if (full)
      return score (board);
  }
  for (col = 0; col < 5; col++)
  {
    full = 1;
    for (row = 0; row < 5; row++)
      if (! (board.marked[row][col]))
        full = 0;
    if (full)
      return score (board);
  }
  return 0;
}

void getseq ()
{
  char delim = ','; seqlen = 0;
  while (delim != '\n')
    scanf ("%d%c", &seq[seqlen++], &delim);
}

char getb (struct board *board)
{
  int row, col, num;
  board->last = 0;
  for (row = 0; row < 5; row++)
  for (col = 0; col < 5; col++)
  {
    if (scanf ("%d", &num) == EOF)
      return 0;
    board->numbers[row][col] = num;
    board->marked[row][col] = 0;
  }
  return 1;
}

void getbs ()
{
  bslen = 0;
  while (getb (&bs[bslen]) && bslen < 4096) bslen++;
}

int play ()
{
  unsigned i, j; int ans;
  for (i = 0; i < seqlen; i++)
    for (j = 0; j < bslen; j++)
    {
      call (&bs[j], seq[i]);
      if (ans = wins (bs[j]))
        return ans;
    }
  return play ();
}

int main ()
{
  unsigned i;
  getseq (); getbs ();
  printf ("%d\n", play ());
  return 0;
}