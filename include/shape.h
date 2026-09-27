#pragma once
#include "vecteur.h"
#include "color.h"
#include <vector>

struct Sphere
{
  Vecteur center;
  RGBColor emission;
  float radius;
};

struct Scene
{
    std::vector<Sphere> spheres;
};