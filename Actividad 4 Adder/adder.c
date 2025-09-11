#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){

	int arg1, arg2, res;
	printf("Argc = %d\n", argc);
	if(argc != 3)
	{
		return -1;
	}
	printf("Argc[1] = %s\n", argv[1]);
	printf("Argc[2] = %s\n", argv[2]);
	arg1 = atoi(argv[1]);
	arg2 = atoi(argv[2]);
	res = arg1 + arg2;
	printf("Result: %d\n", res);
	return 0;
}
