#include <cstdio>
#include <cmath>

#include "vector.hpp"
#include "convolve_filter.hpp"
#include "upscale_filter.hpp"
#include "downscale_filter.hpp"
#include "composed_filter.hpp"



Vector performWavelet(const Vector &input)
{
    if (input.getNonZeroCount() <= 1)
    {
        return input;
    }

    double sq = 1.0 / sqrt(2);
    Vector h(-1, 0, new double[2]{ -sq, sq });
    Vector g(-1, 0, new double[2]{  sq, sq });

    ConvolveFilter H1(h);
    ConvolveFilter H2(h.reverse());

    ConvolveFilter G1(g);
    ConvolveFilter G2(g.reverse());

    UpscaleFilter up;
    DownscaleFilter down;

    Vector a = down.perform(H1.perform(input));
    Vector b = down.perform(G1.perform(input));

    a = H2.perform(up.perform(a));
    b = G2.perform(up.perform(performWavelet(b)));

    return a + b;
}



void saveVector(const Vector &v, const char *fileName)
{
    FILE *file = fopen(fileName, "w");
    for (int i = v.getStart(); i <= v.getEnd(); i++)
    {
        fprintf(file, "%d %lf\n", i, v[i]);
    }

    fclose(file);
}



int main()
{
    int start = 0;
    int end = 2047;
    Vector x(start, end);

    for (int i = start; i <= end; i++)
    {
        x[i] = sin(i * 0.01) + sin(i * 0.1);
    }

    Vector y = performWavelet(x);
    y.trim();

    saveVector(x, "input.ssv");
    saveVector(y, "output.ssv");

    return 0;
}