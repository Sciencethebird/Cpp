#include<stdint.h>
#include<math.h>
#include<stdlib.h>
double a, a2, b, b2, c, d, x, y, xe, ye, D, rootL, rootR, R, s;

double F(double a, double b, double c, double d, double x)///�p���ƭ�
{
    y=a*x*x*x+b*x*x+c*x+d;
    return y;
}

double F1(double a, double b, double c, double d, double x, double y, double s)///�D�U�ӭ��I
{
    s= 3*a*x*x+2*b*x+c;
    printf("\n�ײv��%f",s);//�ײv
    x=(y*-1+s*x)/s;///�sX��
    y=a*x*x*x+b*x*x+c*x+d;///�sY��
    printf("\n�s(x,y)�Ȭ�:(%f,%f)", x, y);
    return  y;


}
double F2(double a, double b, double c, double d, double x, double y, double s)///�D�U�ӭ��I
{

    while(fabs(y)>=pow(10,-8))

    {
        printf("\n%f %f %f",x, a, b);
        s= 3*a*x*x+2*b*x+c;
        printf("\n�ײv��%f",s);//�ײv
        x=(y*-1+s*x)/s;///�sX��
        y=a*x*x*x+b*x*x+c*x+d;///�sY��
        printf("\n�s(x,y)�Ȭ�:(%f,%f)", x, y);
    }
    printf("\n�J�I��%f\n",x);
}
double F3(double a, double b, double c, double d, double x, double y, double s)///�D�U�ӭ��I
{

    while(fabs(y)>=pow(10,-8))

    {
        printf("\n%f %f %f",x, a, b);
        s= 3*a*x*x+2*b*x+c;
        printf("\n�ײv��%f",s);//�ײv
        x=(y*-1+s*x)/s;///�sX��
        y=a*x*x*x+b*x*x+c*x+d;///�sY��
        printf("\n�s(x,y)�Ȭ�:(%f,%f)", x, y);
    }
    printf("\n�J�I��%f\n",x);
}

double main()
{
    printf("�D�T����{��ax^3+bx^2+cx+d����\n");
    printf("�п�Ja b c d:");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    printf("\n��{����%fx^3+%fx^2+%fx+%f", a, b, c, d);

    a2=3*a;///a2���z�Z���
    b2=2*b;
    printf("\n�L���ᬰ:%fx^2+%fx+%f", a2, b2, c);

    D=b2*b2-4*a2*c;

    if(D>=0)///��{���X�z, ���B�J���i�ٲ�!!
    {
        D=sqrt(D);
        printf("\nD=%f",D);
        if(a>0)
        {
            rootR=(-1*b2+D)/(2*a2);
            rootL=(-1*b2-D)/(2*a2);///��X���IX��
        }
        else
        {
            rootR=(-1*b2-D)/(2*a2);
            rootL=(-1*b2+D)/(2*a2);
        }
        printf("\n�쳻�IX��(��,�k)=(%f,%f)\n", rootL, rootR);

        if(rootL*rootR>0)///(�@)���@��
        {

            if(a>0 && rootR<0)
            {
                x=rootL-1;
            }
            if(a>0 && rootR>0)
            {
                x=rootR+1;
            }
            if(a<0 && rootR<0)
            {
                x=rootL-1;
            }
            if(a<0 && rootR>0)
            {
                x=rootR+1;
            }
            y=F( a, b, c, d, x);
            printf("\n�_�l�p���(x,y)=(%f,%f)", x, y);///�p��_�l�I

            while(fabs(y)>=pow(10,-8))
            {

                y=F1( a, b, c, d, x, y, s);


                printf("%f %f", x, y);
            }


        }


        if(rootL * rootR==0)///(�G)���G��
        {

        }

        if(rootL * rootR<0)
        {
            printf("���T�Ӹ�\n");
        }

    }
    else
    {
        printf("�{���٨S�g�nSOR!");
    }
}




