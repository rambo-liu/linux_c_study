#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE	80

int main(void)
{
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];

	if (pipe(fd) < 0) {
		perror("pipe");
		exit(1);
	}
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}
	if (pid > 0) { /* parent */
		close(fd[0]);
		write(fd[1], "hello world\n", 12);
		wait(NULL);
	} else {	/* child */
		close(fd[1]);
		while (1)
			if ((n = read(fd[0], line, MAXLINE)) > 0)
				write(STDOUT_FILENO, line, n);
			 else {
				fprintf(stdout, "n: %d\n", n);
				wait(NULL);
			}
		
	}

	return 0;
}
