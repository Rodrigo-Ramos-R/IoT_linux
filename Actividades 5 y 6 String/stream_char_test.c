#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN 50

void stream_char_test(){
	FILE * fout, *fin;
	char line[LEN+1];
	int c;

	fout = fopen("test_file_char.txt", "wa");
	printf ("File descriptor of test_file.txt is %d\n", fileno(fout));

	fin = fdopen(0, "r");

	if( fout == (FILE *)NULL)
		exit(-1);

	do{
		c = fgetc(fin);
		fputc(c, fout);
	}while( c != EOF);

	fclose(fout);

}

int main(int argc, char *argv[]) {
    int stdin_bup;
    FILE *fstdin_bup;

    printf("Hi from %s\n", argv[0]);

    stdin_bup = dup(0);
    fstdin_bup = fdopen(stdin_bup, "r");

    stream_char_test();
    //stream_string_test();
    //fwrite_test();
    //fread_fseek_test();

    return 0;
}



