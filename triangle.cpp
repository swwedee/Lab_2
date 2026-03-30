#include "triangle.h"

double eps = 1e-9;

double dist(Point A, Point B) {
    return sqrt((B.x - A.x)*(B.x - A.x) +
                (B.y - A.y)*(B.y - A.y));
}

double heron(Point A, Point B, Point C) {
    double a = dist(A, B);
    double b = dist(B, C);
    double c = dist(C, A);

    double p = (a + b + c) / 2;
    double s = p * (p - a) * (p - b) * (p - c);

    if (s < 0) s = 0;

    return sqrt(s);
}

double gauss(Point A, Point B, Point C) {
    double s = A.x*(B.y - C.y) +
               B.x*(C.y - A.y) +
               C.x*(A.y - B.y);

    if (s < 0) s = -s;

    return s / 2;
}

double crossProduct(Point A, Point B, Point C) {
    return (B.x - A.x)*(C.y - A.y) -
           (B.y - A.y)*(C.x - A.x);
}

bool isDegenerate(Point A, Point B, Point C) {
    return gauss(A, B, C) < eps;
}



bool onSegment(Point A, Point B, Point P) {
    if (P.x >= min(A.x, B.x) - eps &&
        P.x <= max(A.x, B.x) + eps &&
        P.y >= min(A.y, B.y) - eps &&
        P.y <= max(A.y, B.y) + eps)
        return true;

    return false;
}

int checkPoint(Point A, Point B, Point C, Point P) {
    double s1 = crossProduct(A, B, P);
    double s2 = crossProduct(B, C, P);
    double s3 = crossProduct(C, A, P);

    
    if (abs(s1) < eps && onSegment(A, B, P)) return 2;
    if (abs(s2) < eps && onSegment(B, C, P)) return 2;
    if (abs(s3) < eps && onSegment(C, A, P)) return 2;

    

    if ((s1 > 0 && s2 > 0 && s3 > 0) ||
        (s1 < 0 && s2 < 0 && s3 < 0))
        return 1;

    return 0;
}
