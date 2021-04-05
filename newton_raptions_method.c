#include<stdio.h>
#include<math.h>
#define EORRO 0.0001
float findx(float x)
{
    return (x*x*x)-(2*x)-5;
}
float diff(float x)
{
    return (3*x*x)-2;
}
int main()
{
    int maxiteration,i;
    float x1,x2,x,x3;
    printf("Enter the max number of iteration");
    scanf("%d",&maxiteration);
    i=1;
    while(1)
    {
        if(findx(i)*findx(i-1)<0)
        {
            x2=i;
            x1=i-1;
            break;
        }
        i++;
    }
    printf("\n root lie between %f and %f\n",x1,x2);
    x=(x1+x2)/2;
    i=0;
    do{
        x3=x-(findx(x)/diff(x));
        if(fabs(x3-x)<EORRO)
        {
            printf("\nroot are :%f \n",x3);
            break;
        }
        printf("itration %d and root %f\n",i,x3);
        i++;
        x=x3;
    }while(i<=maxiteration);
}