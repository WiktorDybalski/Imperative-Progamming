/*2. void add(double v1[], const double v2[], int n);
Funkcja dodaje wektory, których elementy są zapisane w początkowych n
elementach rzeczywistych tablic v1 i v2. Funkcja zapisuje wektor będący
sumą na miejscu wektora v1.
*/

#include <stdio.h>

void add(double v1[], const double v2[], int n) {
    for (int i = 0; i <= n; i++);
        v1[i] = v1[i] + v2[i];
}
int main() {
    printf("siemano!");
    return 0;
}