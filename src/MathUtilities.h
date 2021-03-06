#ifndef MATH_UTILITIES_H
#define MATH_UTILITIES_H

#include <cmath>
#include <cstdint>

#define PI 3.14159f

typedef float real;
typedef int32_t int32;
typedef bool boolean;

namespace math 
{
    int32 ToNearestInt(real x);

    template <typename T>
    T Max(T const &a, T const &b) 
    {
        return a > b ? a: b;
    }

    template <typename T>
    T Max(T const &a, T const &b, T const &c) 
    {
        return Max(Max(a, b), c);
    }

    template <typename T>
    T Max(T const &a, T const &b, T const &c, T const &d) 
    {
        return Max(Max(a, b, c), d);
    }

    template <typename T>
    T Min(T const &a, T const &b) 
    {
        return a < b ? a: b;
    }

    template <typename T>
    T Min(T const &a, T const &b, T const &c) 
    {
        return Min(Min(a, b), c);
    }

    template <typename T>
    T Min(T const &a, T const &b, T const &c, T const &d) 
    {
        return Min(Min(a, b, c), d);
    }

    template <typename T>
    T Clamp(T x, T lo, T hi) 
    {
        if(hi < lo) {
            T tmp = lo;
            lo = hi;
            hi = tmp;
        }
        if(x < lo) x = lo;
        if(x > hi) x = hi;
        return x;
    }

    /*
        // Precise method
        http://en.wikipedia.org/wiki/Linear_int32erpolation
        
        lo + t * (hi - lo)
        lo + t * hi - t * lo
        (lo - t * lo) + t * hi
        (1 - t) * lo + t * hi
    */
    template <typename T>
    T Lerp(T const &lo, T const &hi, real t) 
    {
        return (1 - t) * lo + t * hi;
    }

    real ToDegrees(real radians);
    
    real ToRadians(real degrees);

    real CalcAngularDistanceInRadians(real angle1InRadians, real angle2InRadians);

    real CalcAngularDistanceInDegrees(real angle1InDegrees, real angle2InDegrees);

    boolean IsPowerOf2(int32 x);

    boolean IsNear(real lhs, real rhs, real epsilon = 0.001);
}

#endif
