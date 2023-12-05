#include <stdio.h>
#include "..\aochelp.c"

int main () {
	unsigned int points, cardpoints;
	unsigned short int number;
	unsigned short int winning[20], *nextwinning, *wn;
	char c;

	points = 0;
	aocstd ();
card:
	aocignore (5);
	if (aoceof)
		goto done;
	aocignoreto (':');

	nextwinning = winning;
wnumber:
	aocspaces ();
	if ((c = aocread ()) == '|')
		goto wlistend;
	else
		aoclater (c);
	*nextwinning++ = aocscannum ();
	goto wnumber;

wlistend:
	cardpoints = 1;
actnumber:
	aocspaces ();
	number = aocscannum ();

	wn = winning;
	while (wn < nextwinning)
		if (number == *wn++) {
			cardpoints <<= 1;
			break;
		}

	if (aocread () != '\n')
		goto actnumber;

	points += cardpoints >> 1;
	goto card;

done:
	printf ("Points: %u.\n", points);
	return 0;
	}

