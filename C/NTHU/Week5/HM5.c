#include <stdio.h>

#define ROW 100
#define COL 600

void printArray(double array[ROW][COL], int rowNum, int colNum)
{
    int i, j;
    for(i=0; i<rowNum; i++)
    {
        for(j=0; j<colNum; j++)
        {
            printf("%f ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    int i, j, m, n;
    double a[ROW][COL];

    scanf("%d %d", &m, &n);

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%lf",&a[i][j]);
        }
    }

    double avg[ROW], sum;
    for(i=0; i<m; i++)
    {
        sum=0;
        for(j=0; j<n; j++)
        {
            sum=sum+a[i][j];
        }
        avg[i]=sum/n;
    }
    printf("\n");

    double sigS[ROW], sumS2;
    for(i=0; i<m; i++)
    {
        sumS2=0;
        for(j=0; j<n; j++)
        {
            sumS2=sumS2+(a[i][j]-avg[i])*(a[i][j]-avg[i]);
        }
        sigS[i]=sumS2/(n-1);
        printf("%f\n", sigS[i]);
    }

    double sigD[ROW][COL], sumD1, sumDq, sumDs;
    int comp;
    for(i=0; i<m; i++)
    {
        for(comp=0; comp<m; comp++)
        {
            sumD1=0;
            sumDq=0;
            sumDs=0;
            for(j=0; j<n; j++)
            {
                sumD1=sumD1+(a[i][j]*a[comp][j])/(n-1);
                sumDq=sumDq+a[i][j];
                sumDs=sumDs+a[comp][j];
            }
            sigD[i][comp]=sumD1-sumDq*sumDs/(n*n-n);
        }
    }
    printf("\n");
    printArray(sigD, m, m);


    return 0;
}
