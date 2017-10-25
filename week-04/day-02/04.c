#include <stdio.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

double GetSurface(struct rectangular_cuboid brick);
double GetVolume(struct rectangular_cuboid brick);
// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

int main()
{
    struct rectangular_cuboid brick;
    brick.a = 5;
    brick.b = 3;
    brick.c = 4;

    printf("Surface: %.2f\n", GetSurface(brick));
    printf("volume: %.2f\n", GetVolume(brick));

    return 0;
}

double GetSurface(struct rectangular_cuboid brick)
{
    return brick.a * brick.b * 2 + brick.a * brick.c * 2 + brick.b * brick.c * 2;
}

double GetVolume(struct rectangular_cuboid brick)
{
    return brick.a * brick.b * brick.c;
}
