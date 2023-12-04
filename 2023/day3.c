#include <stdio.h>

char engine[20000];
unsigned int engwidth, engheight;

void loadschematic () {
	char *engp;
	unsigned int linelength;
	char fstline;
	char c;

	engp = engine;
	linelength = 0;
	fstline = 1;
read:
	c = getchar ();
	if (c == EOF)
		goto endfile;

	*engp++ = c;
	++linelength;
	if (c == '\n') {
		if (fstline) {
			engwidth = linelength;
			fstline = 0;
			}
		}
	goto read;

endfile:
	engheight = (engp - engine) / engwidth;
	}

char *locate (unsigned int x, unsigned int y) {
	return engine + (y * engwidth + x);
	}

char symbolat (unsigned int x, unsigned int y) {
	char adjc;

	adjc = *(locate (x, y));
	return adjc != '.' && adjc != '\n'
	         && (adjc < '0' || adjc > '9');
	}

unsigned int analyse () {
	unsigned int partsum;
	unsigned int x, y;
	signed short int ox, oy;
	unsigned int ax, ay;
	unsigned int number;
	char *ep, ec;
	char isnumber, adjsymbol;

	partsum = 0;
	ep = engine;
	y = 0;

	while (y < engheight) {
		isnumber = 0;
		x = 0;
		while (x < engwidth) {
			ec = *ep;
			if (ec >= '0' && ec <= '9') {
				if (isnumber)
					number *= 10;
				else {
					isnumber = 1;
					number = 0;
					adjsymbol = 0;
					}
				number += ec - '0';

				oy = -1;
				while (oy <= +1) {
					ox = -1;
					while (ox <= +1) {
						if (ox || oy) {
						ax = x + ox;
						ay = y + oy;

						if (ax >= 0 && ay >= 0
						    && ax < engwidth
						    && ay < engheight
						    && symbolat (ax, ay))
							goto symfound;

						}
						++ox;
						}
					++oy;
					}
				goto nxfield;

			symfound:
				adjsymbol = 1;
				}
			else if (isnumber) {
				if (adjsymbol)
					partsum += number;
				isnumber = 0;
				}
		nxfield:
			++x;
			++ep;
			}

		++y;
		}

	return partsum;
	}

int main () {
	loadschematic ();
	printf ("Part number sum: %u.\n", analyse ());

	return 0;
	}

