#pragma once

#include "vecteur.h"
#include "color.h"
#include <cmath>

struct Sphere
{
  Vecteur center;
  RGBColor emission;
  float radius;
};

struct Ray
{
  Vecteur origin;
  Vecteur direction;
};

struct Scene
{
    std::vector<Sphere> spheres;
};

std::optional<float> intersect(const Ray ray, const Sphere sphere)
{
    const Vecteur co = ray.origin - sphere.center;
    const float a = ray.direction.dot(ray.direction);
    const float b = 2 * ray.direction.dot(co);
    const float c = co.dot(co) - sphere.radius * sphere.radius;

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

    return std::nullopt;;
}

std::optional<float> intersect(const Ray ray, const Scene scene)
{
    std::optional<float> scene_it{};

    for (auto &&sphere : scene.spheres)
    {
        std::optional<float> it = intersect(ray,sphere);

        if (it)
        {
            if (it && scene_it){
                scene_it = std::optional<float>(std::min(it.value(), scene_it.value()));
            }
            else if (it)
            {
                scene_it = it;
            }
        }
    }

    return scene_it;
}