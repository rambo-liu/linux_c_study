#include <unistd.h>
#include <stdlib.h>

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

	if (pid > 0)	/* parent */
		while (1) {
			write(fd[1], "parent to child\n", 16);
	
			sleep(1);

			if ((n = read(fd[0], line, MAXLINE)) > 0)
				write(STDOUT_FILENO, line, n);
		}
	else	/* child */
		while (1) {
			if ((n = read(fd[0], line, MAXLINE)) > 0)
				write(STDOUT_FILENO, line, n);
			
			sleep(1);

			write(fd[1], "child to parent\n", 16);
		}

	return 0;
}
