#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

// Losuje jedna liczbe calkowita z przedzialu [a,b] stosujac funkcje rand() i operator %
// Jezeli a>b to zwraca INT_MIN
// Jezeli b-a > RAND_MAX to zwraca INT_MAX
// Jezeli a=b to zwraca a (bez wywolywania funkcji rand)
// Else zwraca liczbe z przedzialu [a,b]

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

int main() {
    printf("%d", rand_from_interval(3, 30));
    return 0;
}