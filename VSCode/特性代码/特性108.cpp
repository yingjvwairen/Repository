#include <stdio.h>

#include <math.h>

//__x_a != __x_a is non-sense�������棺

int main()

{

    double a = sqrt(-1.0);

    double b = 1.0;

    printf("%f %d\n%f %d\n", a, a == a, b, b == b);

    return 0;
}