#include <iostream>
#include <optional>
#include "image.h"
#include "shape.h"
using namespace std;

int main()
{
    const int WIDTH = 640;
    const int HEIGHT = 480;

    Image img(WIDTH,HEIGHT);

    const Scene scene {
        {
            Sphere{{WIDTH / 2, HEIGHT / 2, 300}, Color::WHITE, 50},
            Sphere{{WIDTH / 2, HEIGHT / 2, 500}, Color::WHITE, 200},
            Sphere{{WIDTH / 2, HEIGHT / 2, 1000}, Color::WHITE, 400}
        }
    };

    const Vecteur focal = {WIDTH / 2, HEIGHT / 2, -2400};

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            const Vecteur pixel = {x + 0.5f, y + 0.5f, 0};
            std::optional<Vecteur> direction = (pixel - focal).normalize();
            const Ray ray{pixel, direction.value()};
            const std::optional<float> hit = intersect(ray, scene);

            if (hit)
            {
                const float d_inv = 1 / hit.value() * 200;
                img.set_pixel(x, y, {d_inv, d_inv, d_inv});
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