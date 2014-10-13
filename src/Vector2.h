#ifndef VECTOR2_H
#define VECTOR2_H

typedef float real;

namespace math 
{
    class Vector2 
    {
        public:
            // constructors
            Vector2();
            Vector2(const real x, const real y);
            Vector2(const Vector2 &rhs);

            // functions
            void Normalize();
            void SetXY(const real x, const real y);
            void SetX(const real x);
            void SetY(const real y);
            void SetUnitLengthAndYawRadians(const real angleInRadians);
            void SetUnitLengthAndYawDegrees(const real angleInDegrees);
            void SetLengthAndYawRadians(const real radius, const real angleInRadians);
            void SetLengthAndYawDegrees(const real radius, const real angleInDegrees);
            void SetLength(const real radius);
            void ScaleUniform(const real length);
            void ScaleX(const real length);
            void ScaleY(const real length);
            Vector2& RotateDegrees(const real angleInDegrees);
            Vector2& RotateRadians(const real angleInRadians);
            Vector2& Rotate90Degrees();
            Vector2& RotateMinus90Degrees();
            Vector2& Reverse();
            void GetXY( real& x, real& y );
            real GetX() const;
            real GetY() const;
            real CalcLength() const;
            real CalcLengthSquared() const;
            real CalcYawRadians() const;
            real CalcYawDegrees() const;
            real DotProduct(const Vector2 &rhs) const;

            // operators
            Vector2& operator=(const Vector2 &rhs);
            Vector2& operator+=(const Vector2 &rhs);
            Vector2& operator-=(const Vector2 &rhs);
            Vector2& operator*=(const real uniformScale);
            Vector2& operator/=(const real inverseScale);
            Vector2 operator+(const Vector2 &rhs);
            Vector2 operator+( const float displacement );
            Vector2 operator-(const Vector2 &rhs);
            Vector2 operator-( const float displacement );
            Vector2 operator*(const real uniformScale);
            Vector2 operator/(const real inverseScale);
            Vector2 operator-();
            bool operator==(const Vector2 &rhs);
            bool operator!=(const Vector2 &rhs);
            friend Vector2 operator*(const real scale, const Vector2& rhs);
            
            real x;
            real y;
    };

}

#endif
