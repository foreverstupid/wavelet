#include <cstdio>
#include <cmath>

#include "vector.hpp"
#include "convolve_filter.hpp"
#include "upscale_filter.hpp"
#include "downscale_filter.hpp"
#include "composed_filter.hpp"

Filter *getFilter()
{
    Filter **innerFilters = new Filter*[2];
    innerFilters[1] = new UpscaleFilter();
    innerFilters[0] = new DownscaleFilter();

    return new ComposedFilter(innerFilters, 2);
}



void printVector(const Vector &y)
{
    printf("{ ");
    for (int i = y.getStart(); i <= y.getEnd(); i++)
    {
        printf("%15.5e[%2.1d]", y[i], i);
    }

    putchar('}');
}



int main()
{
    int len = 3;
    Vector h(-len, len);

    for (int i = -len; i <= len; i++)
    {
        h[i] = sin(i * 0.01);
    }

    Filter *filter = getFilter();
    Vector y = filter->perform(h);

    printf("Signal: { sin(0.01 * i), i=%d,%d }\n", -len, len);
    printf("Input:  ");
    printVector(h);
    printf("\nOutput: ");
    printVector(y);
    putchar('\n');

    return 0;
}