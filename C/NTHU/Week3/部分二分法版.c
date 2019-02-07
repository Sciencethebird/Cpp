#include<stdint.h>
#include<math.h>
#include<stdlib.h>
double a, a2, b, b2, c, d, x, y, Rex, Rey, Lex, Ley, D, root1, s, x2, x3, x4, y2, y3, y4;
double xL, xR, yR, xm, ym;

double F(double a, double b, double c, double d, double x)
{
    y=a*x*x*x+b*x*x+c*x+d;
    return y;
}
double F1(double a, double b, double c, double d, double x, double y, double s)
{
    while(fabs(y)>pow(10,-6))
    {
        s=3*a*x*x+2*b*x+c;
        x=(y*-1+s*x)/s;
        y=a*x*x*x+b*x*x+c*x+d;
    }
    printf("%.4f\n",x);
}
double F2(double a, double b, double c, double d, double root1, double x, double y, double s)
{
    while(fabs(y)>pow(10,-6))
    {
        s= 3*a*x*x+2*b*x+c;
        x=(y*-1+s*x)/s;
        y=a*x*x*x+b*x*x+c*x+d;
    }
    if(x<root1)
    {
        printf("%.4f %.4f\n", x, root1);
    }
    else
    {
        printf("%.4f %.4f\n", root1, x);
    }
}

int main()
{
    int i, n;
    scanf("%d",&n);

    double A[n],B[n],C[n],Dd[n];

    for(i=1; i<=n; i++)
    {
        scanf("\n%lf %lf %lf %lf", &A[i], &B[i], &C[i], &Dd[i]);
    }
    for(i=1; i<=n; i++)
    {
        a=A[i];
        b=B[i];
        c=C[i];
        d=Dd[i];


        a2=3*a;
        b2=2*b;

        D=b2*b2-4*a2*c;
        D=sqrt(D);

        if(a<0)
        {
            D = -1*D;
        }

        Rex=(-1*b2+D)/(2*a2);
        x=Rex;
        y=F( a, b, c, d, x);
        Rey=y;

        Lex=(-1*b2-D)/(2*a2);
        x=Lex;
        y=F( a, b, c, d, x);
        Ley=y;


        if(Ley*Rey>0 && fabs(Ley)>pow(10,-6) && fabs(Rey)>pow(10,-6) )
        {
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
            y=F1( a, b, c, d, x, y, s);
        }


        if(fabs(Ley)<= pow(10,-6) || fabs(Rey)<= pow(10,-6))
        {
            if(a>0 && Rey<-pow(10,-6))
            {
                x=Rex+1;
                root1=Lex;
            }
            if(a>0 && Ley>pow(10,-6))
            {
                x=Lex-1;
                root1=Rex;
            }
            if(a<0 && Ley<-pow(10,-6))
            {
                x=Lex-1;
                root1=Rex;
            }
            if(a<0 && Rey>pow(10,-6))
            {
                x=Rex+1;
                root1=Lex;
            }
            y=F( a, b, c, d, x);
            y=F2( a, b, c, d, root1, x, y, s);
        }

        if(Ley * Rey<0 && fabs(Ley)>pow(10,-6) && fabs(Rey)>pow(10,-6) )
        {
            x=(Rex+Lex)/2;
            y=F( a, b, c, d, x);
            if(y<=pow(10,-6))
            {
                x2=x;
            }
            else
            {
                xL=Lex;
                xR=Rex;
                yR=Rey;
                xm=(Lex+Rex)/2;
                x=xm;
                y=F( a, b, c, d, x);
                ym=y;

                while(fabs(ym)>pow(10,-6))
                {
                    xm=(xL+xR)/2;
                    x=xm;
                    y=F( a, b, c, d, x);
                    ym=y;
                    if(yR*ym>0)
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

            x=Lex-1;
            y=F( a, b, c, d, x);
            x3=x;
            y3=y;

            while(fabs(y3)>pow(10,-6))
            {
                s= 3*a*x3*x3+2*b*x3+c;
                x3=(y3*-1+s*x3)/s;
                y3=a*x3*x3*x3+b*x3*x3+c*x3+d;
            }

            x=Rex+1;
            y=F( a, b, c, d, x);
            x4=x;
            y4=y;

            while(fabs(y4)>pow(10,-6))
            {
                s= 3*a*x4*x4+2*b*x4+c;
                x4=(y4*-1+s*x4)/s;
                y4=a*x4*x4*x4+b*x4*x4+c*x4+d;
            }
            printf("%.4f %.4f %.4f\n", x3, x2, x4);
        }
    }
    return 0 ;
}
