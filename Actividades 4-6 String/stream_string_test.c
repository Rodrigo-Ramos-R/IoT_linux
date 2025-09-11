#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN 50

void stream_string_test() {
    FILE *fout, *fin;
    char line[LEN+1];

    fout = fopen("test_file_string.txt", "wa");
    if (fout == NULL) {
        perror("fopen");
        exit(-1);
    }

    printf("File descriptor of test_file_char.txt is %d\n", fileno(fout));

    fin = fdopen(0, "r");
    if (fin == NULL) {
        perror("fdopen");
        exit(-1);
    }

    while (fgets(line, sizeof(line), fin) != NULL) {
        fputs(line, fout);
    }

    fclose(fout);
}


int main(int argc, char *argv[]) {
    int stdin_bup;
    FILE *fstdin_bup;

    printf("Hi from %s\n", argv[0]);

    stdin_bup = dup(0);
    fstdin_bup = fdopen(stdin_bup, "r");

    //stream_char_test();
    stream_string_test();
    //fwrite_test();
    //fread_fseek_test();

    return 0;
}
