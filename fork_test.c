#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t pid;
	if ((pid = fork()) == -1)
		printf("error\n");
	else if (pid == 0){
		printf("child");
		//exit(0);
		return 0;
	}
	else {
		printf("father\n");
		printf("hello world");
		_exit(0);
	}
}
