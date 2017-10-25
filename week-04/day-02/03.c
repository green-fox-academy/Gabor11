#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point_t;

point_t make_point(int X, int Y);
double distance(point_t p1, point_t p2);

// TODO:
// Create a function the constructs a point
// It should take it's x and y coordinate as parameter

// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them

int main()
{
    point_t point1 = make_point(5, 0);
    point_t point2 = make_point(3, 0);

    printf("x: %d, y: %d\n", point1.x, point1.y);
    printf("x: %d, y: %d\n", point2.x, point2.y);
    printf("distance: %.2f", distance(point1, point2));

    return 0;
}

point_t make_point(int X, int Y)
{
    point_t p;

    //p.x = X;
    //p.y = Y;
    printf("X: \n");
    scanf("%d", &p.x);

    printf("Y: \n");
    scanf("%d", &p.y);


    return p;
}

double distance(point_t p1, point_t p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}
