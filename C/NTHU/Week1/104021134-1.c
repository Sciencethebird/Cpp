#include<stdio.h>

int main()
{
    double a, b, c, d, e;
    scanf("%lf %lf %lf", &a, &b, &c);
    d=-b/(2*a);
    e=a*d*d+b*d+c;
    printf("(%.2f, %.2f)\n", d, e);

    return 0;
}






