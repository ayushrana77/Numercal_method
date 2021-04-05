#include<stdio.h>
void display(float arr[10][10],int n)
{
    int i,j;
       for( i =0;i<n;i++)
    {
        for( j=0;j<n+1;j++)
        {
            printf("%f ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int n,i,j,k;
    float arr[10][10],ratio;
    printf("Enter the number of unknoes");
    scanf("%d",&n);
     for( i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
           scanf("%f",&arr[i][j]);
        }
    } 
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    ratio=arr[j][i]/arr[i][i];
                    for(k=0;k<n+1;k++)
                    {
                        arr[j][k]= arr[j][k] - (ratio*arr[i][k]);
                    }
                    display(arr,n);
                }
                printf("\n");
            }
        }
        
 

}