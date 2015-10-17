#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Plane.h"
#include "Triangle.h"
#include "Angles.h"
#include "Distances.h"

using namespace std;

void showConstructorPoint()
{
    cout << "-----------------------" << endl;
    cout << "Points constructors:" << endl;
    Point p(3, 1, 2), q(1, 0, 2), o, tj(6, 2, 4);
    Vector v(1, 1, 1), w(p, q);
    Plane planeSample(1, -1, 1, -1), plane2(v, w, q);
    Line l(p, q), perpThrough(p, planeSample), lineSample(tj, o);
    cout << "Constructor with parameters:" << endl;
    cout << q << endl;
    system("pause");
    cout << "Construtor by intersection of lines: " << endl;
    cout << l << endl << lineSample << endl;
    Point intersectionPoint(l, lineSample);
    cout << "Intersection point:" << intersectionPoint << endl;
    system("pause");
    cout << "Constructor by intersection of line and plane: " << endl;
    Point newPoint(perpThrough, planeSample);
    cout << perpThrough << endl;
    planeSample.showEquation(); cout << endl;
    cout << "Intersection: " << newPoint << endl;
    system("pause");
}

void showConstructorVector()
{
    system("cls");
    cout << "Constructor with parameters:" << endl;
    Vector v(2, -5, 3);
    cout << v << endl;
    Point p(2, 3, 4), q(-2, 0.5, 4);
    cout << "Constructor through points: " << endl;
    cout << p << ' ' << q << endl;
    Vector w(p, q);
    cout << w << endl;
    Plane plane(3, -5, 23, -56);
    cout << "Constructor as normal vector of the plane: " << endl;
    plane.showEquation(); cout << endl;
    Vector t(plane);
    cout << t << endl;
    system("pause");
}

void showConstructorPlane()
{
    system("cls");
    Plane planeCoeff(1, -2, 3, 4);
    cout << "Constructor by coeffiecients:" << endl;
    planeCoeff.showEquation(); cout << endl;
    cout << endl;
    cout << "Constructor by a parallel plane and a point:" << endl;
    cout << "Plane: "; planeCoeff.showEquation(); cout << endl;
    Point p(1, 1, 1);
    cout << "Point: "; cout << p << endl;
    Plane planePoint(planeCoeff, p);
    planePoint.showEquation(); cout << endl;
    Point o; Vector v(1, 0, 0), w(0, 1, 0);
    Plane twoVectorsPoint(v, w, o);
    cout << endl;
    cout << "Constructor by two vectors and a point: "<< endl;
    cout << "Vectors: " << v << ' ' << w << endl;
    cout << "Point: " << o << endl;
    twoVectorsPoint.showEquation(); cout << endl;
    Point s(-3, 4, 5);
    Plane threePoints(s, o, p);
    cout << endl;
    cout << "Constructor by three points: " << endl;
    cout << "Points: " << s << ' ' << o << ' ' << p << endl;
    threePoints.showEquation(); cout << endl;
    system("pause");
}

void showOperations()
{
    system("cls");
    Vector v(1, 0, -1), w(0, -1, 1); Point p(3, 4, 5);
    cout << "Equation of a plane: " << endl;
    Plane param(v, w, p);
    param.showEquation(); cout << endl;
    cout << endl;
    param.showParametricalEquation();
    cout << endl;
    system("pause");
    Line l(p, v);
    cout << "Parametrical equation of a line:" << endl;
    cout << l << endl;
    Plane p1, p2;
    l.representAsPlaneIntersection(p1, p2);
    cout << "Line represented as intersection of planes:" << endl;
    p1.showEquation(); cout << endl;
    p2.showEquation(); cout << endl;
    system("pause");
    cout << endl;
    cout << "Point translated with vector" << endl;
    cout << "Point: " << p << " Vector: " << v << endl;
    cout << p.translateWith(v) << endl;
    system("pause");
    cout << endl;
    cout << "Sum of two vectors" << endl;
    cout << "Vector1: " << v << endl; cout << "Vector2: " << w << endl;
    cout << "Sum: " << v + w << endl;
    cout << "Dot product:" << v.dotProduct(w) << endl;
    cout << "Vector product: " << v.crossProduct(w) << endl;
    system("pause");
    cout << endl;
    cout << "Point belongs to line?" << endl;
    cout << "Point: " << p << endl;
    cout << "Line: " << l;
    cout << p.belongsToLine(l) << endl;
    system("pause");
    cout << endl;
    cout << "Point belongs to plane?" << endl;
    cout << "Point: " << p << endl;
    cout << "Plane: "; p1.showEquation(); cout << endl;
    cout << p.belongsToPlane(p1) << endl;
    system("pause");
    cout << endl;
    cout << "Plane Line state: "<< endl;
    cout << "Line: " << l << endl;
    cout << "Plane: "; p1.showEquation(); cout << endl;
    cout << l.stateWithPlane(p1) << endl;    system("pause");
    cout << endl;
    cout << "Line Line state: "<< endl;
    Point o; Vector q(0, 0, -1);
    l.setVector(q);
    Line ql(w, o);
    cout << "Line: " << l << endl;
    cout << "Line: " << ql << endl;
    cout << l.stateWithLine(ql) << endl;
    system("pause");
    cout << endl;
    cout << "State planes:" << endl;
    cout << "Plane: "; p1.showEquation(); cout << endl;
    cout << "Plane: "; p2.showEquation(); cout << endl;
    cout << p1.stateWithPlane(p2) << endl;
    system("pause");
}

void showTriangle()
{
    system("cls");
    Point p(3, -8, 10), q(3, 4, 1), r(4, 1, -3);
    Triangle t(p, q, r);
    cout << "Plane of the triangle, determined by points:" << endl;
    cout << "Point1: " << p << endl;
    cout << "Point2: " << q << endl;
    cout << "Point3: " << r << endl;
    cout << "Plane: "; t.getPlane().showEquation(); cout << endl;
    system("pause");
    cout << "Line between Point2 and Point3" << endl;
    Line l = t.getLine(0);
    cout << l << endl;
    cout << "Height through Point1: " << endl;
    l = t.getHeight(0);
    cout  << l << endl;
    cout << "Median through Point1: " << endl;
    l = t.getMedian(0);
    cout << l << endl;
    system("pause");
    cout << "Bisector through Point1: " << endl;
    l = t.getBisector(0);
    cout << l << endl;
    cout << "Symetral through Point1: " << endl;
    l = t.getSymmetral(0);
    cout << l << endl;
    system("pause");
    Point tempPoint;
    tempPoint = t.getOrthocenter();
    cout << "Orthocenter: "<< tempPoint << endl;
    cout << endl;
    tempPoint = t.getMedicenter();
    cout << "Medicenter: "<< tempPoint << endl;
    cout << endl;
    tempPoint = t.getDescribedCircleCenter();
    cout << "Described circle center: "<< tempPoint << endl;
    cout << endl;
    tempPoint = t.getInscribedCircleCenter();
    cout << "Inscribed circle center: "<< tempPoint << endl;
    cout << endl;
    system("pause");
}
void showAdditionalOperations()
{
    system("cls");
    Point r(3, 5, 23902);
    Plane pl (0, 0, 1, 0);
    cout << "Projection of a point:";
    cout << "Point: " << r << endl;
    cout << "Plane: "; pl.showEquation(); cout << endl;
    r = r.projectionToPlane(pl);
    cout << "Projection: "<< r << endl;
    system("pause");
    cout << endl;
    Point t(3, 4, 0), q(5, 6, 4);
    Line l(t, q);
    cout << "Angle between:" << endl;
    cout << "Line:" << l << endl;
    cout << "Plane: "; pl.showEquation(); cout << endl;
    double res = angleBetweenLinePlane(l, pl);
    cout << "Angle: " << res << endl;
    system("pause");
    cout << endl;
    cout << "Distance between: " << endl;
    cout << "Line: " << q << endl;
    cout << "Point: " << t << endl;
    cout << "Dist:" << distancePointLine(q, l) << endl;
    system("pause");
    cout << endl;
    cout << "Distance between: " << endl;
    cout << "Point: " << q << endl;
    cout << "Plane: "; pl.showEquation(); cout << endl;
    cout << "Dist: " << distancePointPlane(pl, q) << endl;
    system("pause");
    cout << endl;
    Point o; Vector qt(3, 0, -1), w(0, -1, 1); Point v(1, 0, -1);
    Line line(qt, v);
    Line ql(w, o);
    cout << "Line: " << line << endl;
    cout << "Line: " << ql << endl;
    cout << "Dist: " << distanceSkewLines(line, ql) << endl;
}

int main()
{
   // showConstructorPoint();
   // showConstructorVector();
   // showConstructorPlane();
   // showOperations();
    showTriangle();
   // showAdditionalOperations();
    return 0;
}
