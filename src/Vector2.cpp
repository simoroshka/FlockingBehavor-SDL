#include "Vector2.h"

namespace mysdl
{
const double EPSILON = 0.000000001;
//vector2 ctor
Vector2::Vector2(double xVal, double yVal) : x(xVal), y(yVal) { }

//vector2 methods
double Vector2::LengthSq() const { return x * x + y * y; }

double Vector2::Length() const { return sqrt(LengthSq()); }

const Vector2 & Vector2::Skew() { x -= y; y += x; x -= y; return *this; }

const Vector2 & Vector2::Normalize()
{
    return ClumpMagnitude(1);
}

const Vector2 & Vector2::ClumpMagnitude(double limit)
{
    double len = Length();
    if(len < EPSILON)
    {
        x = y = 0;
        return *this;
    }
    else
    {
        double invLen = limit / len;
        x *= invLen;
        y *= invLen;
        return *this;
    }
}

const Vector2 & Vector2::Truncate(double xMin, double yMin, double xMax, double yMax)
{
    if (x < xMin) x = xMin;
    else if (x > xMax) x = xMax - 1;
    if (y < yMin) y = yMin;
    else if (y > yMax) y = yMax - 1;
    return *this;
}

Vector2::~Vector2()
{
}
}
