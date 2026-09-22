#pragma once

#include "vecteur.h"
#include "color.h"
#include <cmath>

struct Sphere {
  Vecteur center;
  RGBColor emission;
  float radius;
};

struct Ray {
  Vecteur origin;
  Vecteur direction;
};

std::optional<float> intersect(const Ray ray, const Sphere sphere)
{
    const float a = ray.direction.norm_squared();
    const Vecteur co = ray.origin - sphere.center;
    const float b = 2 * ray.direction.dot(co);
    const float c = co.norm_squared() - sphere.radius * sphere.radius;

    const float delta = b * b - 4 * a * c;

    if (delta >= 0)
    {
        const float sqrtdelta = std::sqrt(delta);
        float ta = (-b - sqrtdelta) / (2 * a);
        float tb = (-b + sqrtdelta) / (2 * a);

        if (ta > 0)
        {
            return ta;
        }
        if (tb > 0)
        {
            return tb;
        }
    }

    return {};
}