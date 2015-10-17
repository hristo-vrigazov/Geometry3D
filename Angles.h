#ifndef ANGLES_H
#define ANGLES_H

#include "Line.h"
#include "Plane.h"

double angleBetweenLinePlane(const Line&, const Plane&);
double angleBetweenVectors(const Vector&, const Vector&);

#endif // ANGLES_H
