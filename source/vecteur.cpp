#include "vecteur.h"
#include <cmath>

double Vecteur::dot(const Vecteur other) const
{
    return x * other.x + y * other.y + z * other.z;
}

double Vecteur::norm() const
{
    return std::sqrt(this->dot(*this));
}

std::optional<Vecteur> Vecteur::normalize() const
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

Vecteur operator+(const Vecteur a, const Vecteur b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vecteur operator*(const Vecteur a, const Vecteur b)
{
    return {a.x * b.x, a.y * b.y, a.z * b.z};
}

Vecteur operator*(const double s, const Vecteur a)
{
    return {a.x * s, a.y * s, a.z * s};
}

Vecteur operator/(const Vecteur a, const double s)
{
    return {a.x / s, a.y / s, a.z / s};
}
