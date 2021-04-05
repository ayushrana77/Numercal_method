#include<stdio.h>
void main()
{
    int n,i,j,k;
    float a[10][10],ratio,values[10],sum;
    printf("Entet the number unkown");
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j>i)
                {
                    ratio=a[j][i]/a[i][i];
                    for(k=0;k<n+1;k++)
                    {
                        a[j][k] -= ratio*a[i][k];
                    }
                }
            }
        }
    for(int i=0;i<n;i++)
        {
            for(j=0;j<n+1;j++)
            {
                printf("%f ",a[i][j]);
            }
            printf("\n");
        }
    values[n-1]= a[n-1][n]/a[n-1][n-1];
    printf("%f",a[n-1][n]/a[n-1][n-1]);
    for(i=n-2;i>=0;i--)
        {
            sum=0;
            for(j=i+1;j<n;j++)
            {
                sum += a[i][j]*values[j];
            }
            values[i] = (a[i][n] - sum)/a[i][i];
        }
    for(i=0;i<n;i++)
    {
        printf("value of X%d = %f\n",i+1,values[i]);
    }
}