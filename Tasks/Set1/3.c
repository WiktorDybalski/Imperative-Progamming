/*3. double dot product(const double v1[], const double v2[], int n);
Funkcja oblicza i zwraca iloczyn skalarny wektorów v1 i v2 o długości n.*/

#include <stdio.h>

double dot product(const double v1[], const double v2[], int n) {
    int il = 0;
    for (int i = 0; i <n; i++) {
        il += v1[i] * v2[i];
    }
    return il;
}

int main {
    printf("siemano!");
    return 0;
}