#include <stdio.h>

int main()
{
    FILE *input;
    int  i,j, k, d, n, judge[5000],count[6];
    double a[10][5000], avg[5000], result[6], group[10][5000] ;

    input = fopen("trainingData.txt","r");//trainingData
    if(NULL==input)
    {
        printf("File not found!!\n");

        return 0;
    }

    fscanf(input,"%d %d", &d, &n);
    printf("維度:%d 資料點數:%d\n\n", d, n);

    for(i=0; i<d; i++)
    {
        for (j=0; j<n; j++)
        {
            fscanf(input, "%lf", &a[i][j]);
            //printf(" %.2f", a[i][j]);
        }
        //printf("\n\n");
    }

    for (i=0; i<n; i++)
    {
        fscanf(input, "%d", &judge[i]);
        //printf(" %d", judge[i]);
    }

    printf("各資料點平均\n");

    for (j=0; j<n; j++)
    {
        for(i=0; i<d; i++)
        {
            avg[j] = avg[j] + a[i][j];

        }
        avg[j] = avg[j]/d;
        printf("%f ", avg[j]);

    }



    for(i=0; i<6; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==judge[j])
            {
                count[i]=count[i]+1;
            }
            else
            {
                continue;
            }
        }
        //printf("\n\n%d", count[i]);

    }
    for(i=0; i<6; i++)
    {
        k=0;
        for(j=0; j<n; j++)
        {
            if(judge[j]==i)
            {
                group[i][k]=avg[j];
                k++;
            }
            else
            {
                continue;
            }
        }

    }
    for(i=0; i<6; i++)
    {
        for(j=0; j<count[i]; j++)
        {
            //printf("  %f", group[i][j]);
            result[i]=result[i]+group[i][j];
        }
        //printf("\n");
    }

    for (i=0; i<d; i++)
    {
        if(count[i]==0)
        {
            result[i]=0;
            continue;
        }

        result[i]=result[i]/count[i];

    }

    printf("\n\n");

    for(i=0; i<6; i++)
    {
        printf("\nGroup %d\n資料平均:%.3f 資料數: %d\n", i, result[i], count[i] );
        for(j=0; j<count[i]; j++)
        {
            printf("%f ", group[i][j]);
        }

        printf("\n");
    }


    FILE *output;

    output = fopen("parameter.txt","w");

    for(i=0; i<6; i++)
    {
        fprintf(output,"%f %d\n", result[i], count[i]);
        for(j=0; j<count[i]; j++)
        {
            fprintf(output,"%f ", group[i][j]);
        }
        fprintf(output, "\n");
    }

    fclose(output);

    return 0;
}






