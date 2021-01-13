#ifndef WAVE_CONVOLVE_FILTER_CLASS_HPP
#define WAVE_CONVOLVE_FILTER_CLASS_HPP

#include "filter.hpp"
#include "vector.hpp"

/*
 * The filter that acts on the vector via convolution.
 */
class ConvolveFilter : public Filter
{
    Vector kernel; /* the vector the filter is used for convolution */

public:
    ConvolveFilter(Vector kernel) : kernel(kernel) {}

    Vector perform(const Vector &input) const
    {
        return input.convolve(kernel);
    }

private:
    ConvolveFilter(ConvolveFilter &other);
    void operator=(ConvolveFilter &other);
};

#endif