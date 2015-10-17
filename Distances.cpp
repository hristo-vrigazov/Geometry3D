#include "Distances.h"

double distancePointLine(const Point& pt, const Line& l)
{
    Plane pl(l, pt); // perpendicular to l and pt belongs to pl
    Point intersectionPoint(l, pl);
    Vector v(intersectionPoint, pt);
    return v.length();
}

double distancePointPlane(const Plane& pl, const Point& pt)
{
    Vector v(pt), w(pl.normal());
    double dist = (v.dotProduct(w) + pl.getD()) / w.length();
    return dist;
}

double distanceSkewLines(const Line& l, const Line& m)
{
    Plane pl (l.getVector(), m.getVector(), l.getPoint());
    return distancePointPlane(pl, m.getPoint());
}
