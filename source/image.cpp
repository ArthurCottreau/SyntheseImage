#include "image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


Image::Image(const int w, const int h)
{
    width = w;
    height = h;

    pixels.resize(w * h * Image::CHANNELS); // 3 for the number of channels
}

void Image::set_pixel(const int x, const int y, const Vecteur c)
{
    int pos = (y * width + x) * Image::CHANNELS;

    pixels[pos + 0] = c.x;
    pixels[pos + 1] = c.y;
    pixels[pos + 2] = c.z;
}

void Image::save(const char* file_name)
{
    stbi_write_png(
        file_name,
        width, height, Image::CHANNELS,
        pixels.data(),
        width * Image::CHANNELS
    );
}