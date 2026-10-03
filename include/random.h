#pragma once
#include "vecteur.h"
#include "utl_random.hpp"

struct RandomNumber
{
    utl::random::generators::RomuMono16 gen {(uint16_t)utl::random::entropy()};
    //utl::random::generators::SplitMix32 gen {utl::random::entropy()};

    float random_range(float min, float max);
    Vecteur random_square();
};

inline float RandomNumber::random_range(float min = 0.0f, float max = 1.0f)
{
    utl::random::UniformRealDistribution<float> distrib(min, max);
    return distrib(gen);
}

inline Vecteur RandomNumber::random_square()
{
    return Vecteur {random_range(-.5,.5), random_range(-.5,.5), 0};
}