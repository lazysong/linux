#include <stdio.h>
#include <string.h>

int main()
{
	/* valid how if works */
	int exp = 0;//exp = -1; exp = 1;
	if (exp)
		printf("exp = %d, means true\n", exp);
	else
		printf("exp = %d, means false\n", exp);

	/* valid how strlen() and sizeof() works */
	char s[] = "12345\n";
	//char s[] = "12345";
	printf("sizeof(%s) is %ld\n", s, sizeof(s));
	printf("strlen(%s) is %ld\n", s, strlen(s));
	return 0;
}
