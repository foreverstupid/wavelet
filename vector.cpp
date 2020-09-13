#include "vector.hpp"

double Vector::eps = 1e-10;

void Vector::operator=(const Vector &vector)
{
    if (this == &vector)
    {
        return;
    }

    int count = vector.nonZeroCount();
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
    int newCount = this->nonZeroCount();

    if (newCount > this->capacity)
    {
        this->capacity = newCount;
        this->data = (double *)realloc(this->data, newCount * sizeof(double));
    }

    #pragma omp parallel for
    for (int i = this->start; i <= this->end; i++)
    {
        this->data[i - this->start] += vector[i];
    }
}

void Vector::operator-=(const Vector &vector)
{
    this->start = min(this->start, vector.start);
    this->end = max(this->end, vector.end);
    int newCount = this->nonZeroCount();

    if (newCount > this->capacity)
    {
        this->capacity = newCount;
        this->data = (double *)realloc(this->data, newCount * sizeof(double));
    }

    #pragma omp parallel for
    for (int i = this->start; i <= this->end; i++)
    {
        this->data[i - this->start] -= vector[i];
    }
}

void Vector::operator*=(double f)
{
    #pragma omp parallel for
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

    #pragma omp parallel for
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

    #pragma omp parallel for
    for (int i = newStart; i <= newEnd; i++)
    {
        newData[i - newStart] = (*this)[i] - vector[i];
    }

    return Vector(newStart, newEnd, newData);
}

Vector Vector::operator*(double f) const
{
    int newCapacity = this->nonZeroCount();
    double *newData = (double *)malloc(newCapacity * sizeof(double));

    #pragma omp parallel for
    for (int i = this->start; i <= this->end; i++)
    {
        newData[i - this->start] = (*this)[i] * f;
    }

    return Vector(this->start, this->end, newData);
}

void Vector::copy(double *dst, double *src, int cnt)
{
    #pragma omp parallel for
    for (int i = 0; i < cnt; i++)
    {
        dst[i] = src[i];
    }
}