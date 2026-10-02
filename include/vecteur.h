#pragma once
#include <optional>
#include <cmath>

struct Vecteur
{
    double x,y,z;

    double dot(const Vecteur &other) const;
    double norm() const;
    std::optional<Vecteur> normalize() const;
};

Vecteur operator+(const Vecteur a, const Vecteur b);
Vecteur operator-(const Vecteur a, const Vecteur b);
Vecteur operator*(const Vecteur a, const Vecteur b);
Vecteur operator*(const double s, const Vecteur a);
Vecteur operator/(const Vecteur a, const double s);

inline double Vecteur::dot(const Vecteur &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

inline double Vecteur::norm() const
{
    return std::sqrt(this->dot(*this));
}

inline std::optional<Vecteur> Vecteur::normalize() const
{
    const double n = norm();

    if (n == 0)
    {
        return std::nullopt;
    }
    else
    {
        return *this / norm();
    }
}