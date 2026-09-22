#include "force.h"
#include <iostream>
using namespace std;

void skydive()
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
