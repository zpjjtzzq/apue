#include <apue.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main() {
    umask(0);
    if (creat("foo",RWRWRW) < 0)
	    printf("creat error for foo\n");
    err_sys("lalala");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0)
	    printf("creat error for bar\n");
    struct stat statbuf;

    if (stat("foo", &statbuf) < 0)
	    printf ("stat error for foo");
    exit(0);
}
