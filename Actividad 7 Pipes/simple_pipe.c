#include <stdio.h>
#include <unistd.h>

#define MAX_CHAR 80
#define PIPE_IN 1
#define PIPE_OUT 0


int main(int argc, char * argv[]){

	int fds[2];
	char buff[MAX_CHAR];
	char pipeBuffOut[MAX_CHAR];

	/*create pipe file descriptors*/
	int ret = pipe(fds);

	/*reads console line*/
	char * str = fgets(buff, MAX_CHAR, stdin);

	/*Writes the entry as input into Pipe*/
	ret = write(fds[PIPE_IN], buff, MAX_CHAR);

	/*reads the output of the pipe */
	ret = read(fds[PIPE_OUT], pipeBuffOut, MAX_CHAR);

	/*Prints the output of the Pipe*/
	printf("%s", pipeBuffOut);

	return 0;
}



