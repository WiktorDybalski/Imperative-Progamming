/* 1. void linspace(double v[], double start, double stop, int n);
Funkcja wypełnia tablicę rzeczywistą v n wartościami równomiernie rozłożonymi
w przedziale [start, stop]. Wartość n powinna być nieujemna; dla n =
1 funkcja wpisuje do początkowego elementu tablicy wartość start. Dla
n = 0 funkcja nie zmienia zawartości tablicy.*/

// #include <stdio.h>

void linspace(double v[], double start, double stop, int n) {
    if (n <= 0) {
        return;
    }
    else if (n == 1) {
        if (v[0] = start);
        return;
    }
    else {
        for (int i = 0; i <= stop; i++) {
            if (i < start || i > stop) {
                v[i] = 0;
            }
            else {
                v[i] = n;
            }
        }
        return;
    }
}

void print_vector(const double v[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%.2f ", v[i]);
	}
	printf("\n");
}

int main() {
    printf("siemano!");
    double start, stop;
    int n, N;
    scanf("%d, %d, %f, %f", &N, &n, &start, &stop);
    double v1[N];
    linspace(v1, start, stop, n);
    print_vector(v1, N);
    return 0;
}