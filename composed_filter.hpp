#ifndef WAVE_COMPOSED_FILTER_CLASS_HPP
#define WAVE_COMPOSED_FILTER_CLASS_HPP

#include "filter.hpp"
#include "vector.hpp"

class ComposedFilter : public Filter
{
    Filter **filters;
    int count;

public:
    ComposedFilter(Filter **filters, int count)
        : filters(filters), count(count) {}

    ~ComposedFilter();

    Vector perform(const Vector &input) const;
};

#endif