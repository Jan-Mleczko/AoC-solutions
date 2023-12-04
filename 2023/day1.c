#include <stdio.h>

#define YES	1
#define NO	0

#define LNSIZE 50

unsigned int phlen;

char infront (char *str, char *phrase) {
	char c;

	phlen = 0;
	while (c = *phrase++) {
		if (*str++ != c)
			return NO;

		++phlen;
		}

	return YES;
	}

int main () {
	unsigned int calibsum;
	char ch;
	char linebuf[LNSIZE], *linepos, *scanpos;
	char fdig, ldig;
	char nodig, eof;
	char dig;

	calibsum = 0;

line:
	linepos = linebuf;

read:
	ch = getchar ();
	if ((eof = (ch == EOF)) || ch == '\n');
		goto endline;

	*linepos = ch;
	++linepos;
	printf ("%p\n", linepos);

	goto read;

endline:
	*linepos = 0;
	scanpos = linebuf;
	nodig = YES;
	printf ("%d\n", ch);
	printf ("%p %p\n", scanpos, linepos);

	while (scanpos < linepos) {
		puts ("SCANNING LINE");
		ch = *scanpos;
		if (ch >= '0' && ch <= '9') {
			dig = ch - '0';
			++scanpos;
			goto founddig;
			}
		
		if (infront (scanpos, "one")) {
			dig = 1;
			goto spelldig;
			}
		if (infront (scanpos, "two")) {
			dig = 2;
			goto spelldig;
			}
		if (infront (scanpos, "three")) {
			dig = 3;
			goto spelldig;
			}
		if (infront (scanpos, "four")) {
			dig = 4;
			goto spelldig;
			}
		if (infront (scanpos, "five")) {
			dig = 5;
			goto spelldig;
			}
		if (infront (scanpos, "six")) {
			dig = 6;
			goto spelldig;
			}
		if (infront (scanpos, "seven")) {
			dig = 7;
			goto spelldig;
			}
		if (infront (scanpos, "eight")) {
			dig = 8;
			goto spelldig;
			}
		if (infront (scanpos, "nine")) {
			dig = 9;
			goto spelldig;
			}

		continue;

	spelldig:
		scanpos += phlen;

	founddig:
		printf ("Found digit %d.\n", dig);

		if (nodig) {
			fdig = dig;
			nodig = NO;
			}
		ldig = dig;

		}

	calibsum += fdig * 10 + ldig;

	if (!eof)
		goto line;

end:
	printf ("Sum of calibration values: %u.\n", calibsum);
	return 0;
	}

