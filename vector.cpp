#include "vector.hpp"

double Vector::eps = 1e-10;

void Vector::operator=(const Vector &vector)
{
    if (this == &vector)
    {
        return;
    }

    int count = vector.getNonZeroCount();
    if (this->capacity < count)
    {
        this->capacity = count;
        this->data = (double *)realloc(this->data, count * sizeof(double));
    }

    copy(this->data, vector.data, count);
    this->start = vector.start;
    this->end = vector.end;
}

void Vector::operator+=(const Vector &vector)
{
    this->start = min(this->start, vector.start);
    this->end = max(this->end, vector.end);
    int newCount = this->getNonZeroCount();

    if (newCount > this->capacity)
    {
        this->capacity = newCount;
        this->data = (double *)realloc(this->data, newCount * sizeof(double));
    }

    for (int i = this->start; i <= this->end; i++)
    {
        this->data[i - this->start] += vector[i];
    }
}

void Vector::operator-=(const Vector &vector)
{
    this->start = min(this->start, vector.start);
    this->end = max(this->end, vector.end);
    int newCount = this->getNonZeroCount();

    if (newCount > this->capacity)
    {
        this->capacity = newCount;
        this->data = (double *)realloc(this->data, newCount * sizeof(double));
    }

    for (int i = this->start; i <= this->end; i++)
    {
        this->data[i - this->start] -= vector[i];
    }
}

void Vector::operator*=(double f)
{
    for (int i = this->start; i <= this->end; i++)
    {
        this->data[i - this->start] *= f;
    }
}

Vector Vector::operator+(const Vector &vector) const
{
    int newStart = min(this->start, vector.start);
    int newEnd = max(this->end, vector.end);
    int newCapacity = newEnd -newStart + 1;
    double *newData = (double *)malloc(newCapacity * sizeof(double));

    for (int i = newStart; i <= newEnd; i++)
    {
        newData[i - newStart] = (*this)[i] + vector[i];
    }

    return Vector(newStart, newEnd, newData);
}

Vector Vector::operator-(const Vector &vector) const
{
    int newStart = min(this->start, vector.start);
    int newEnd = max(this->end, vector.end);
    int newCapacity = newEnd - newStart + 1;
    double *newData = (double *)malloc(newCapacity * sizeof(double));

    for (int i = newStart; i <= newEnd; i++)
    {
        newData[i - newStart] = (*this)[i] - vector[i];
    }

    return Vector(newStart, newEnd, newData);
}

Vector Vector::operator*(double f) const
{
    int newCapacity = this->getNonZeroCount();
    double *newData = (double *)malloc(newCapacity * sizeof(double));

    for (int i = this->start; i <= this->end; i++)
    {
        newData[i - this->start] = (*this)[i] * f;
    }

    return Vector(this->start, this->end, newData);
}

Vector Vector::convolve(const Vector &vector) const
{
    int newStart = this->start + vector.start;
    int newEnd = this->end + vector.end;
    Vector result(newStart, newEnd);

    for (int i = newStart; i <= newEnd; i++)
    {
        result[i] = 0.0;
        for (int j = vector.start; j <= vector.end; j++)
        {
            result[i] += vector[j] * (*this)[i - j];
        }
    }

    return result;
}

Vector Vector::reverse() const
{
    Vector result(-this->end, -this->start);
    for (int i = end; i >= start; i--)
    {
        result[-i] = (*this)[i];
    }

    return result;
}

void Vector::copy(double *dst, double *src, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        dst[i] = src[i];
    }
}