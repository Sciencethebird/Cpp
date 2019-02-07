#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 50
#define COL 500
#define SIZE 50
void printArray(double array[][SIZE], int rowNum, int colNum){
    int i, j;
    for(i=0;i<rowNum;i++){
        for(j=0;j<colNum;j++){
            printf("%.4f ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void rowExchange(double array[][SIZE], int size, int idx1, int idx2)
{
    int i;
    double temp;
    for(i=0; i<size; i++)
    {
        temp = array[idx1][i];
        array[idx1][i] = array[idx2][i];
        array[idx2][i] = -temp;//**********
    }
}
void addRowToAnother(double array[][SIZE], int size, double c, int idx1, int idx2)
{
    int i;
    for(i=0; i<size; i++)
    {
        array[idx2][i] += c * array[idx1][i];
    }
}
int main()
{
    int i, j, m, n;
    double a[ROW][COL];

    while(1)
    {
        scanf("%d %d", &m, &n);
        if(m==0 &&n ==0)
        {
            break;
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%lf",&a[i][j]);
            }
        }

        double sigD[SIZE][SIZE], sumD1, sumDq, sumDs;
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

        double maxVal;
        int i, j, maxRowIdx;

        for(j=0; j<m-1; j++)
        {
            maxVal = fabs(sigD[j][j]);
            maxRowIdx = j;
            for(i=j+1; i<m; i++)
            {
                if(fabs(sigD[i][j])>maxVal)
                {
                    maxVal = fabs(sigD[i][j]);
                    maxRowIdx = i;
                }
            }
            if(maxVal==0)
            {
                continue;
            }
            if(maxRowIdx!=j)
            {
                rowExchange(sigD, m, j, maxRowIdx);
            }
            for(i=j+1; i<m; i++)
            {
                //printf("%.4f * row %d + row %d:\n", -sigD[i][j]/sigD[j][j], j, i);
                addRowToAnother(sigD, m, -sigD[i][j]/sigD[j][j], j, i);
                printArray(sigD, m,m);
            }
        }
        double det=1;
        for(i=0; i<m; i++)
        {
            det= det * sigD[i][i];
        }
        printf("%.4f\n", det);
    }
    return 0;
}
