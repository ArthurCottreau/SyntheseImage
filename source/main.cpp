#include <iostream>
#include <optional>
#include "image.h"
#include "shape.h"
#include "random.h"
using namespace std;

int main()
{
    RandomNumber my_rand = RandomNumber();

    const int WIDTH = 640;
    const int HEIGHT = 480;

    const int SAMPLES = 32;

    Image img(WIDTH,HEIGHT);

    const Scene scene {
        {
            Sphere{{WIDTH / 2, HEIGHT / 2, 300}, Color::WHITE, 50},
            Sphere{{WIDTH / 2, HEIGHT / 2, 500}, Color::WHITE, 200},
            Sphere{{WIDTH / 2, HEIGHT / 2, 1000}, Color::WHITE, 400}
        }
    };

    const Vecteur focal = {WIDTH / 2, HEIGHT / 2, -2400};

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {

            RGBColor tmp = {0,0,0};

            for (int s = 0; s < SAMPLES; ++s)
            {
                Vecteur offset = my_rand.random_square();
                const Vecteur pixel = {(x + offset.x) + 0.5f, (y + offset.y) + 0.5f, 0};
                std::optional<Vecteur> direction = (pixel - focal).normalize();
                const Ray ray{pixel, direction.value()};
                const std::optional<float> hit = intersect(ray, scene);

                if (hit)
                {
                    const float d_inv = 1 / hit.value() * 200;
                    RGBColor d_color = {d_inv, d_inv, d_inv};
                    tmp = tmp + d_color;
                }
                else
                {
                    tmp = tmp + Color::RED;
                }
            }

            const RGBColor f_color = tmp / SAMPLES;
            img.set_pixel(x, y, f_color);
        }
    }

    img.save("output");

    return 0;
};