#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point A, Point B);
double heron(Point A, Point B, Point C);
double gauss(Point A, Point B, Point C);
double crossProduct(Point A, Point B, Point C);

bool isDegenerate(Point A, Point B, Point C);
bool onSegment(Point A, Point B, Point P);

int checkPoint(Point A, Point B, Point C, Point P);

#endif
