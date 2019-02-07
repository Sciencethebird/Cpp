#include<stdio.h>

int main()
{
    double a, b, c, d, e;
    printf("\n求拋物線y=ax^2+bx+c之頂點\n請輸入a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a==0)
    {
        printf("\n錯誤，方程式必須是二次式!\n");
    }
    else
    {
           printf("\n(a, b, c,)分別為(%f,%f,%f)\n", a, b, c);
           printf("方程式為:%.2fx^2+(%.2f)x+(%.2f)\n", a, b, c);

           d=-b/(2*a);

           printf("\n頂點x值為:%f",d);
           e=a*d*d+b*d+c;
           printf("  y值為:%f\n",e);

           printf("\n答案為(%.2f,%.2f)\n\n", d, e);

    }







    return 0;
}
