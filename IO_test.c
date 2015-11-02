#include "apue.h"

int main(void){
	FILE* fp;
	char buf[MAXLINE];
	char buf_test[4095] = "helloworld";
	char buf_test1[4097] = {'b','b'};
	
	fp = fopen("test", "w+");
	fputs(buf_test, fp);
	
	char c;
	c = getchar();
	fflush(fp);
	
	printf("%d", (int)strlen(buf_test));
	
	fputs(buf_test, stdout);
	fputs(buf_test1, stdout);

	while(fgets(buf, MAXLINE, stdin) != NULL){
		if(fputs(buf, stdout) == EOF){
			err_sys("output error");
		}
	}

	if(ferror(stdin)){
		err_sys("input error");
	}

	exit(0);
}
