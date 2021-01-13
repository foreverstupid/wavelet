#ifndef WAVE_UPSCALE_FILTER_CLASS_HPP
#define WAVE_UPSCALE_FILTER_CLASS_HPP

#include "filter.hpp"
#include "vector.hpp"

class UpscaleFilter : public Filter
{
public:
    Vector perform(const Vector &input) const;
};

#endif