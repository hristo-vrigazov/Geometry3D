#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>

using namespace std;

struct Solution { // class to represent a solution of a system equation
    bool exists;
    bool hasExactlyOneSolution;
    bool hasManySolutions;
    double a;
    double b;
};

class Point;
class Vector;
class Line;
class Plane;

Solution solveEquations (const Point&, const Point&);
Solution solveLinearEquation(const double A, const double B);
// solves a system of linear equation by given their
// coefficients given as points
double det(double, double,
            double, double); //short for determinant

enum State
{
    Intersection = 0,
    Parallel = 1,
    Skew = 2
};

class Point
{
    private:
        double x;
        double y;
        double z;
    public:
        Point();
        Point(double, double, double); // constructor by three coordinates
        Point(const Line&, const Line&); // intersection point of two lines
        Point(const Line&, const Plane&); // intersection of a line and a plane
        ~Point();
        Point(const Point& other);
        Point& operator=(const Point& other);
        const double getX() const;
        const double getY() const;
        const double getZ() const;
        void setX(double);
        void setY(double);
        void setZ(double);
        Point& translateWith(const Vector&); // returns the point translated with a vector
        friend ostream& operator<< (ostream& os, const Point&);
        bool belongsToLine(const Line&);
        bool belongsToPlane(const Plane&);
        Point projectionToPlane(const Plane&);
};

#endif // POINT_H
