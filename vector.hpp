#ifndef WAVE_VECTOR_CLASS_HPP
#define WAVE_VECTOR_CLASS_HPP

#include <cstdlib>

/*
 * Represents an infinite vector with a finite number
 * of non-zero elements.
 */
class Vector
{
    static double eps;  /* the value that is thought as zero */

    int start;          /* the first non-zero element index */
    int end;            /* the last non-zero element index */
    int capacity;       /* Note: the storage always starts with the first
                           non-zero element, but it can contains more data
                           than it is necessary for contains all non-zero
                           elements. That is done for
                           reducing memory operations. */
    double *data;       /* the elements storage */

public:
    Vector(int start, int end)
        : start(start), end(end), capacity(end - start + 1)
    {
        data = (double *)malloc(capacity * sizeof(double));
    }

    Vector(const Vector &vector)
        : start(vector.start),
          end(vector.end),
          capacity(vector.end - vector.start + 1)
    {
        data = (double *)malloc(capacity * sizeof(double));
        copy(data, vector.data, capacity);
    }

    ~Vector()
    {
        if (data != NULL)
        {
            free(data);
        }
    }

    void operator=(const Vector &vector);
    void operator+=(const Vector &vector);
    void operator-=(const Vector &vector);
    void operator*=(double f);
    Vector operator+(const Vector &vector) const;
    Vector operator-(const Vector &vector) const;
    Vector operator*(double f) const;
    friend Vector operator*(double f, const Vector &vector)
    {
        return vector * f;
    };

    double operator[](int idx) const
    {
        if (idx < start || idx > end)
        {
            return 0.0;
        }

        return data[idx - start];
    }

    double &operator[](int idx)
    {
        if (idx < start || idx > end)
        {
            return data[0];     /* TODO: resize vector */
        }

        return data[idx - start];
    }

    /* returns the count of elements between the first
       and the last non-zero ones inclusive */
    int getNonZeroCount() const
    {
        return this->end - this->start + 1;
    }

    int getStart() const { return this->start; };
    int getEnd() const { return this->end; };

    /* performs convolution with another vector */
    Vector convolve(const Vector &vector) const;

private:
    Vector(int start, int end, double *data)
        : start(start), end(end), capacity(end - start + 1), data(data)
    {
    }

    static void copy(double *dst, double *src, int cnt);
    static int min(int a, int b) { return a < b ? a : b; };
    static int max(int a, int b) { return a > b ? a : b; };
};

#endif
