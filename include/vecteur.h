#pragma once
#include <optional>

struct Vecteur
{
    double x,y,z;

    double dot(const Vecteur other) const;
    double norm() const;
    std::optional<Vecteur> normalize() const;
};

static const Vecteur DOWN = {0, 0, 1};
static const Vecteur UP = {0, 0, 1};

Vecteur operator+(const Vecteur a, const Vecteur b);
Vecteur operator*(const Vecteur a, const Vecteur b);
Vecteur operator*(const double s, const Vecteur a);
Vecteur operator/(const Vecteur a, const double s);