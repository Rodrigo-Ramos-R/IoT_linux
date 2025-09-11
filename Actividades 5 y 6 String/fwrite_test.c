#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN 50
#define ELEMENTS 3

typedef struct {
    int id;
    float data;
    char name[LEN];
} sAnalogData_t;

sAnalogData_t aData[ELEMENTS] = {
    {0, 3.1416, "Temperature"},
    {1, 1.18, "Humidity"},
    {2, 23.5, "Pressure"}
};

void fwrite_test() {
    FILE *fout = fopen("AnalogData.bin", "wb");
    if (!fout) {
        perror("fopen");
        exit(-1);
    }
    fwrite((void *)aData, sizeof(sAnalogData_t), ELEMENTS, fout);
    fclose(fout);
}

int main(int argc, char *argv[]) {
    printf("Hi from %s\n", argv[0]);

    fwrite_test();

    return 0;
}
