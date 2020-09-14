#include <cstdio>
#include <cmath>

#include "vector.hpp"

int main()
{
    int len = 10;
    Vector x(0, 0);
    Vector h(-len, len);

    x[0] = 1.0;
    for (int i = -len; i <= len; i++)
    {
        h[i] = sin(i * 0.01);
    }

    Vector y = h.convolve(x);

    printf("Convolution of { sin(0.01 * i), i=-10,10 } with delta:\n");
    printf("Resulting non-zero count: %d\n", y.getNonZeroCount());
    printf("[ ");
    for (int i = y.getStart(); i <= y.getEnd(); i++)
    {
        printf("%lf ", y[i]);
    }

    putchar(']');
    return 0;
}