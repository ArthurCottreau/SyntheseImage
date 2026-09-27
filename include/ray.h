#pragma once
#include "shape.h"
#include "vecteur.h"
#include <cmath>

struct Ray
{
  Vecteur origin;
  Vecteur direction;
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

RGBColor ray_color(const Ray ray, const Scene scene)
{
    const std::optional<float> hit = intersect(ray, scene);

    if (hit)
    {
        const float d_inv = 1 / hit.value() * 200;
        RGBColor color = {d_inv, d_inv, d_inv};
        return color;
    }
    else
    {
        return Color::RED;
    }
}