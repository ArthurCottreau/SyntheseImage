#include "force.h"
#include "image.h"
#include <iostream>
using namespace std;

void vecteur_class()
{
    Force world_force(9.81);

    Vecteur position {0, 0, 4000};
    Vecteur vitesse {0, 0, 0};
    double mass = 90;
    double C_d = 0.34;

    double time = 0;
    const double t_max = 60;
    const double dt = 0.1;

    const Vecteur wind{-30, 0, 0};

    while (time <= t_max)
    {
        const Vecteur forces = world_force.f_g(mass) + world_force.f_d(mass,vitesse,C_d);
        const Vecteur acceleration = forces / mass;

        vitesse = vitesse + dt * acceleration;
        position = position + dt * vitesse + dt * wind;

        time += dt;
        cout << "position a l'instant " << time << " :  " << position.x << ", " << position.y << ", " << vitesse.z << endl;
    }
}

int main()
{
    Image img(1920,1080);

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {

            if (y < img.height/2)
            {
                img.set_pixel(x, y, {0,255,0});
            }
            else
            {
                img.set_pixel(x, y, {255,0,0});
            }
        }
    }

    img.save("output");

    return 0;
};