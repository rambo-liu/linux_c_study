#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{	
	if (argv[1] != NULL) {
		printf("file name is %s\n", argv[1]);
	} else {
		printf("please give a file name\n");
		exit(1);
	}

	int fd;
	if ((fd = open(argv[1], O_RDWR | O_CREAT, 0664)) < 0) {
		perror("fail to create a new file");
		exit(1);
	} else
		printf("new file descriptor is %d\n", fd);

	return 0;
}
