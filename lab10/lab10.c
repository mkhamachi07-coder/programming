#include "lab10.h"

void input(Point* points, int n) {
    printf("Введите координаты %d точек (x y):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Точка %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
}

const char* ugol(double x, double y) {
    if (x > 0 && y > 0) return "1-й координатный угол";
    if (x < 0 && y > 0) return "2-й координатный угол";
    if (x < 0 && y < 0) return "3-й координатный угол";
    if (x > 0 && y < 0) return "4-й координатный угол";
    if (x == 0 && y == 0) return "начало координат";
    if (x == 0) return "ось Y";
    if (y == 0) return "ось X";
    return "неопределенное положение";
}

void print_point(Point* points, int n) {
    printf("\nРезультаты:\n");
    for (int i = 0; i < n; i++) {
        printf("Точка %d (%.2f, %.2f): %s\n", i + 1, points[i].x, points[i].y, ugol(points[i].x, points[i].y));
    }
}
