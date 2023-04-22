#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

void print_array(int n, int array[]) {
    for(int i = 0; i < n; i++) {
        printf("%d", array[i]);
        printf(" ");
    }
    printf("\n");
}

// Losowa permutacja elementow zbioru liczb {0, 1, 2,..., n-1} (z rozkladem rownomiernym)
// wg algorytmu przedstawionego w opisie zadania
// jest zapisywana w tablicy tab.
// 0 < n <= 100, jezeli nie to elementy tablicy tab maja wartosci nieokreslone.

void swap(int tab[], int a, int b)
{
    int temp = tab[a];
    tab[a] = tab[b];
    tab[b] = temp;
}

int rand_from_interval(int a, int b)
{
    if (a > b) 
    {
        return INT_MIN;
    }
    else if (b - a >  RAND_MAX)
    {
        return INT_MAX;
    }
    else if (a == b)
    {
        return a;
    }
    else 
    {
        int randomNum = (rand() % (b - a + 1)) + a;
        return randomNum;
    }
}

void rand_permutation(int n, int tab[]) {
    if (n <= 0 || n > 100) 
    {
        return;
    }
    else 
    {
        for(int i = 0; i < n; i++) 
        {
            tab[i] = i;    
        }
        for(int j = 0; j < n; j++) 
        {
            int random = rand_from_interval(j, n - 1);
            swap(tab, j, random);
        }
    }
}

int main() 
{
    int array1[10];
    print_array(10, array1);
    rand_permutation(10, array1);
    print_array(10, array1);
    return 0;
}