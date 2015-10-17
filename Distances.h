#ifndef DISTANCES_H
#define DISTANCES_H

#include "Line.h"
#include "Plane.h"
#include "Point.h"

double distancePointLine(const Point&, const Line&);
double distancePointPlane(const Plane&, const Point&);
double distanceSkewLines(const Line&, const Line&);

#endif // DISTANCES_H
