#include<stdint.h>
#include<math.h>
#include<stdlib.h>
double a, a2, b, b2, c, d, x, y, Rex, Rey, Lex, Ley, D, root1, s, x2, x3, x4, y2, y3, y4;
double xL, xR, yR, xm, ym;

double F(double a, double b, double c, double d, double x)///計算函數值
{
    y=a*x*x*x+b*x*x+c*x+d;
    return y;
}

double F1(double a, double b, double c, double d, double x, double y, double s)///求下個值點
{
    while(fabs(y)>=pow(10,-8))
    {
        s= 3*a*x*x+2*b*x+c;
        x=(y*-1+s*x)/s;///新X值
        y=a*x*x*x+b*x*x+c*x+d;///新Y值
    }
    printf("\n焦點為%f\n",x);
}
double F2(double a, double b, double c, double d, double root1, double x, double y, double s)///求下個值點
{
    while(fabs(y)>=pow(10,-8))
    {
        s= 3*a*x*x+2*b*x+c;
        x=(y*-1+s*x)/s;///新X值
        y=a*x*x*x+b*x*x+c*x+d;///新Y值
    }
    if(x<root1)
    {
        printf("\n焦點為%f %f\n", x, root1);
    }
    else
    {
        printf("\n焦點為%f %f\n", root1, x);
    }
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
    D=sqrt(D);

    if(a<0)
    {
        D=-1*D;
    }

    Rex=(-1*b2+D)/(2*a2);
    x=Rex;
    y=F( a, b, c, d, x);
    Rey=y;

    Lex=(-1*b2-D)/(2*a2);///算出頂點X值
    x=Lex;
    y=F( a, b, c, d, x);
    Ley=y;

    printf("\n\n左頂點(x,y)=(%f,%f)",Lex,Ley);
    printf("\n右頂點(x,y)=(%f,%f)",Rex,Rey);
    printf("\n此方程式類型為 ");

    if(Ley*Rey>pow(10,-8))///(一)有一解
    {
        printf("一個焦點");

        if(a>0 && Rey<0)
        {
            x=Lex-1;

        }
        if(a>0 && Rey>0)
        {
            x=Rex+1;
        }
        if(a<0 && Rey<0)
        {
            x=Lex-1;
        }
        if(a<0 && Rey>0)
        {
            x=Rex+1;
        }
        y=F( a, b, c, d, x);
        printf("\n\n起始計算值(x,y)=(%f,%f)", x, y);///計算起始點
        y=F1( a, b, c, d, x, y, s);
    }

    if(fabs(Ley*Rey)<=pow(10,-8))///(二)有二解
    {
        printf("兩個焦點");
        if(a>0 && Rey<0)
        {
            x=Rex+1;

            root1=Lex;
        }
        if(a>0 && Rey>0)
        {
            x=Lex-1;

            root1=Rex;
        }
        if(a<0 && Ley<0)
        {
            x=Lex-1;

            root1=Lex;
        }
        if(a<0 && Ley>0)
        {
            x=Rex+1;

            root1=Rex;
        }
        y=F( a, b, c, d, x);
        printf("\n起始計算值(x,y)=(%f,%f)", x, y);///計算起始點
        y=F2( a, b, c, d, root1, x, y, s);
    }

    if(Ley * Rey<-pow(10,-8))///(三)有三解
    {
        printf("三個焦點");

        x=(Rex+Lex/2);
        y=F( a, b, c, d, x);
        if(fabs(y*Rex)<pow(10,-8))
        {
            x2=x;
        }
        else
        {
            xL=Lex;
            xR=Rex;
            yR=Rey;
            xm=Lex+Rex;
            x=xm;
            y=F( a, b, c, d, x);
            ym=y;

            while(fabs(ym)>=pow(10,-8))
            {
                xm=(xL+xR)/2;
                x=xm;
                y=F( a, b, c, d, x);
                ym=y;
                if(yR*ym>0)///決定新邊界
                {
                    xR=xm;
                    x=xR;
                    y=F( a, b, c, d, x);
                    yR=y;
                }
                else
                {
                    xL=xm;
                }
            }
            x2=xm;
        }

        x=Lex-1;//左邊解
        y=F( a, b, c, d, x);
        x3=x;
        y3=y;

        while(fabs(y3)>=pow(10,-8))
        {
            s= 3*a*x3*x3+2*b*x3+c;
            x3=(y3*-1+s*x3)/s;///新X值
            y3=a*x3*x3*x3+b*x3*x3+c*x3+d;///新Y值
        }

        x=Rex+1;//右邊解
        y=F( a, b, c, d, x);
        x4=x;
        y4=y;

        while(fabs(y4)>=pow(10,-8))
        {
            s= 3*a*x4*x4+2*b*x4+c;
            x4=(y4*-1+s*x4)/s;///新X值
            y4=a*x4*x4*x4+b*x4*x4+c*x4+d;///新Y值
        }
        printf("\n焦點為%f %f %f\n", x3, x2, x4);
    }
}
