#include <stdio.h>
#include <stdlib.h>

struct consumer {
    char *name;
    int age;
} *conptr;

struct point {
    int x;
    int y;
} pt2;

struct rect {
    struct point pt1;
    struct point pt2;
} rect1;

struct point pt1 = {2, 3 + (20 % 3)};
struct consumer c1 = {"Kiki", 22};

struct point addpoint (struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
};

struct consumer makeconsumer (char *x, int y){
    struct consumer temp;
    temp.name = x;
    temp.age = y;
    return temp;
};

int main()
{
    pt2.x = 14;
    pt2.y = 57;
    printf("%d\n", pt1.x);
    printf("%d\n", pt1.y);
    printf("%d\n", pt2.x);
    printf("%d\n", pt2.y);

    double dist, sqrt(double);
    dist = sqrt(((double)pt1.x * pt1.x) + ((double)pt1.y * pt1.y));
    printf("%f\n", dist);

    rect1.pt1.x = 1211;
    rect1.pt2.x = 13;
    printf("%d\n", rect1.pt1.x);
    printf("%d\n", rect1.pt2.x);

    printf("%s %d\n", c1.name, c1.age);

    struct consumer c2 = makeconsumer("John", 35);
    printf("%s %d\n", c2.name, c2.age);

    struct point res = addpoint(pt1, pt2);
    printf("%d %d\n", res.x, res.y);

    struct point *ptr = &pt1;
    printf("%d %d\n", ptr->x, ptr->y);

    struct consumer c3 = makeconsumer("Jake", 25);
    struct consumer *ptr2 = &c3;
    printf("%s %d\n", ptr2->name, ptr2->age);

    struct consumer c4 = {"Lisa", 75};
    conptr = &c4;
    printf("%s %d\n", conptr->name, conptr->age);
    return 0;
}
