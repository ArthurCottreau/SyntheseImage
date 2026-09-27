#pragma once
#include "vecteur.h"
#include <random>

struct RandomNumber
{
    std::random_device rd;
    std::mt19937 gen {rd()};

    float random_range(float min, float max);
    Vecteur random_square();
};