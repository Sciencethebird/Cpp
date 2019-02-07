#include<stdint.h>
#include<math.h>
#include<stdlib.h>
double a, a2, b, b2, c, d, x, y, xe, ye, D, rootL, rootR, R, s;

double F(double a, double b, double c, double d, double x)///計算函數值
{
    y=a*x*x*x+b*x*x+c*x+d;
    return y;
}

double F1(double a, double b, double c, double d, double x, double y, double s)///求下個值點
{
    s= 3*a*x*x+2*b*x+c;
    printf("\n斜率為%f",s);//斜率
    x=(y*-1+s*x)/s;///新X值
    y=a*x*x*x+b*x*x+c*x+d;///新Y值
    printf("\n新(x,y)值為:(%f,%f)", x, y);
    return  y;


}
double F2(double a, double b, double c, double d, double x, double y, double s)///求下個值點
{

    while(fabs(y)>=pow(10,-8))

    {
        printf("\n%f %f %f",x, a, b);
        s= 3*a*x*x+2*b*x+c;
        printf("\n斜率為%f",s);//斜率
        x=(y*-1+s*x)/s;///新X值
        y=a*x*x*x+b*x*x+c*x+d;///新Y值
        printf("\n新(x,y)值為:(%f,%f)", x, y);
    }
    printf("\n焦點為%f\n",x);
}
double F3(double a, double b, double c, double d, double x, double y, double s)///求下個值點
{

    while(fabs(y)>=pow(10,-8))

    {
        printf("\n%f %f %f",x, a, b);
        s= 3*a*x*x+2*b*x+c;
        printf("\n斜率為%f",s);//斜率
        x=(y*-1+s*x)/s;///新X值
        y=a*x*x*x+b*x*x+c*x+d;///新Y值
        printf("\n新(x,y)值為:(%f,%f)", x, y);
    }
    printf("\n焦點為%f\n",x);
}

double main()
{
    printf("求三次方程式ax^3+bx^2+cx+d的解\n");
    printf("請輸入a b c d:");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    printf("\n方程式為%fx^3+%fx^2+%fx+%f", a, b, c, d);

    a2=3*a;///a2不干擾原值
    b2=2*b;
    printf("\n微分後為:%fx^2+%fx+%f", a2, b2, c);

    D=b2*b2-4*a2*c;

    if(D>=0)///方程式合理, 此步驟應可省略!!
    {
        D=sqrt(D);
        printf("\nD=%f",D);
        if(a>0)
        {
            rootR=(-1*b2+D)/(2*a2);
            rootL=(-1*b2-D)/(2*a2);///算出頂點X值
        }
        else
        {
            rootR=(-1*b2-D)/(2*a2);
            rootL=(-1*b2+D)/(2*a2);
        }
        printf("\n原頂點X值(左,右)=(%f,%f)\n", rootL, rootR);

        if(rootL*rootR>0)///(一)有一解
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
            printf("\n起始計算值(x,y)=(%f,%f)", x, y);///計算起始點

            while(fabs(y)>=pow(10,-8))
            {

                y=F1( a, b, c, d, x, y, s);


                printf("%f %f", x, y);
            }


        }


        if(rootL * rootR==0)///(二)有二解
        {

        }

        if(rootL * rootR<0)
        {
            printf("有三個解\n");
        }

    }
    else
    {
        printf("程式還沒寫好SOR!");
    }
}




