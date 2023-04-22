#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 100

// Returns an integer from [a,b] using library function rand() and operator %
// if a > b return INT_MIN
// if b - a > RAND_MAX return INT_MAX
// if a == b return a
// else return integer from [a,b]
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

void swap(int array[], int i, int k)
{
    int temp = array[i];
    array[i] = array[k];
    array[k] = temp;
}

// random permutation of integers from [0, n-1]
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

// bubble sort (increasing order)
// returns number of iterations of the external loop
// after which the array is sorted
// for { 0 1 2 3 7 4 5 6 } -> 1,
// for { 1 2 3 7 4 5 6 0 } -> 7,
// for { 0 1 2 3 4 5 6 7 } -> 0.

void print_array(int n, int array[])
{
    for (int a = 0; a < n; a++)
    {
        printf("%d ", array[a]);
    }
    printf("\n");
}

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

int main(void)
{
    int to_do, seed;
    int a, b, m, n;
    int array[N];

    scanf("%d %d", &to_do, &seed);
    srand((unsigned)seed); // set the seed

    switch (to_do)
    {
    case 1:
        scanf("%d %d %d", &a, &b, &m);
        for (int i = 0; i < m; ++i)
        {
            printf("%d ", rand_from_interval(a, b));
        }
        printf("\n");
        break;
    case 2:
        scanf("%d", &n);
        rand_permutation(n, array);
        for (int i = 0; i < n; ++i)
            printf("%d ", array[i]);
        printf("\n");
        break;
    case 3:
        scanf("%d", &n);
        rand_permutation(n, array);
        printf("%d\n", bubble_sort(n, array));
        break;
    default:
        printf("NOTHING TO DO!\n");
        break;
    }
    return 0;
}