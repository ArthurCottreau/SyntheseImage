#include "color.h"

RGBColor operator*(const RGBColor c, const float v)
{
    return {c.r * v, c.g * v, c.b * v};
}