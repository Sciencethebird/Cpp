#include<stdio.h>

int main()
{

    int a, b, c, d, x, y, g, z/*星期幾*/;
    printf("程式:求出幾年幾月的第幾個禮拜幾是幾號\n");
    printf("請輸入 年分\\月份\\第幾個禮拜\\星期幾\n\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(b<=2)//每年1,2月算成去年13,14月
    {
        b=b+12;
        a=a-1;
    }
    printf("\n運算值(year,month)=(%d,%d)",a,b);

    x=a/100;//前兩位
    printf(" \n前兩位=%d",x);

    y=a-x*100;//後兩位
    printf(" 後兩位=%d ",y);

    g=(y+y/4+x/4-2*x+(26*b+26)/10)%7;

    printf("\n此月一號為星期%d\n\n",g);
    if(g<=0)//避免負號和星期"零"出現
    {
        g=g+7;
    }

    if(d>=g)
    {
       z=(c-1)*7+d-g+1;
    }
    else
    {
       z=c*7+d-g+1;//沒有第一個星期
    }


    printf("此天為%d號!XD\n",z);

    printf("邏輯:\n先用蔡勒公式推出當月一號是星期幾\n在由此推出答案");

    return 0;
}
