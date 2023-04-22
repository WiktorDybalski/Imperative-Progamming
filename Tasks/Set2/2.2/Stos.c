#include <stdio.h>
#include <math.h>

// Stos

#define STACK_SIZE  10

double stack[STACK_SIZE];
int top = 0;   // jawne zerowanie nie jest konieczne

void print_stack() {
    if (top == 0) {  // sprawdzenie, czy stos jest pusty
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--) {  // iteracja od szczytu stosu do jego podstawy
            printf("%lf\n", stack[i]);  // wypisanie kolejnych wartości stosu
        }
    }
}

double stack_push(double x) {
    if (top < STACK_SIZE - 1) 
    {
        stack[top] = x;
        top++;
        return 0;
    }
        return INFINITY;
}

double stack_pop(void) {
    if (top == 0) {
        return NAN;

    } else {
        int x = stack[top];
        stack[top] = 0;
        top -= 1;
        return x;
    }
}

int stack_state(void) {
    return top;
}

int main() {
    print_stack();
    stack_push(5);
    print_stack();
    stack_push(3);
    print_stack();
    stack_push(9);
    print_stack();
    printf("%d\n", stack_state());
    print_stack();
    printf("%f\n", stack_pop());
    print_stack();
    printf("%f\n", stack_pop());
    print_stack();
    return 0;
}
