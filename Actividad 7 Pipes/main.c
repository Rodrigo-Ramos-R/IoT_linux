#include "processes.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){

	pid_t ret;
	int pfd[2];

	int ret_pipe = pipe(pfd);
	ret = fork();

	if ( ret == 0){
		child_process(pfd[0]);
	} else if( ret > 0){
		parent_process(pfd[1]);
	} else{
		printf("Error creating process\n");
	}

	return 0;
}
