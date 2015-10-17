#include "Angles.h"

double angleBetweenLinePlane(const Line& l, const Plane& p)
{
    Vector v = p.normal(), u = l.getVector();
    return (PI/2) - angleBetweenVectors(v, u);
}

double angleBetweenVectors(const Vector& v, const Vector& w)
{
    Vector v1 (v), w1(w);
    v1.normalize();
    w1.normalize();
    return acos(v1.dotProduct(w1));
}
