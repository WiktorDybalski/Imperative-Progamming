#include <stdio.h>
#include <math.h>

//Kolejka w buforze cyklicznym

#define CBUFF_SIZE  10

int cbuff[CBUFF_SIZE];
int out=0, len=0;

double cbuff_push(int cli_nr) {
    if (len >= CBUFF_SIZE) {
        return INFINITY;
    }
    cbuff[(out + len) % 10] = cli_nr;
    len++;
    return 0.0;
}

int cbuff_pop(void) {
    if (len == 0) {
        return -1;
    }
    int x = cbuff[out];
    out = (out + 1) % 10;
    len--;
    return x;
}

int cbuff_state(void) {
    return len;
}

void cbuff_print(void) {
    if (len == 0) {
        printf("The cbuff is empty\n");
        return;
    }
    for(int i = 0; i < len; i++) {
        printf("d", cbuff[(out + i) % 10]);
    }
    printf("\n");
}

int main() {
    cbuff_pop();
    return 0;
}