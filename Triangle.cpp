#include "Triangle.h"

Triangle::Triangle()
{

}

Triangle::Triangle(const Point& s, const Point& q, const Point& r)
{
    p[0] = s;
    p[1] = q;
    p[2] = r;
}

Triangle::~Triangle()
{

}

Triangle::Triangle(const Triangle& other)
{
    p[0] = other.p[0];
    p[1] = other.p[1];
    p[2] = other.p[2];
}

Triangle& Triangle::operator=(const Triangle& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    p[0] = rhs.p[0];
    p[1] = rhs.p[1];
    p[2] = rhs.p[2];
    return *this;
}

Plane Triangle::getPlane() const
{
    Plane t(p[0], p[1], p[2]);
    return t;
}

Line Triangle::getLine(short i) const
{
    Line l(p[(i + 1) % 3], p[(i + 2) % 3]);
    return l;
}

Line Triangle::getHeight(short i) const
{
    Line l = getLine(i);
    Plane perpendicularPlane(l, p[i]);
    Line result (perpendicularPlane, getPlane());
    return result;
}

Line Triangle::getMedian(short i) const
{
    Point middle((p[(i + 1)%3].getX() + p[(i + 2) % 3].getX())/2,
                 (p[(i + 1)%3].getY() + p[(i + 2) % 3].getY())/2,
                 (p[(i + 1)%3].getZ() + p[(i + 2) % 3].getZ())/2);
    Vector v(p[i], middle);
    Line l(p[i], v);
    return l;
}

Line Triangle::getSymmetral(short i) const
{
    Point middle((p[(i + 1)%3].getX() + p[(i + 2) % 3].getX())/2,
                 (p[(i + 1)%3].getY() + p[(i + 2) % 3].getY())/2,
                 (p[(i + 1)%3].getZ() + p[(i + 2) % 3].getZ())/2);
    Line l = getLine(i);
    Plane perpendicularPlane(l, middle);
    Line result (perpendicularPlane, getPlane());
    return result;
}

Line Triangle::getBisector(short i) const
{
    Vector v(p[i], p[(i + 1) % 3]), w (p[i], p[(i + 2) % 3]);
    v = v + w;
    Line(p[i], v);
}

Point Triangle::getOrthocenter() const
{
    int i = 0;
    Line l(getHeight(i)), h(getHeight((i + 1) % 3));
    Point p(l, h);
    return p;
}

Point Triangle::getMedicenter() const
{
    int i = 0;
    Line l(getMedian(i)), h(getMedian((i + 1) % 3));
    Point p(l, h);
    return p;
}

Point Triangle::getDescribedCircleCenter() const
{
    int i = 0;
    Line l(getSymmetral(i)), h(getSymmetral((i + 1) % 3));
    Point p(l, h);
    return p;
}

Point Triangle::getInscribedCircleCenter() const
{
    int i = 0;
    Line l(getBisector(i)), h(getBisector((i + 1) % 3));
    Point p(l, h);
    return p;
}
