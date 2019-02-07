#include <stdio.h>

#define ROW 50
#define COL 500


double det(double array[100][100], int n)
{
    double temp[100][100], result = 0;
    int sign = 1, i, ii, jj, iCounter;
    if(n==2)
    {
        return array[0][0] * array[1][1] - array[0][1] * array[1][0];
    }
    for(i=0; i<n; i++)
    {
        iCounter = 0;
        for(ii=0; ii<n; ii++)
        {
            if(ii==i)
            {
                continue;
            }
            for(jj=1; jj<n; jj++)
            {
                temp[iCounter][jj-1] = array[ii][jj];
            }
            iCounter++;
        }
        result += sign * array[i][0] * det(temp, n-1);
        sign = -sign;
    }
    return result;
}

int main()
{
    int i, j, m, n;
    double a[ROW][COL];

    while(m!=0 && n!=0)
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

        double sigD[100][100], sumD1, sumDq, sumDs;
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
        printf("%.4f\n",det(sigD, m));
    }
    return 0;
}
