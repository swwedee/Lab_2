#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point
{
    double x;
    double y;
};

double distance(Point A, Point B);

double heronArea(Point A, Point B, Point C);

double gaussArea(Point A, Point B, Point C);

bool degenerate(Point A, Point B, Point C);

double cross(Point A, Point B, Point C);

int checkPoint(Point A, Point B, Point C, Point P);

#endif