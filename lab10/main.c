#include "lab10.h"

int main() {
    int n;
    printf("Введите количество точек: ");
    scanf("%d", &n);
  
    Point* points = (Point*)malloc(n * sizeof(Point));
    if (points == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    input(points, n);
    print_point(points, n);
    
    free(points);
    
    return 0;
}
