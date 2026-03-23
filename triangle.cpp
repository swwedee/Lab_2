#include "triangle.h"
#include <cmath>

// довжина відрізка
double distance(Point A, Point B)
{
    return sqrt((A.x - B.x)*(A.x - B.x) +
                (A.y - B.y)*(A.y - B.y));
}

// площа за формулою Герона
double heronArea(Point A, Point B, Point C)
{
    double a = distance(A,B);
    double b = distance(B,C);
    double c = distance(C,A);

    double p = (a + b + c) / 2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}

// площа через координати (Гаус)
double gaussArea(Point A, Point B, Point C)
{
    return 0.5 * (A.x*(B.y - C.y) +
                  B.x*(C.y - A.y) +
                  C.x*(A.y - B.y));
}

// перевірка виродженості
bool degenerate(Point A, Point B, Point C)
{
    double S = heronArea(A,B,C);

    if (fabs(S) < 1e-9)
        return true;
    else
        return false;
}

// векторний добуток
double cross(Point A, Point B, Point C)
{
    return (B.x - A.x)*(C.y - A.y) -
           (B.y - A.y)*(C.x - A.x);
}

// перевірка точки
int checkPoint(Point A, Point B, Point C, Point P)
{
    double c1 = cross(A,B,P);
    double c2 = cross(B,C,P);
    double c3 = cross(C,A,P);

    if((c1 > 0 && c2 > 0 && c3 > 0) ||
       (c1 < 0 && c2 < 0 && c3 < 0))
        return 1;

    if(c1 == 0 || c2 == 0 || c3 == 0)
        return 0;

    return -1;
}