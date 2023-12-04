#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

void safeunget (char c) {
	if (c != EOF)
		ungetc (c, fp);
	}

unsigned int getvalue () {
	unsigned int val;
	char c;

	val = 0;
read:
	c = fgetc (fp);
	if (c < '0' || c > '9')
		goto endvalue;

	val = val * 10 + c - '0';
	goto read;

endvalue:
	safeunget (c);

	return val;
	}

void getword (char *dest) {
	char c;

read:
	c = fgetc (fp);
	if (c < 'a' || c > 'z')
		goto endword;

	*dest++ = c;
	goto read;

endword:
	safeunget (c);
	*dest = 0;
	}

#define COLRED 0
#define COLGREEN 1
#define COLBLUE 2

int getcolor () {
	char colorname[10];

	getword (colorname);
	if (!strcmp (colorname, "red"))
		return COLRED;
	else if (!strcmp (colorname, "green"))
		return COLGREEN;
	else if (!strcmp (colorname, "blue"))
		return COLBLUE;

	printf ("Unrecognized color \"%s\"\n", colorname);
	abort ();
	}

void ignore (unsigned int n) {
	while (n--)
		fgetc (fp);
	}

unsigned int gameid, cubes;
unsigned int power, totpower;
unsigned int colcount[3], reqcount[3];
int cubecolor;

void reqthis () {
	int i;

	i = 0;
	while (i < 3) {
		reqcount[i] = colcount[i];
		++i;
		}
	}

void updreq () {
	int i;
	unsigned int cn, rqcn;

	i = 0;
	while (i < 3) {
		cn = colcount[i];
		if (cn > reqcount[i])
			reqcount[i] = cn;
		++i;
		}
	}

/*void prcounts (int *a) {
	printf ("%u red, %u green, %u blue.\n",
		a[COLRED], a[COLGREEN], a[COLBLUE]);
	}*/

int main (int argc, char **argv) {
	char term;
	char firstset;

	if (argc > 1 && (fp = fopen (argv[1], "r"))) {
		totpower = 0;
	line:
		ignore (5);
		if (feof (fp))
			goto alldone;
		gameid = getvalue ();
		ignore (2);
		firstset = 1;
	cubeset:
		colcount[COLRED] = 0;
		colcount[COLGREEN] = 0;
		colcount[COLBLUE] = 0;
	cube:
		cubes = getvalue ();
		ignore (1);
		cubecolor = getcolor ();

		colcount[cubecolor] = cubes;

		term = fgetc (fp);
		ignore (1);

		if (term == ',')
			goto cube;

		if (firstset) {
			firstset = 0;
			reqthis ();
			}
		else
			updreq ();

		if (term == ';')
			goto cubeset;

		power = reqcount[COLRED]
                      * reqcount[COLGREEN]
		      * reqcount[COLBLUE];
		totpower += power;

		if (!feof (fp))
			goto line;

	alldone:
		fclose (fp);
		printf ("%u\n", totpower);
		}
	else
		puts ("File error!");

	return 0;
	}

