#include <stdio.h>
#include <string.h>

char *myfgets(char *s, int n, FILE *iop)
{
	register char c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
	{
		if ((*cs++ = c) == '\n')
			break;
	}
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

int mygetline(char *line, int max)
{
	if (myfgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}

int main()
{
	const int MAX = 20;
	char line[MAX];
	int n = mygetline(line, MAX);
	return 0;
}
