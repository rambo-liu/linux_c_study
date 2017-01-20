#include <stdio.h>

int main(void)
{
	char name[100];
	sprintf(name, "%s/%s", "linux", "java");
	printf("name: %s\n", name);

	return 0;
}
