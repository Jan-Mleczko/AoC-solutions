#include <stdio.h>
#include "..\aochelp.c"

#define COPIESFD 30

int main () {
	unsigned short int number;
	unsigned short int winning[20], *nextwinning, *wn;
	unsigned int mycopies, copies[COPIESFD], *cp, *ncp;
	unsigned int matching;
	unsigned long int cards;
	unsigned int i;
	char c;

	cards = 0;
	cp = copies + COPIESFD;
	while (--cp >= copies)
		*cp = 1;

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
	matching = 0;
actnumber:
	aocspaces ();
	number = aocscannum ();

	wn = winning;
	while (wn < nextwinning)
		if (number == *wn++) {
			++matching;
			break;
		}

	if (aocread () != '\n')
		goto actnumber;

	cards += mycopies = *copies;
	printf ("%u instances.\n", mycopies);

	ncp = cp = copies;
	i = 1;
	while (i < COPIESFD) {
		*cp = *++ncp;
		cp = ncp;
		++i;
		}
	*cp = 1;

	cp = copies;
	while (matching--)
		(*cp++) += mycopies;
	goto card;

done:
	printf ("Cards: %u.\n", cards);
	return 0;
	}

