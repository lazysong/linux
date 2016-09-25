#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 100

char * p;

void exe_cmd(char in_buf[], char * argv[])
{
	/* split in_buf into argv */
	int i = 0;
	for(p = in_buf; ; p++)
	{
		argv[i++] = p;
		while (*p != ' ' && *p != '\0')
			p++;
		if(*p == '\0')
			break;
		*p = '\0';
	}
	argv[i] = NULL;

	/* fork a process to execute the command */
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		execvp(argv[0], argv);
		printf("command %s is not found\n", argv[0]);
	}
	else if (pid > 0)
		wait(NULL);
	else
		printf("fork error\n");
}

int main()
{
	char in_buf[MAX_SIZE];
	char * argv[MAX_SIZE / 2 -1];
	int loop_count = 0;
	while (1)
	{
		printf("myshell:");
		gets(in_buf);
		loop_count++;
		exe_cmd(in_buf, argv);
	}
	return 0;
}
