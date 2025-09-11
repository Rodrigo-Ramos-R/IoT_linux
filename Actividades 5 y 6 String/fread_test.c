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

// Optional: reference data for comparison
sAnalogData_t aData[ELEMENTS] = {
    {0, 3.1416, "Temperature"},
    {1, 1.18, "Humidity"},
    {2, 23.5, "Pressure"}
};

void fread_test() {
    FILE *fin = fopen("AnalogData.bin", "rb");
    if (!fin) {
        perror("fopen");
        exit(-1);
    }

    printf("Reading all records with fread:\n");
    sAnalogData_t readData[ELEMENTS];
    size_t nread = fread(readData, sizeof(sAnalogData_t), ELEMENTS, fin);
    printf("Read %zu elements\n", nread);
    for (size_t i = 0; i < nread; i++) {
        printf("Record %d: %.2f %s\n", readData[i].id, readData[i].data, readData[i].name);
    }

    printf("\nRewinding file and reading again:\n");
    rewind(fin);
    sAnalogData_t temp;
    while (fread(&temp, sizeof(sAnalogData_t), 1, fin) == 1) {
        printf("Record %d: %.2f %s\n", temp.id, temp.data, temp.name);
    }

    printf("\nUsing fseek to read 2nd record only:\n");
    fseek(fin, sizeof(sAnalogData_t) * 1, SEEK_SET); // index 1 = 2nd record
    sAnalogData_t second;
    fread(&second, sizeof(sAnalogData_t), 1, fin);
    printf("Record %d: %.2f %s\n", second.id, second.data, second.name);

    fclose(fin);
}

int main(int argc, char *argv[]) {
    printf("Hi from %s\n", argv[0]);

    fread_test();

    return 0;
}
