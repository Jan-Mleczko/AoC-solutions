FILE *aocfile;
char aoceof;

char *aocqueue, aocqustart[100];

char aocerror;

void aocinit () {
	aocqueue = aocqustart;
	aoceof = 0;
	}

void aocopen (char *fname) {
	aocerror = ((aocfile = fopen (fname, "r")) == NULL);
	aocinit ();
	}

void aocstd () {
	aocfile = stdin;
	aocinit ();
	}

void aocclose () {
	if (aocfile != stdin)
		fclose (aocfile);
	}

char aocread () {
	char c;

	aocerror = 0;

	if (aocqueue > aocqustart)
		return *--aocqueue;

	if (aoceof) {
		aocerror = 1;
		return;
		}

	c = fgetc (aocfile);

	if (c == EOF)
		aoceof = 1;

	return c;
	}

void aoclater (char c) {
	*aocqueue++ = c;
	}

void aoclaters (char *start, char *stop) {
	while (stop > start)
		aoclater (*--stop);
	}

unsigned int aocscannum () {
	unsigned int val;
	char c;

	val = 0;
	aocerror = 1;
readnum:
	c = aocread ();
	if (aoceof)
		goto numberend;
	if (c < '0' || c > '9')
		goto numberterm;

	aocerror = 0;
	val = val * 10 + c - '0';
	goto readnum;

numberterm:
	aoclater (c);
numberend:
	return val;
	}

void aocscanword (char *dest) {
	char c;

	aocerror = 1;
readword:
	c = aocread ();
	if (aoceof)
		goto wordend;
	if (c < 'a' || c > 'z')
		goto wordterm;

	aocerror = 0;
	*dest++ = c;
	goto readword;

wordterm:
	aoclater (c);
wordend:
	*dest = 0;
	}

void aocignore (unsigned int n) {
	while (n--)
		aocread ();
	}

void aocignoreto (char term) {
	char c;

	do
		c = aocread ();
		while (!aoceof && c != term);
	}

void aocspaces () {
	char c;

read:
	c = aocread ();
	if (aoceof)
		return;
	if (c != ' ')
		goto nonspace;
	goto read;

nonspace:
	aoclater (c);
	}

int aocexpect (char *str) {
	char *s, sc, ac;

	s = str;
	while (sc = *s) {
		ac = aocread ();
		if (aoceof)
			goto ended;
		if (ac != sc)
			goto nope;
		++s;
		}
	return 1;

nope:
	aoclater (ac);
ended:
	aoclaters (str, s);
	return 0;
	}

int aocfirst (char *flag) {
	if (*flag) {
		*flag = 0;
		return 1;
		}
	return 0;
	}

void aocmaximize (unsigned int *currmax, unsigned int elem) {
	if (elem > *currmax)
		*currmax = elem;
	}

void aocminimize (unsigned int *currmin, unsigned int elem) {
	if (elem < *currmin)
		*currmin = elem;
	}

