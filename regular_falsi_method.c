#include<stdio.h>
#include<math.h>
# define EORRO 0.0001
float f(float x)
{
    return (x*x*x)-(2*x)-5;
}
float formula(float x1,float x2)
{
    return ((x1*f(x2)-x2*f(x1))/(f(x2)-f(x1)));
}
void main()
{
    int maxitreation,i;
    float x,x1,x2,x3;
    printf("Enter the maxiune itreation");
    scanf("%d",&maxitreation);
    i=1;
    while (1)
    {
        if(f(i)*f(i-1)<0)
        {
            x1=i-1;
            x2=i;
            break;
        }
        i++;
    }
    i=0;
    printf("\nroot is lies between%f and %f \n",x1,x2);
    x3=formula(x1,x2);
    do{
        if(f(x3)*f(x2)<0)
        {
            x1=x3;
        }else{
            x2=x3;
        }
        x=formula(x1,x2);
        if(fabs(x3-x)<EORRO)
        {
            printf("\nroot %f",x);
            return;
        }
         printf("root %f iteration %d\n",x3,i);
        i++;
        x3=x;

    }while(i<=maxitreation);
    
}