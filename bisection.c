#include<stdio.h>
#include<math.h>
#define EORRO 0.0001
float findvaluex(float x)
    {
        return (x*x*x)-(2*x)-5;
    }
float bisect(float x1, float x2)
    {
        return (x1+x2)/2;
    }
void main()
{
    int maxitreatin,i;
    float x1,x2,x3,x;
    printf("Enter the maximum itreation");
    scanf("%d",&maxitreatin);
    for(i=1;;i++)
    {
        if(findvaluex(i)*findvaluex(i-1)<0)
        {
            x1=i-1;
            x2=i;
            break;
        }
    }
    printf("\nroot lies between %f and %f\n",x1,x2);
    x3= bisect(x1,x2);
    i=0;
    do
    {
        if(findvaluex(x3)*findvaluex(x2)<0)
        {
            x1=x3;
        }else
        {
            x2=x3;
        }
        x=bisect(x1,x2);
        if(fabs(x-x3)<EORRO)
        {
            printf("root is %f",&x);
            return;
        }
        printf("itreation %d root %f\n",i,x3);
        x3=x;
        i++;
    }while(i<=maxitreatin);
}