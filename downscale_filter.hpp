#ifndef WAVE_DOWNSCALE_FILTER_CLASS_HPP
#define WAVE_DOWNSCALE_FILTER_CLASS_HPP

#include "filter.hpp"
#include "vector.hpp"

class DownscaleFilter : public Filter
{
public:
    Vector perform(const Vector &input) const;
};

#endif