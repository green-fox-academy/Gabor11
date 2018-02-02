#include <stdio.h>

float values[6] = {3.2, 3.0, 4.2, 6.3, 5.5, 7.8};

float sum(float val[], int size);

int main()
{
    printf("%g\n", sum(values, 6));
    return 0;
}

float sum(float val[], int size)
{
    float ret = 0;
    for (int i = 0; i < size; ++i) {
        ret += val[i];
    }

    return ret;
}
