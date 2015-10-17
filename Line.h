#ifndef LINE_H
#define LINE_H

#include "Vector.h"
#define PI 3.141592653589

// the line will be represented using the parametrical
// equation P + Rs, where P is a point from the line
// and R is a vector from the line
class Line
{
    private:
        Point p;
        Vector v;
    public:
        Line(); // the default line will be Ox
        Line(const Point&, const Vector&); // point and collinear vector
        Line(const Point& , const Point&); // two points
        Line(const Point&, const Plane&);
        // constructing a line perpendicular to the plane
        // through point
        Line(const Plane&, const Plane&); // intersection of two planes
        ~Line();
        Line(const Line& other);
        Line& operator=(const Line& other);

        void setPoint(Point);
        void setVector(Vector);
        const Point& getPoint() const;
        const Vector& getVector() const;

        friend ostream& operator<< (ostream& os, const Line& l);
        void representAsPlaneIntersection(Plane& p, Plane& r);
        State stateWithPlane(const Plane&) const;
        State stateWithLine(const Line&) const;
        friend double angleBetweenLinePlane(const Line&, const Plane&);

};

#endif // LINE_H
