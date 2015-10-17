#include "Plane.h"
#include "Line.h"

Plane::Plane() : A(1), B(0), C(0), D(0)
{

}

Plane::Plane(double a, double b, double c, double d) :
    A (a), B (b), C(c), D(d)
{

}

Plane::~Plane()
{

}

Plane::Plane(const Plane& other) : A(other.A), B(other.B), C(other.C), D(other.D)
{

}

Plane::Plane(const Plane& pl, const Point& pt) : A(pl.A), B(pl.B), C(pl.C),
    D  (-(pl.A * pt.getX() + pl.B * pt.getY() + pl.C * pt.getZ()))
{

}

Plane::Plane(const Line& l, const Point& p) :
    A(l.getVector().getX()), B(l.getVector().getY()), C(l.getVector().getZ())
{
    D = -(A * p.getX() + B * p.getY() + C * p.getZ());
}

Plane::Plane(const Vector& v1, const Vector& v2, const Point& p)
{
    Vector w = v1;
    w = w.crossProduct(v2);
    A = w.getX();
    B = w.getY();
    C = w.getZ();
    D = -(A * p.getX() + B * p.getY() + C * p.getZ());
}

Plane::Plane(const Point& p, const Point& q, const Point& r)
{
    Vector v(r, q), w(p, q);
    w = w.crossProduct(v);
    A = w.getX();
    B = w.getY();
    C = w.getZ();
    D = -(A * p.getX() + B * p.getY() + C * p.getZ());
}

Plane& Plane::operator=(const Plane& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    A = rhs.A;
    B = rhs.B;
    C = rhs.C;
    D = rhs.D;
    return *this;
}

const double Plane::getA() const
{
    return A;
}

const double Plane::getB() const
{
    return B;
}

const double Plane::getC() const
{
    return C;
}

const double Plane::getD() const
{
    return D;
}

void Plane::showEquation() const
{
    cout << A << "x + " << B << "y + " << C << "z + " << D << " = 0";
}

void Plane::showParametricalEquation() const
{
    Vector vector1FromPlane = normal().generatePerpendicular();
    Vector vector2FromPlane = vector1FromPlane.crossProduct(normal());
    Point pointFromPlane;
    if (A == 0)
    {
        if (B == 0) // then C != 0
        {
            Solution s = solveLinearEquation(C, -D);
            pointFromPlane.setX(1.0);
            pointFromPlane.setY(0.0);
            pointFromPlane.setZ(s.a);
        }
        else // B != 0
        {
            Solution s = solveLinearEquation(B, -D);
            pointFromPlane.setX(1.0);
            pointFromPlane.setY(s.a);
            pointFromPlane.setZ(0.0);
        }
    }
    else
    {
        Solution s = solveLinearEquation(A, -D);
        pointFromPlane.setX(s.a);
        pointFromPlane.setY(0.0);
        pointFromPlane.setZ(0.0);
    }
    cout << "Parametrical equation of the plane:" << endl;
    cout << "x = " << pointFromPlane.getX() << " + " << vector1FromPlane.getX()
        << "s + " << vector2FromPlane.getX() << 't' << endl;
    cout << "y = " << pointFromPlane.getY() << " + " << vector1FromPlane.getY()
        << "s + " << vector2FromPlane.getY() << 't' << endl;
    cout << "z = " << pointFromPlane.getZ() << " + " << vector1FromPlane.getZ()
        << "s + " << vector2FromPlane.getZ() << 't' << endl;
}

Vector Plane::normal() const
{
    Vector v(*this);
    return v;
}

State Plane::stateWithPlane(const Plane& other)
{
    if (normal().isCollinearWith(other.normal()))
        return Parallel;
    return Intersection;
}
