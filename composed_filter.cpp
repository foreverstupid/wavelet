#include "composed_filter.hpp"

ComposedFilter::~ComposedFilter()
{
    for (int i = 0; i < count; i++)
    {
        delete filters[i];
    }

    delete filters;
}



Vector ComposedFilter::perform(const Vector &input) const
{
    Vector result = input;

    for (int i = 0; i < count; i++)
    {
        result = filters[i]->perform(result);
    }

    return result;
}