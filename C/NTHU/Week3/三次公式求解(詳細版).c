#include<stdint.h>
#include<math.h>
#include<stdlib.h>
double a, a2, b, b2, c, d, x, y, Rex, Rey, Lex, Ley, D, root1, s, x2, x3, x4, y2, y3, y4;
double xL, xR, yR, xm, ym;

double F(double a, double b, double c, double d, double x)///�p���ƭ�
{
    y=a*x*x*x+b*x*x+c*x+d;
    return y;
}

double F1(double a, double b, double c, double d, double x, double y, double s)///�D�U�ӭ��I
{
    while(fabs(y)>=pow(10,-8))
    {
        s= 3*a*x*x+2*b*x+c;
        x=(y*-1+s*x)/s;///�sX��
        y=a*x*x*x+b*x*x+c*x+d;///�sY��
    }
    printf("\n�J�I��%f\n",x);
}
double F2(double a, double b, double c, double d, double root1, double x, double y, double s)///�D�U�ӭ��I
{
    while(fabs(y)>=pow(10,-8))
    {
        s= 3*a*x*x+2*b*x+c;
        x=(y*-1+s*x)/s;///�sX��
        y=a*x*x*x+b*x*x+c*x+d;///�sY��
    }
    if(x<root1)
    {
        printf("\n�J�I��%f %f\n", x, root1);
    }
    else
    {
        printf("\n�J�I��%f %f\n", root1, x);
    }
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
    D=sqrt(D);

    if(a<0)
    {
        D=-1*D;
    }

    Rex=(-1*b2+D)/(2*a2);
    x=Rex;
    y=F( a, b, c, d, x);
    Rey=y;

    Lex=(-1*b2-D)/(2*a2);///��X���IX��
    x=Lex;
    y=F( a, b, c, d, x);
    Ley=y;

    printf("\n\n�����I(x,y)=(%f,%f)",Lex,Ley);
    printf("\n�k���I(x,y)=(%f,%f)",Rex,Rey);
    printf("\n����{�������� ");

    if(Ley*Rey>pow(10,-8))///(�@)���@��
    {
        printf("�@�ӵJ�I");

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
        printf("\n\n�_�l�p���(x,y)=(%f,%f)", x, y);///�p��_�l�I
        y=F1( a, b, c, d, x, y, s);
    }

    if(fabs(Ley*Rey)<=pow(10,-8))///(�G)���G��
    {
        printf("��ӵJ�I");
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
        printf("\n�_�l�p���(x,y)=(%f,%f)", x, y);///�p��_�l�I
        y=F2( a, b, c, d, root1, x, y, s);
    }

    if(Ley * Rey<-pow(10,-8))///(�T)���T��
    {
        printf("�T�ӵJ�I");

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
                if(yR*ym>0)///�M�w�s���
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

        x=Lex-1;//�����
        y=F( a, b, c, d, x);
        x3=x;
        y3=y;

        while(fabs(y3)>=pow(10,-8))
        {
            s= 3*a*x3*x3+2*b*x3+c;
            x3=(y3*-1+s*x3)/s;///�sX��
            y3=a*x3*x3*x3+b*x3*x3+c*x3+d;///�sY��
        }

        x=Rex+1;//�k���
        y=F( a, b, c, d, x);
        x4=x;
        y4=y;

        while(fabs(y4)>=pow(10,-8))
        {
            s= 3*a*x4*x4+2*b*x4+c;
            x4=(y4*-1+s*x4)/s;///�sX��
            y4=a*x4*x4*x4+b*x4*x4+c*x4+d;///�sY��
        }
        printf("\n�J�I��%f %f %f\n", x3, x2, x4);
    }
}
