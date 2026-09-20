#include "force.h"

Force::Force(const double g)
{
    grav = g;
}

Vecteur Force::f_g(const double mass)
{
    return - mass * grav * DOWN;
}

Vecteur Force::f_d(const double mass, const Vecteur vitesse, const double coef_drag)
{
    return - coef_drag * vitesse.norm() * vitesse;
}
