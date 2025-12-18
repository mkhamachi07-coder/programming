#ifndef LAB10_H
#define LAB10_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

void input(Point* points, int n);
void print_point(Point* points, int n);
const char* ugol(double x, double y);

#endif
