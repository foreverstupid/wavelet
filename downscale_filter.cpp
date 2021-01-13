#include "downscale_filter.hpp"

Vector DownscaleFilter::perform(const Vector &input) const
{
    int start = input.getStart() / 2;
    int count = input.getNonZeroCount() / 2;
    Vector result(start, start + count -1);

    for (int i = start; i < start + count; i++)
    {
        result[i] = input[2 * i];
    }

    return result;
}