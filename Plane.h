#ifndef PLANE_H
#define PLANE_H

#include "Point.h"
class Line;
// the plane will be represented using the
// equation Ax + By + Cz + D = 0
class Plane
{
    private:
        double A;
        double B;
        double C;
        double D;
    public:
        Plane(); // default plane is Oyz
        Plane(double, double, double, double);
        // constructor using the equation of the plane
        Plane(const Plane&, const Point&); // parallel to a plane through point
        Plane(const Line&, const Point&); // perpendicular to a line through point
        Plane(const Vector&, const Vector&, const Point&); // parallel to two vectors through point
        Plane(const Point&, const Point&, const Point&); // constructor by two points
        ~Plane();
        Plane(const Plane& other);
        Plane& operator=(const Plane& other);
        const double getA() const;
        const double getB() const;
        const double getC() const;
        const double getD() const;

        void setA(double);
        void setB(double);
        void setC(double);
        void setD(double);

        void showEquation() const;
        void showParametricalEquation() const;

        Vector normal() const;

        State stateWithPlane(const Plane&);
        friend double angleBetweenLinePlane(const Line&, const Plane&);
};

#endif // PLANE_H
