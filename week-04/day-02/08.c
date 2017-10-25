#include <stdio.h>

typedef struct complex
{
    float real;
    float imag;
} complex;

complex sum(complex n1, complex n2)
{
    complex nsum;

    nsum.real = n1.real + n2.real;

    nsum.imag = n1.imag + n2.imag;

    return nsum;
}

complex sub(complex n1, complex n2)
{
    complex nsub;

    nsub.real = n1.real - n2.real;

    nsub.imag = n1.imag - n2.imag;

    return nsub;
}

complex mul(complex n1, complex n2)
{
    complex nmul;

    nmul.real = n1.real * n2.real - n1.imag * n2.imag;

    nmul.imag = n1.imag * n2.real + n2.imag * n1.real;

    return nmul;
}

//TODO: create 3 functions, which calculates the sum, subtraction and multiplication of a complex number.
// you can read about complex number's operations here: https://www.mathsisfun.com/numbers/complex-numbers.html

int main()
{
    complex n1, n2;
    n1.real = 5;
    n1.imag = 7.2;

    n2.real = 6;
    n2.imag = 8.1;

    printf("n2 * n1 =\n nsub.real: %.2f nsub.imag: %.2f\n", mul(n2, n1).real, mul(n2, n1).imag);

    return 0;
}


