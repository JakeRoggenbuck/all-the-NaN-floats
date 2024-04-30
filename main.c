#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;

    fp = fopen("all-the-nan-floats", "wb");

    unsigned int start = 0b011111111 << 23;
    unsigned int end = (1 << 31) - 1u;

    int counter = 0;

    do {
        fwrite(&start, sizeof(unsigned int), 1, fp);
        start = -start;
        fwrite(&start, sizeof(unsigned int), 1, fp);
        start = -start;

        start++;
        counter++;
        counter++;
    } while (start < end);

    printf("Wrote %d NaN floats", counter);
}
