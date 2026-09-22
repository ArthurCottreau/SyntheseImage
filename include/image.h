#pragma once
#include <list>
#include "color.h"
#include <vector>
#include <cstdint>

struct Image
{
    static const int CHANNELS = 3;

    int width, height;
    std::vector<uint8_t> pixels;

    Image(const int w, const int h);
    void set_pixel(const int x, const int y, const RGBColor c);
    void save(const char* file_name);
};