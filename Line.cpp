#include "Line.h"

Line::Line() : p(0, 0, 0), v(1, 0, 0)
{

}

Line::Line(const Point& _p, const Vector& _v) : p(_p), v(_v)
{

}
Line::Line(const Point& _p, const Point& _q)
{
    Vector t(_p, _q);
    v = t;
    p = _p;
}

Line::Line(const Point& pt, const Plane& pl) :
    p (pt)
{
    Vector normal(pl);
    v = normal;
}
Line::Line(const Plane& pl1, const Plane& pl2)
{
    Vector t = pl1.normal(), w = pl2.normal();
    Vector collinearVector = t.crossProduct(w);
    v = collinearVector;
    bool wasFound = false;
    // for z == 0
    Point firstEqCoeff(pl1.getA(), pl1.getB(), -pl1.getD());
    Point secondEqCoeff(pl2.getA(), pl2.getB(), -pl2.getD());
    Solution s = solveEquations(firstEqCoeff, secondEqCoeff);
    if (s.hasExactlyOneSolution)
    {
        Point commonPoint(s.a, s.b, 0.0);
        p = commonPoint;
        wasFound = true;
    }
    // for y == 0
    if (!wasFound)
    {
        firstEqCoeff.setY(0.0);
        firstEqCoeff.setZ(pl1.getC());
        secondEqCoeff.setY(0.0);
        secondEqCoeff.setZ(pl2.getC());
        s = solveEquations(firstEqCoeff, secondEqCoeff);
        if (s.hasExactlyOneSolution)
        {
            Point commonPoint(s.a, 0.0, s.b);
            p = commonPoint;
            wasFound = true;
        }
    }
    // for x == 0
    if (!wasFound)
    {
        firstEqCoeff.setX(0.0);
        firstEqCoeff.setY(pl1.getB());
        secondEqCoeff.setX(0.0);
        secondEqCoeff.setY(pl2.getB());
        s = solveEquations(firstEqCoeff, secondEqCoeff);
        if (s.hasExactlyOneSolution)
        {
            Point commonPoint(0.0, s.a, s.b);
            p = commonPoint;
            wasFound = true;
        }
    }

}

Line::~Line()
{

}

Line::Line(const Line& other) : p(other.p), v(other.v)
{

}

Line& Line::operator=(const Line& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    p = rhs.p;
    v = rhs.v;
    return *this;
}

void Line::setPoint(Point _p)
{
    p = _p;
}
void Line::setVector(Vector _v)
{
    v = _v;
}

const Point& Line::getPoint() const
{
    return p;
}

const Vector& Line::getVector() const
{
    return v;
}

void Line::representAsPlaneIntersection(Plane& p, Plane& r)
{
    Point pt = getPoint();
    Vector w = getVector();
    Vector newVector1, newVector2;
    newVector1 = w.generatePerpendicular();
    newVector2 = newVector1.crossProduct(w);
    Plane newPlane1(w, newVector1, pt), newPlane2(w, newVector2, pt);
    p = newPlane1;
    r = newPlane2;
}

State Line::stateWithPlane(const Plane& p) const
{
    if (v.dotProduct(p.normal()) == 0)
    // if a vector is perpendicular to the line and the plane at the same time
        return Parallel;
    return Intersection;
}

State Line::stateWithLine(const Line& l) const
{
    if (getVector().isCollinearWith(l.getVector()))
        return Parallel;
    Point firstEquationCoeff (getVector().getX(), l.getVector().getX(),
                              l.getPoint().getX() - getPoint().getX());
    Point secondEquationCoeff (getVector().getY(), l.getVector().getY(),
                              l.getPoint().getY() - getPoint().getY());
    Solution s = solveEquations(firstEquationCoeff, secondEquationCoeff);
    if (s.hasExactlyOneSolution)
        return Intersection;
    return Skew;
}

ostream& operator<< (ostream& os, const Line& l)
{
    os << "Line equation:" << endl;
    os << "x = " << l.p.getX() << " + " << l.v.getX() << 's' << endl;
    os << "y = " << l.p.getY() << " + " << l.v.getY() << 's' << endl;
    os << "z = " << l.p.getZ() << " + " << l.v.getZ() << 's' << endl;
    return os;
}
