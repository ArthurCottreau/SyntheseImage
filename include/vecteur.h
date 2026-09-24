#pragma once
#include <optional>

struct Vecteur
{
    double x,y,z;

    double dot(const Vecteur other) const;
    double norm() const;
    std::optional<Vecteur> normalize() const;
};

struct Direction
{
    Vecteur vec;

    double dot(const Direction other) const;
    double norm() const;
    std::optional<Direction> normalize() const;
    
    static constexpr Vecteur UP = {0, 0, -1};
    static constexpr Vecteur DOWN = {0, 0, 1};
};

Vecteur operator+(const Vecteur a, const Vecteur b);
Vecteur operator-(const Vecteur a, const Vecteur b);
Vecteur operator*(const Vecteur a, const Vecteur b);
Vecteur operator*(const double s, const Vecteur a);
Vecteur operator/(const Vecteur a, const double s);