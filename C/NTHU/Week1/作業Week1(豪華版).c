#include<stdio.h>

int main()
{
    double a, b, c, d, e;
    printf("\n�D�ߪ��uy=ax^2+bx+c�����I\n�п�Ja, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a==0)
    {
        printf("\n���~�A��{�������O�G����!\n");
    }
    else
    {
           printf("\n(a, b, c,)���O��(%f,%f,%f)\n", a, b, c);
           printf("��{����:%.2fx^2+(%.2f)x+(%.2f)\n", a, b, c);

           d=-b/(2*a);

           printf("\n���Ix�Ȭ�:%f",d);
           e=a*d*d+b*d+c;
           printf("  y�Ȭ�:%f\n",e);

           printf("\n���׬�(%.2f,%.2f)\n\n", d, e);

    }







    return 0;
}
