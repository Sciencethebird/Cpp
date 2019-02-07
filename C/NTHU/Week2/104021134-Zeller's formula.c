#include<stdio.h>

int main()
{
    int y, m, k, w, f, b, g, z;
    scanf("%d %d %d %d", &y, &m, &k, &w);
    if(m<=2)
    {
        m=m+12;
        y=y-1;
    }

    f=y/100;
    b=y-f*100;
    g=(b+b/4+f/4-2*f+(26*m+26)/10)%7;

    if(g<=0)
    {
        g=g+7;
    }

    if(w>=g)
    {
       z=(k-1)*7+w-g+1;
    }
    else
    {
       z=k*7+w-g+1;
    }
    printf("%d\n",z);

    return 0;
}
