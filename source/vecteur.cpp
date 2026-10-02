#include "vecteur.h"

Vecteur operator+(const Vecteur a, const Vecteur b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vecteur operator-(const Vecteur a, const Vecteur b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
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