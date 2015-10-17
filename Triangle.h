#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Line.h"
#include "Plane.h"

class Triangle
{
    private:
        Point p[3];
    public:
        Triangle();
        Triangle(const Point&, const Point&, const Point&);
        ~Triangle();
        Triangle(const Triangle& other);
        Triangle& operator=(const Triangle& other);
        Plane getPlane() const;

        Line getLine(short) const;
        Line getHeight(short) const; // to check after the intersection
        Line getMedian(short) const;
        Line getSymmetral(short) const;
        Line getBisector(short) const;
        Point getOrthocenter() const;
        Point getMedicenter() const;
        Point getDescribedCircleCenter() const; // opisana
        Point getInscribedCircleCenter() const;
};

#endif // TRIANGLE_H
