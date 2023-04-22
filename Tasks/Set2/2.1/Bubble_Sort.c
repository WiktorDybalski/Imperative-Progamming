// np. dla { 0 1 2 3 7 4 5 6 } -> 1,
//     dla { 1 2 3 7 4 5 6 0 } -> 7,
//     dla { 0 1 2 3 4 5 6 7 } -> 0.

#include <stdio.h>

int bubble_sort(int n,int tab[]) {
    int x = -1;
    int change = 1;
    int temp;
    int cnt = 0;
    while (change) {
        x += 1;
        change = 0;
        for(int i = 0; i < n - x - 1; i++) {
            if (tab[i] > tab[i + 1]){
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                change = 1;
            }
        }
        if (change == 0) {
            return cnt;
        }
        cnt += 1;
    }
    return cnt;
}

void print_array(int n, int array[]) {
    for(int i = 0; i < n; i++) {
        printf("%d", array[i]);
        printf(" ");
    }
    printf("\n");
}

int main() {
    int array1[] = {0, 1, 2, 3, 7, 4, 5, 6};
    int array2[] = {1, 2, 3, 7, 4, 5, 6, 0};
    int array3[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(array2) / sizeof(int);
    printf("%d", bubble_sort(n, array2));
    return 0;
}

