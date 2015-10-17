#include "Vector.h"

Vector::Vector() : Point ()
{

}
Vector::Vector(double x, double y, double z) : Point(x, y, z)
{

}

Vector::Vector(const Point& p, const Point& q) :
    Point (q.getX() - p.getX(), q.getY() - p.getY(), q.getZ() - p.getZ())
{

}

Vector::Vector(const Point& p) :
    Point (p)
{

}

double Vector::dotProduct(const Vector& v) const
{
    return getX() * v.getX() + getY() * v.getY() + getZ() * v.getZ();
}

Vector Vector::crossProduct(const Vector& v) const
{
    double
    a = det (getY(), getZ(),
              v.getY(), v.getZ()),
    b = det (getZ(), getX(),
              v.getZ(), v.getX()),
    c = det (getX(), getY(),
              v.getX(), v.getY());
    Vector result(a, b, c);
    return result;
}

Vector::Vector(const Plane& p) :
    Point (p.getA(), p.getB(), p.getC())
{

}

Vector::~Vector()
{

}

Vector::Vector(const Vector& other) : Point (other)
{

}

Vector& Vector::operator=(const Vector& rhs)
{
    if (this == &rhs) return *this;
    setX(rhs.getX());
    setY(rhs.getY());
    setZ(rhs.getZ());
    return *this;
}

Vector operator+ (const Vector& u, const Vector& v)
{
    Vector res (u.getX() + v.getX(), u.getY() + v.getY(), u.getZ() + v.getZ());
    return res;
}

double Vector::length() const
{
    return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
}

void Vector::normalize()
{
    double s = length();
    setX(getX()/s);
    setY(getY()/s);
    setZ(getZ()/s);
}

bool Vector::isCollinearWith(const Vector& v) const
{
    Vector thisCopy(*this), otherCopy(v);
    thisCopy.normalize();
    otherCopy.normalize();
    float toCheck = thisCopy.dotProduct(otherCopy);
    return toCheck == 1;
}
Vector Vector::generatePerpendicular() const
{
    Vector result;
    if (getX() == 0 && getY() == 0)
    {
        result.setX(1.0);
        result.setY(0.0);
        result.setZ(0.0);
    }
    else
    {
        result.setX(-getY());
        result.setY(getX());
        result.setZ(0.0);
    }
    return result;
}
