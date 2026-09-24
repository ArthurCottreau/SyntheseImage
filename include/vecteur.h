#pragma once
#include <optional>

struct Vecteur
{
    double x,y,z;

    double dot(const Vecteur other) const;
    double norm() const;
    std::optional<Vecteur> normalize() const;
};

Vecteur operator+(const Vecteur a, const Vecteur b);
Vecteur operator-(const Vecteur a, const Vecteur b);
Vecteur operator*(const Vecteur a, const Vecteur b);
Vecteur operator*(const double s, const Vecteur a);
Vecteur operator/(const Vecteur a, const double s);