#include <cmath>
#include <cstdio>

int main()
{
    double a = 3.0, b = sqrt(10);
    int x = 3, y = sqrt(10);

    printf("var a is of type double with value %.3lf\n", a);
    printf("var b is of type double with value %.3lf\n", b);

    printf("\nvar x is of type int with value %d\n", x);
    printf("var y is of type int with value %d\n", y);

    printf("\nevaluating a < b: ");
    if (a < b) puts("true");
    else       puts("false");

    printf("evaluating x < y: ");
    if (x < y) puts("true");
    else       puts("false");

    printf("evaluating x < b: ");
    if (x < b) puts("true");
    else       puts("false");

    return 0;
}
