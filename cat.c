/* implement of command 'cat' */
#include <stdio.h>

void filecopy(FILE * ifile, FILE * ofile);

int main(int argc, char * argv[])
{
	if (argc == 2)
	{
		/*  */
		char * filename = argv[1];
		FILE * surf = fopen(filename, "r");
		if (surf == NULL)
		{
			printf("file open failed!\n");
			return -1;
		}
		filecopy(surf, stdout);
		fclose(surf);
	}
	else
	{
		printf("usage: cat filename\n");
	}
	
	return 0;
}

 
void filecopy(FILE * surf, FILE * desf)
{
	char c;
	while ((c = getc(surf)) != EOF)
	{
		putc(c, desf);
	}
}
