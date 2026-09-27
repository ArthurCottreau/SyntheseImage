#include "color.h"

RGBColor operator*(const RGBColor c, const float v)
{
    return {c.r * v, c.g * v, c.b * v};
}

RGBColor operator/(const RGBColor c, const float f)
{
    return {c.r / f, c.g / f, c.b / f};
}

RGBColor operator+(const RGBColor a, const RGBColor b)
{
    return {a.r + b.r, a.g + b.g, a.b + b.b};
}