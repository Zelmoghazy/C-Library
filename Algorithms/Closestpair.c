
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
} Point;

float dist(Point p5, Point p2)
{
    return sqrt((p5.x - p2.x) * (p5.x - p2.x) +
                (p5.y - p2.y) * (p5.y - p2.y));
}

float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f \n", bruteForce(P, n));
    system("pause");
    return 0;
}
