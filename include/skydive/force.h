#pragma once
#include "vecteur.h"

struct Force
{
    double grav = 0;

    Force(const double g);
    Vecteur f_g(const double mass);
    Vecteur f_d(const double mass, const Vecteur vitesse, const double coef_drag);
};