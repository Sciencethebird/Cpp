#include<stdio.h>

int main()
{

    int a, b, c, d, x, y, g, z/*�P���X*/;
    printf("�{��:�D�X�X�~�X�몺�ĴX��§���X�O�X��\n");
    printf("�п�J �~��\\���\\�ĴX��§��\\�P���X\n\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(b<=2)//�C�~1,2��⦨�h�~13,14��
    {
        b=b+12;
        a=a-1;
    }
    printf("\n�B���(year,month)=(%d,%d)",a,b);

    x=a/100;//�e���
    printf(" \n�e���=%d",x);

    y=a-x*100;//����
    printf(" ����=%d ",y);

    g=(y+y/4+x/4-2*x+(26*b+26)/10)%7;

    printf("\n����@�����P��%d\n\n",g);
    if(g<=0)//�קK�t���M�P��"�s"�X�{
    {
        g=g+7;
    }

    if(d>=g)
    {
       z=(c-1)*7+d-g+1;
    }
    else
    {
       z=c*7+d-g+1;//�S���Ĥ@�ӬP��
    }


    printf("���Ѭ�%d��!XD\n",z);

    printf("�޿�:\n���ν��Ǥ������X���@���O�P���X\n�b�Ѧ����X����");

    return 0;
}
