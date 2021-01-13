#ifndef WAVE_FILTER_CLASS_HPP
#define WAVE_FILTER_CLASS_HPP

#include <cmath>
#include "vector.hpp"

/*
 * Represents the filter that is performed over signals.
 */
class Filter
{
public:
    virtual ~Filter(){}
    virtual Vector perform(const Vector &input) const = 0;
};

#endif