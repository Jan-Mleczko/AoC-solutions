#include <stdio.h>
#include "..\aochelp.c"

char *strend (char *str) {
	while (*str)
		++str;
	return str;
	}

int peek (char *str) {
	int result;

	if (result = aocexpect (str))
		aoclaters (str + 1, strend (str));
	return result;
	}

int main () {
	unsigned int calib, sum;
	char c;
	char digit, fdig, ldig;
	char isfst;

	aocstd ();
	sum = 0;
line:
	isfst = 1;
pline:
	c = aocread ();
	if (aoceof)
		goto alldone;
	if (c == '\n')
		goto linedone;

	if (c >= '0' && c <= '9') {
		digit = c - '0';
		goto digit;
		}
	aoclater (c);

	if (peek ("one")) {
		digit = 1;
		goto digit;
		}
	if (peek ("two")) {
		digit = 2;
		goto digit;
		}
	if (peek ("three")) {
		digit = 3;
		goto digit;
		}
	if (peek ("four")) {
		digit = 4;
		goto digit;
		}
	if (peek ("five")) {
		digit = 5;
		goto digit;
		}
	if (peek ("six")) {
		digit = 6;
		goto digit;
		}
	if (peek ("seven")) {
		digit = 7;
		goto digit;
		}
	if (peek ("eight")) {
		digit = 8;
		goto digit;
		}
	if (peek ("nine")) {
		digit = 9;
		goto digit;
		}

	aocignore (1);
	goto pline;

digit:
	if (aocfirst (&isfst))
		fdig = digit;
	ldig = digit;
	goto pline;

linedone:
	sum += calib = fdig * 10 + ldig;
	/*printf ("Calibration val.: %u.\n", calib);*/
	if (!aoceof)
		goto line;
alldone:
	aocclose ();
	printf ("Sum of calibration values: %u.\n", sum);
	return 0;
	}
