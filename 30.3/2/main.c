#include <unistd.h>

int main(void)
{
	char *const ps_argv[] = {"ps", "-o", "pid,ppid,pgrp,session,tpgid,comm", NULL};
	char *const ps_envp[] = {"PATH=/bin:/usr/bin", "TERM=console", NULL};
	execve("/bin/ps", ps_argv, ps_envp);

	return 0;
}
