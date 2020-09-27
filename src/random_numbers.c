#include <stdlib.h>
#include <stdio.h>
#include "random_numbers.h"
#include <time.h>

void make_arr(int* a, int size)
{
    for(int i = 0; i < size; i++)
        a[i] = i + 1;
}

void shuffle(int* chisla, int N )
{
    srand(time(NULL));
    for (int i = N - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);
        int tmp = chisla[j];
        chisla[j] = chisla[i];
        chisla[i] = tmp;
    }
}
