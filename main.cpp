#include <cstdio>
#include <cmath>

#include "vector.hpp"

int main()
{
    int len = 10;
    Vector v1(-len, len);
    Vector v2(-len, len);

    for (int i = -len; i <= len; i++)
    {
        v1[i] = sin(i * 0.01);
        v2[i] = sin(i * 0.01);
    }

    Vector v3 = v1.convolve(v2);

    printf("Convolution of { sin(0.01 * i), i=-10,10 } with itself:\n");
    printf("Resulting non-zero count: %d\n", v3.getNonZeroCount());
    printf("[ ");
    for (int i = v3.getStart(); i <= v3.getEnd(); i++)
    {
        printf("%lf ", v3[i]);
    }

    putchar(']');
    return 0;
}