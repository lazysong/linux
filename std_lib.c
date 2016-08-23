#include <stdio.h>

char *fgets(char *s, int n, FILE iop)
{
	register char c;
	register char *cs;
	
	cs = s;
	while (--n > 0 && (c = fget(iop)) != EOF)
	{
		if ((*cs++ = c) == '\n')
			break;
	}
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

char *getline(char *s, int n)
{
	if (fgets(s, n, stdin))
}
