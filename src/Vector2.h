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
            Vector2(real x, real y);
            Vector2(const Vector2 &rhs);

            // functions
            void Normalize();
            void SetXY(real x, real y);
            void SetX(real x);
            void SetY(real y);
            void SetUnitLengthAndYawRadians(real angleInRadians);
            void SetUnitLengthAndYawDegrees(real angleInDegrees);
            void SetLengthAndYawRadians(real radius, real angleInRadians);
            void SetLengthAndYawDegrees(real radius, real angleInDegrees);
            void SetLength(real radius);
            void ScaleUniform(real length);
            void ScaleX(real length);
            void ScaleY(real length);
            Vector2& RotateDegrees(real angleInDegrees);
            Vector2& RotateRadians(real angleInRadians);
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
            Vector2& operator*=(real uniformScale);
            Vector2& operator/=(real inverseScale);
            Vector2 operator+(const Vector2 &rhs);
            Vector2 operator+( const float displacement );
            Vector2 operator-(const Vector2 &rhs);
            Vector2 operator-( const float displacement );
            Vector2 operator*(real uniformScale);
            Vector2 operator/(real inverseScale);
            Vector2 operator-();
            bool operator==(const Vector2 &rhs);
            bool operator!=(const Vector2 &rhs);
            friend Vector2 operator*(real scale, const Vector2& rhs);
            
            real x;
            real y;
    };

}

#endif
