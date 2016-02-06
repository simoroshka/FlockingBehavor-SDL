#ifndef VECTOR2_H
#define VECTOR2_H
#include <math.h>
namespace mysdl {

class Vector2
{
    public:
        double x, y;

        Vector2(double xVal = 0.0, double yVal = 0.0);

        //methods
        double LengthSq() const;
        double Length() const;
        const Vector2 & Skew();
        const Vector2 & Normalize();
        const Vector2 & Truncate(double xMin, double yMin, double xMax, double yMax);
        const Vector2 & ClumpMagnitude(double limit);

        //assingment operators
        Vector2 & operator = (const Vector2 & v) { x = v.x; y = v.y; return *this; }
        Vector2 & operator = (const double & s) { x = s; y = s; return *this; }
        Vector2 & operator - (void) { x = -x; y = -y; return *this; }

        //equality operators
        bool operator == (const Vector2 & v) const { return (x == v.x) && (y == v.y); }
        bool operator != (const Vector2 & v) const { return !(*this == v); }

        //comparison operators
        bool operator < (const Vector2 & v) const { return (x < v.x) || ((x == v.x) && (y < v.y)); }
        bool operator > (const Vector2 & v) const { return !(*this < v) && !(*this == v); }

        //vector2 to this operators
        Vector2 & operator += (const Vector2 & v) { x += v.x; y += v.y; return *this; }
        Vector2 & operator -= (const Vector2 & v) { x -= v.x; y -= v.y; return *this; }
        Vector2 & operator *= (const Vector2 & v) { x *= v.x; y *= v.y; return *this; }
        Vector2 & operator /= (const Vector2 & v) { x /= v.x; y /= v.y; return *this; }

        //vector2 to vector2 operators
        const Vector2 operator + (const Vector2 & v) const { Vector2 r(*this); return r += v; }
        const Vector2 operator - (const Vector2 & v) const { Vector2 r(*this); return r -= v; }
        const Vector2 operator * (const Vector2 & v) const { Vector2 r(*this); return r *= v; }
        const Vector2 operator / (const Vector2 & v) const { Vector2 r(*this); return r /= v; }

        //scaler to this operators
        Vector2 & operator += (double s) { x += s; y += s; return *this; }
        Vector2 & operator -= (double s) { x -= s; y -= s; return *this; }
        Vector2 & operator *= (double s) { x *= s; y *= s; return *this; }
        Vector2 & operator /= (double s) { x /= s; y /= s; return *this; }

        //scaler to vector2 operators
        const Vector2 operator + (double s) const { Vector2 r(*this); return r += s; }
        const Vector2 operator - (double s) const { Vector2 r(*this); return r -= s; }
        const Vector2 operator * (double s) const { Vector2 r(*this); return r *= s; }
        const Vector2 operator / (double s) const { Vector2 r(*this); return r /= s; }



        //static arithmetic
        static const Vector2 Add (const Vector2 & v1, const Vector2 & v2) { return v1 + v2; }
        static const Vector2 Sub (const Vector2 & v1, const Vector2 & v2) { return v1 - v2; }
        static const Vector2 Mul (const Vector2 & v1, const Vector2 & v2) { return v1 * v2; }
        static const Vector2 Div (const Vector2 & v1, const Vector2 & v2) { return v1 / v2; }

        //static methods
        static double DistanceSq (const Vector2 & v1, const Vector2 & v2)
        { return ((v1.x - v2.x) * (v1.x - v2.x)) + ((v1.y - v2.y) * (v1.y - v2.y)); }

        static double Distance (const Vector2 & v1, const Vector2 & v2)
        { return sqrt(DistanceSq(v1, v2)); }

        static double Dot (const Vector2 & v1, const Vector2 & v2)
        { return ((v1.x * v2.x) + (v1.y * v2.y)); }

        static const Vector2 Min (const Vector2 & v1, const Vector2 & v2)
        { return Vector2(v1.x < v2.x ? v1.x : v2.x, v1.y < v2.y ? v1.y : v2.y); }

        static const Vector2 Max (const Vector2 & v1, const Vector2 & v2)
        { return Vector2(v1.x > v2.x ? v1.x : v2.x, v1.y > v2.y ? v1.y : v2.y); }

        static const Vector2 Clamp (const Vector2 & v, const Vector2 & min, const Vector2 & max)
        { return Min(Max(v, min), max); }




        virtual ~Vector2();
    protected:
    private:


};
}
#endif // VECTOR2_H
