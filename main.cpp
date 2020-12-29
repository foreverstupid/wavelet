#include <cstdio>
#include <cmath>

#include "vector.hpp"
#include "convolve_filter.hpp"

ConvolveFilter *getFilter()
{
    Vector *vector = new Vector(0, 0);
    (*vector)[0] = 1.0;
    return new ConvolveFilter(vector);
}

void printVector(const Vector &y)
{
    printf("[ ");
    for (int i = y.getStart(); i <= y.getEnd(); i++)
    {
        printf("%lf ", y[i]);
    }

    putchar(']');
}

int main()
{
    int len = 10;
    Vector h(-len, len);

    for (int i = -len; i <= len; i++)
    {
        h[i] = sin(i * 0.01);
    }

    Filter *filter = getFilter();
    Vector y = filter->perform(h);

    printf("Convolution of { sin(0.01 * i), i=-10,10 } with delta:\n");
    printf("Input:  ");
    printVector(h);
    printf("\nOutput: ");
    printVector(y);
    putchar('\n');

    return 0;
}