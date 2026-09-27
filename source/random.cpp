#include "random.h"
#include "vecteur.h"

float RandomNumber::random_range(float min = 0.0f, float max = 1.0f)
{
    std::uniform_real_distribution<float> distrib(min, max);
    return distrib(gen);
}

Vecteur RandomNumber::random_square()
{
    return Vecteur {random_range(-.5,.5), random_range(-.5,.5), 0};
}