#include <bits/stdc++.h>
#include "image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

Image::Image(const int w, const int h)
{
    width = w;
    height = h;

    pixels.resize(w * h * Image::CHANNELS); // 3 for the number of channels
}

void Image::set_pixel(const int x, const int y, const RGBColor c)
{
    int pos = (y * width + x) * Image::CHANNELS;

    pixels[pos + 0] = c.r;
    pixels[pos + 1] = c.g;
    pixels[pos + 2] = c.b;
}

void Image::save(const char* file_name)
{
    // Tonemapping conversion de valeur [0,1] vers des valuers [0,255]
    std::vector<u_int8_t> result;
    result.resize(width * height * Image::CHANNELS);

    transform(pixels.begin(), pixels.end(), result.begin(),
        [](float n) { return std::clamp((int)(n * 255), 0, 255); });

    // Sauvegarde l'image finale
    stbi_write_png(
        file_name,
        width, height, Image::CHANNELS,
        result.data(),
        width * Image::CHANNELS
    );
}