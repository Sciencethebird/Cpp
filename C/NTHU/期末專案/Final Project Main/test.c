#include <stdio.h>

int main()
{
    int datalenth[6], groupnum=0, i, j, d, n, s=0, k, idx[5000];///data是from Train
    double dataavg[6], group[10][5000], testA[10][5000], distavg[6], testavg[5000],min;

    FILE *learnt, *test;

    learnt = fopen("parameter.txt","r");
    for(i=0; i<6; i++)
    {
        fscanf(learnt,"%lf %d", &dataavg[i], &datalenth[i]);
        //printf("%f  %d\n", dataavg[i], datalenth[i]);
        if(datalenth[i]!=0)
        {
            for(j=0; j<datalenth[i]; j++)
            {
                fscanf(learnt,"%lf", &group[i][j]);
            }
        }
        else
        {
            break;
        }
        groupnum++;

    }

    test=fopen("testData.txt","r");
    fscanf(test,"%d %d", &d, &n);
    printf("測資維度: %d 資料點個數: %d\n", d, n );
    for(i=0; i<d; i++)
    {
        for(j=0; j<n; j++)
        {
            fscanf(test,"%lf",&testA[i][j]);
        }
    }

    /*for(i=0; i<groupnum; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%.1f ",group[i][j]);
        }
        printf("\n");
    }*/

    ///test data average
    printf("測試資料點平均\n");
    for(j=0; j<n; j++)
    {
        for (i=0; i<6; i++)
        {
            testavg[j]=testavg[j]+testA[i][j];
        }
        testavg[j]=testavg[j]/d;
    }
    for(j=0; j<n; j++)
    {
        printf("%.2f ",testavg[j]);
    }
    printf("\n\n\n分類結果:\n\n\n");
    ///以下為判斷距離
    for(j=0; j<n; j++)
    {
        for(i=0; i<groupnum; i++)
        {
            for(k=0; k < datalenth[i]; k++)
            {
                distavg[i]=distavg[i]+fabs(testavg[j]-group[i][k]);
            }
            distavg[i]=distavg[i]/datalenth[i];
        }
        min=distavg[0];
        for(i=0; i<groupnum; i++)
        {
            idx[j]=0;
            if(distavg[i]<min)
            {
                min=distavg[i];
                idx[j]=i;
            }
            else
            {
                continue;
            }

        }

        printf("%d ", idx[j]);

    }
        FILE *output;
    output = fopen("prediction.txt","w");
    for(j=0; j<n; j++)
    {
        fprintf(output,"%d", idx[j]);
    }
    fclose(output);

    return 0;
}




