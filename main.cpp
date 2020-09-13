#include <cstdio>
#include "vector.hpp"

int main()
{
    Vector v1(-1000000, -1);
    Vector v2(1, 1000000);

    for (int i = 0; i < 1000000; i++)
    {
        v1[-i] = -i;
        v2[i] = i;
    }

    Vector v3 = v1 + v2 * 3;
    for (int i = 0; i < 1000; i++)
    {
        v3 += v2;
        v3 *= 0.3;
    }

    double sum = 0.0;
    for (int i = -1000000; i < 1000000; i++)
    {
        sum += v3[i];
    }

    printf("%lf\n", sum);

    return 0;
}