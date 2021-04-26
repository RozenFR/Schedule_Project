#include <stdio.h>
#include <stdlib.h>
#include "../include/utilities.h"

void error(char * msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int intmax(int a, int b) {
    if (a >= b)
        return a;
    else
        return b;
}

int intmin(int a, int b) {
    if (a <= b)
        return a;
    else
        return b;
}

void viewInt(const void *i) {
    printf("%d ", *((int*)i));
}

void freeInt(void * i) {
    free((int*) i);
}

int compareInt(const void* a, const void* b) {
    if (*((int*) a) < *((int*) b))
        return 1;
    else
        return 0;
}