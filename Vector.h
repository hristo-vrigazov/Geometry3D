#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"
#include "Plane.h"

class Vector : public Point
{
    public:
        Vector(); // default constructor
        Vector(double, double, double); // vector by three coordinates
        Vector(const Point&, const Point&); // vector between two points
        Vector(const Point&); // vector between 0 and a given point
        Vector(const Plane&); // normal vector
        double dotProduct(const Vector&) const;
        Vector crossProduct(const Vector&) const; // vector multiplication
        friend Vector operator+(const Vector&, const Vector&);
        ~Vector();
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        void normalize();
        double length() const;
        bool isCollinearWith(const Vector&) const;
        friend double angleBetweenVectors(const Vector&, const Vector&);
        Vector generatePerpendicular() const;
};

#endif // VECTOR_H
