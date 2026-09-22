#include <iostream>
#include <optional>
#include "image.h"
#include "shape.h"
using namespace std;

int main()
{
    const int W = 640;
    const int H = 480;

    Image img(W,H);
    
    const Sphere sphere {Vecteur{W / 2, H / 2, 500}, Color::WHITE, 200}; 

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {

            const Ray ray{Vecteur{x + 0.5f, y + 0.5f, 0}, Direction::DOWN};
            const auto it = intersect(ray, sphere);

            if (it)
            {
                img.set_pixel(x, y, sphere.emission);
            }
            else
            {
                img.set_pixel(x, y, Color::RED);
            }
        }
    }

    img.save("output");

    return 0;
};