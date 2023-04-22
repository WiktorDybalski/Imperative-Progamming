#include <math.h>
#include <stdio.h>

//Kolejka z przesuwaniem w tablicy

#define QUEUE_SIZE  10

int queue[QUEUE_SIZE];
int in=0, curr_nr=0;  // 1. klient dostanie nr = 1

void print_array(int n, int array[]) {
    for(int i = 0; i < n; i++) {
        printf("%d", array[i]);
        printf(" ");
    }
    printf("\n");
}

double queue_push(int how_many) {
    
    for(int i = 0; i < how_many; i++) {
        if (in >= QUEUE_SIZE) {
            curr_nr += how_many - i;
            return INFINITY;
        }
        curr_nr++;
        queue[in] = curr_nr;
        in++;
    }
    return 0.0;
}

void queue_print(void) {
    if (in == 0) {
        printf("THe queue is empty");
    }
    for(int i = 0; i < in; i++) {
        printf("%d", queue[i]);
    }
}

int queue_pop(int how_many) {
    if (in == 0) {
        printf("Queue is already empty");
        return 0;
    } else if (how_many > in){
        in = 0;
        return -1;
    } else {
        int temp_int = in;
        for(int i = 0; i < (temp_int - how_many); i++) {
            queue[i] = queue[i + how_many];
        }
        in -= how_many;
        return in;
    }
}
int queue_state(void) {
    return in;
}

int main() {
    queue_print();
    printf("\n");
    queue_push(1);
    queue_print();
    printf("\n");
    queue_push(3);
    queue_print();
    printf("\n");
    queue_push(5);
    queue_print();
    printf("\n");
    queue_pop(2);
    queue_print();
    printf("\n");
    queue_push(7);
    queue_print();
    printf("\n");
    queue_pop(3);
    queue_print();
    printf("\n");
    queue_pop(9);
    queue_print();
    printf("\n");
    queue_push(3);
    queue_print();
    printf("\n");
    queue_pop(1);
    queue_print();
    printf("\n");
    printf("\n%d\n", queue_state());
}