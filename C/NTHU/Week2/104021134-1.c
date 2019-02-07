#include<stdio.h>

int main()
{
    int a, b, c, d, x, y, g, z/*星期幾*/;
    //printf("求幾年幾月的一號是星期幾");
    printf("請輸入 年分\\月份\\第幾個禮拜\\星期幾\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(b<=2)
    {
        b=b+12;
        a=a-1;
    }
    printf("(year,month)=(%d,%d)",a,b);

    x=a/100;//前兩位
    printf(" \n前兩位=%d",x);
    y=a-x*100;//後兩位
    printf(" 後兩位=%d ",y);
    g=(y+y/4+x/4-2*x+(26*b+26)/10)%7;
    printf("\n此月一號為星期%d\n\n",g);
    if(g<=0)
    {
        g=g+7;
    }

    if(d>=g)
    {
       z=(c-1)*7+d-g+1;
    }
    else
    {
       z=c*7+d-g+1;
    }


    printf("此天為%d號!XD\n",z);

    return 0;
}
