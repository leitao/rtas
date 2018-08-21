#include <stdio.h>
#include <unistd.h>
#include <endian.h>

#define __NR_rtas               255

typedef int rtas_arg_t;


/* Syscall expected structure */
struct rtas_args {
        int token;
        int nargs;
        int nret; 
        rtas_arg_t args[16];
        rtas_arg_t *rets;     /* Pointer to return values in args[]. */
};  



int main(){
	struct rtas_args ra;
	int ret;

	ra.nargs = htobe32(0x1);
	ra.nret = 0;

	ret = syscall(__NR_rtas, &ra);

	printf("ret = %d\n", ret);
	perror("error\n");

	return 0;
}
