#include "apue.h"

#define BSZ 48

int main(void) {
	FILE * fp;
	char buff[BSZ];
	memset(buff, 'a', BSZ-2);
	buff[BSZ-2] = '\0';
	buff[BSZ-1] = 'X';
	printf("%s\n%d\n", buff, (int)strlen(buff));
	if ((fp = fmemopen(buff, BSZ, "w+")) == NULL)
		err_sys("fmemopen error");
	fprintf(fp, "hello world");
	fflush(fp);
	printf("%s%d\n%c", buff, (int)strlen(buff),buff[40]);
	exit(0);

}
