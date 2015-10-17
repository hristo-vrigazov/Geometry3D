#include "Point.h"
#include "Line.h"

double det(double a, double b,
           double c, double d)
{
    return a*d - b*c;
}

Solution solveEquations(const Point& coeffFirst,
                                 const Point& coeffSecond)
{
    Solution s;
    double a1 = coeffFirst.getX(), b1 = coeffFirst.getY(), c1 = coeffFirst.getZ();
    double a2 = coeffSecond.getX(), b2 = coeffSecond.getY(), c2 = coeffSecond.getZ();
    // solving using cramer's rule
    if (det (a1, b1,
             a2, b2) == 0)
    {
        if (det (c1, b1,
                 c2, b2) != 0)
        {
            s.hasExactlyOneSolution = false;
            s.exists = false;
            s.hasManySolutions = false;
            return s;
        }

        if (det (a1, c1,
                 a2, c2) != 0)
        {
            s.hasExactlyOneSolution = false;
            s.exists = false;
            s.hasManySolutions = false;
            return s;
        }
        s.hasExactlyOneSolution = false;
        s.exists = true;
        s.hasManySolutions = true;
        return s;
    }
    s.a = det (c1, b1,
               c2, b2) / det (a1, b1,
                              a2, b2);
    s.b = det (a1, c1,
               a2, c2) / det (a1, b1,
                              a2, b2);
    s.hasExactlyOneSolution = true;
    s.exists = true;
    s.hasManySolutions = false;
    return s;
}

Point::Point() : x(0), y(0), z(0)
{

}

Point::Point(double _x, double _y, double _z)
: x(_x), y(_y), z(_z)
{

}

Point::Point(const Line& l, const Line& p)
{
    double parameterValue1 = 0.0, parameterValue2 = 0.0;
    Point firstEquationCoeff (l.getVector().getX(), p.getVector().getX(),
                              p.getPoint().getX() - l.getPoint().getX());
    Point secondEquationCoeff (l.getVector().getY(), p.getVector().getY(),
                              p.getPoint().getY() - l.getPoint().getY());
    Solution s = solveEquations(firstEquationCoeff, secondEquationCoeff);
    if (s.hasExactlyOneSolution)
    {
        if (s.a * l.getVector().getZ() + s.b * p.getVector().getZ()
            == p.getPoint().getY() - l.getPoint().getY()) // check if satisfies the third equation
        {
            parameterValue1 = s.a;
            parameterValue2 = s.b;
        }
    }
    else if (!s.exists)
    {
        cout << "The point cannot be constructed!" << endl;
    }
    else // has many solutions
    {
        Point firstEquatCoeff (l.getVector().getX(), p.getVector().getX(),
                              p.getPoint().getX() - l.getPoint().getX());
        Point secondEquatCoeff (l.getVector().getZ(), p.getVector().getZ(),
                              p.getPoint().getZ() - l.getPoint().getZ());
        Solution s = solveEquations(firstEquationCoeff, secondEquationCoeff);
        if (s.hasManySolutions)
            cout << "The point is not well-defined!" << endl;

        if (s.hasExactlyOneSolution)
        {
            parameterValue1 = s.a;
            parameterValue2 = s.b;
        }
        else
            cout << "The point does not exist!" << endl;
    }
    if (s.hasExactlyOneSolution)
    {
        x = l.getVector().getX() * parameterValue1 + l.getPoint().getX();
        y = l.getVector().getY() * parameterValue1 + l.getPoint().getY();
        z = l.getVector().getZ() * parameterValue1 + l.getPoint().getZ();
    }
    else
    {
        x = 0;
        y = 0;
        z = 0;
    }

}

Point::Point (const Line& l, const Plane& p)
{
    double parameterValue = 0;
    double A = p.getA() * l.getVector().getX() + p.getB() * l.getVector().getY()
    + p.getC() * l.getVector().getZ();
    double B = - (p.getA() * l.getPoint().getX() + p.getB() * l.getPoint().getY()
    + p.getC() * l.getPoint().getZ() + p.getD());
    if (A == 0)
    {
        if (B == 0)
            cout << "The point is not well-defined!" << endl;        else
            cout << "The point does not exist!" << endl;
        x = 0;
        y = 0;
        z = 0;
    }
    else
    {
        parameterValue = B / A; // we have checked whether A != 0
        x = l.getVector().getX() * parameterValue + l.getPoint().getX();
        y = l.getVector().getY() * parameterValue + l.getPoint().getY();
        z = l.getVector().getZ() * parameterValue + l.getPoint().getZ();
    }

}

Point::~Point()
{

}

Point::Point(const Point& other) : x (other.x), y (other.y), z(other.z)
{

}

Point& Point::operator=(const Point& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

const double Point::getX() const
{
    return x;
}

const double Point::getY() const
{
    return y;
}

const double Point::getZ() const
{
    return z;
}
void Point::setX(double a)
{
    x = a;
}

void Point::setY(double a)
{
    y = a;
}

void Point::setZ(double a)
{
    z = a;
}
ostream& operator<<(ostream& os, const Point& p)
{
    os << '(' << p.x << ',' << ' ' << p.y << ',' << ' ' << p.z << ')';
    return os;
}

Point& Point::translateWith(const Vector& v)
{
    x += v.getX();
    y += v.getY();
    z += v.getZ();
    return *this;
}

Solution solveLinearEquation(const double A, const double B) // Ax = B
{
    Solution s;
    if (A == 0)
    {
        if (B == 0)
        {
            s.exists = true;
            s.hasManySolutions = true;
            s.hasExactlyOneSolution = false;
        }
        else
        {
            s.exists = false;
            s.hasManySolutions = false;
            s.hasExactlyOneSolution = false;
        }
    }
    else
    {
        s.exists = true;
        s.hasManySolutions = false;
        s.hasExactlyOneSolution = true;
        s.a = B / A;
        s.b = s.a;
    }
    return s;
}

bool Point::belongsToLine(const Line& l)
{
    double A = l.getVector().getX(), B = x - l.getPoint().getX();
    Solution s[3];
    s[0] = solveLinearEquation(A, B);
    A = l.getVector().getY(); B = y - l.getPoint().getY();
    s[1] = solveLinearEquation(A, B);
    A = l.getVector().getZ(); B = z - l.getPoint().getZ();
    s[2] = solveLinearEquation(A, B);

    for (int i = 0; i < 3; i++)
    {
        if (!s[i].exists)
            return false;
        if (s[i].hasExactlyOneSolution && s[(i + 1) % 3].hasExactlyOneSolution &&
            s[i].a != s[(i+1)%3].a)
                return false;
    }
    return true;
}

bool Point::belongsToPlane(const Plane& p)
{
    return p.getA() * x + p.getB() * y + p.getC() * z + p.getD() == 0;
}

Point Point::projectionToPlane(const Plane& p)
{
    Line l(*this, p); // line perpendicular to p through the current point
    Point r(l, p); // intersection of this line with the plane
    return r;
}
