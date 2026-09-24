#pragma once

struct RGBColor
{
    float r,g,b;
};

struct Color
{
    static constexpr RGBColor RED = {1, 0, 0};
    static constexpr RGBColor GREEN = {0, 1, 0};
    static constexpr RGBColor BLUE = {0, 0, 1};
    static constexpr RGBColor WHITE = {1, 1, 1};
    static constexpr RGBColor BLACK = {0, 0, 0};
};

RGBColor operator*(const RGBColor c, const float v);