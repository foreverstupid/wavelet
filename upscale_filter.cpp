#include "upscale_filter.hpp"

Vector UpscaleFilter::perform(const Vector &input) const
{
    int start = input.getStart() * 2;
    int count = input.getNonZeroCount() * 2;
    Vector result(start, start + count - 1);

    for (int i = start; i < start + count; i++)
    {
        result[i] =
            i % 2 == 0
            ? input[i / 2]
            : 0;
    }

    return result;
}