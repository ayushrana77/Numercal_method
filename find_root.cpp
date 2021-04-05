#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<graphics.h>
#define EORRO 0.0001

//Draw the graph
struct point{
float x,y;
};
int draw_graph(float *xco,float*yco,int n)
{
    point pt[n];

    int i;

    line(320,20,320,460);
    line(20,240,620,240);
    for(i=1;i<=11;i++)
    {
        line(315,240-(i*20),325,240-(i*20));
        line(315,240+(i*20),325,240+(i*20));
    }
    for(i=1;i<=15;i++)
    {
        line(320-(i*20),235,320-(i*20),245);
        line(320+(i*20),235,320+(i*20),245);
    }
    for(i=0;i<n;i++)
    {
        pt[i].x=320+(xco[i]*20);
        pt[i].y=240-(yco[i]*20);
    }


    for(i=0;i<n-1;i++)
    {

        setfillstyle(SOLID_FILL,WHITE);
        circle(pt[i].x,pt[i].y,2);
        floodfill(pt[i].x,pt[i].y,15);
    }
    setfillstyle(SOLID_FILL,RED);
    circle(pt[n-1].x,pt[n-1].y,4);
    floodfill(pt[n-1].x,pt[n-1].y,15);
    moveto(pt[0].x,pt[0].y);
    lineto(pt[1].x,pt[1].y);

    return 0;
}

//Input equction and return matrix nX2
float **Input_matrix(int *n)
{
    float **arr;
    char str[100],temp[10];
    float val;
    int i,j=0,k=1;
    arr= (float**)calloc(j+1,sizeof(float*));
    arr[j]= (float*)calloc(2,sizeof(float*));
    printf("Enter the equction formatr : 10x^2+3x^1-4x^0=0\n\nDo not put equction in this formate 10x2+3x+4=10\n");
    scanf("%[^\n]%*c",str);
    memset(temp,0,strlen(temp));
    temp[0]=str[0];
    for(i=1;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            temp[k]='\0';
            val = atof(temp);
            arr[j][0]=val;
            k=0;
            memset(temp,0,strlen(temp));
            i++;
        }
        if(str[i]=='+' || str[i]=='-' )
        {
            temp[k]='\0';
            val=atof(temp);
            arr[j][1]=val;
            k=0;
            j++;
            memset(temp,0,strlen(temp));
            arr=(float**)realloc(arr,(j+1)*sizeof(float*));
            arr[j] = (float*)calloc(2,sizeof(float*));

        }
        if(str[i]=='^')
        {
            i++;
            memset(temp,0,strlen(temp));
            k=0;
        }
        temp[k]=str[i];
        k++;
    }
        temp[k]='\0';
        val=atof(temp);
        arr[j][1]=val;
    *n=j+1;
    return arr;
}
//print matrix
void print_matrix(float **matrix,int n)
{
    int i,j;
    for( i=0;i<n;i++)
    {
     for(j=0;j<2;j++)
     {
         printf("%f ",matrix[i][j]);
     }
     printf("\n");

    }
}
// find the value of f(x)
float findx(float **matrix,int n,float x)
{
    int i;
    float sum=0.0f,k;
    for(i=0;i<n;i++)
    {
        sum += (matrix[i][0]*pow(x,matrix[i][1]));
    }
    return sum;
}
// find valuse of diff f(x)
float finddx(float **matrix,int n,float x)
{
    float sum=0.0f,co,po;
    int i=0;
    for(int i=0;i<n;i++)
    {
        co  = (matrix[i][0]*matrix[i][1]);
        if(matrix[i][1]==0)
        {
            po=0.0f;
        }else{
            po  = pow(x,matrix[i][1]-1);
        }
        sum += (co*po);
    }
    return sum;
}
//**************************************************Bisection Method*************************************************
// return  Bisection point
float Bisect(float x,float y)
{
    return (x+y)/2;
}
void Bisection_Methods(float **matrix,int n)
{
    int i=1,k=1,itreation;
    float *xco,*yco;
    float x1,x2,x3,x;
    while(1)
    {
        if(findx(matrix,n,i-1)*findx(matrix,n,i)<0)
        {

            x1=i-1;
            x2=i;
            break;
        }
       i++;
    }
    printf(" \n\t\t The Root lies between %f and %f \n",x1,x2);
    x3=Bisect(x1,x2);
    printf("Enter the number of Itreation");
    scanf("%d",&itreation);
    xco=(float*)calloc(itreation,sizeof(float*));
    yco=(float*)calloc(itreation,sizeof(float*));
    xco[0]=x1;
    xco[1]=x2;
    yco[0]=findx(matrix,n,x1);
    yco[1]=findx(matrix,n,x2);
    k=1;
    while (k<=itreation)
    {
        if(findx(matrix,n,x1)*findx(matrix,n,x3)<0)
        {
            x2=x3;
        }else
        {
            x1=x3;
        }
        x=Bisect(x1,x2);
        if(fabs(x-x3)<EORRO)
        {
            printf("\n Root of the equction %f",x);
            k++;
            xco[k]=x3;
            yco[k]=findx(matrix,n,x3);
            break;
        }
        printf("Itreation %d root %f\n",k,x3);
        x3=x;
        k++;
        xco[k]=x3;
        yco[k]=findx(matrix,n,x3);
    }

    k=draw_graph(xco,yco,k);
}
//**************************************************Regular Falsi Method**********************************************
float regular_formula(float **matrix,int n,float x1,float x2)
{
    float numar,deom;
    numar=(x1*findx(matrix,n,x2))-(x2*findx(matrix,n,x1));
    deom=findx(matrix,n,x2)-findx(matrix,n,x1);
    return numar/deom;
}
void Regular_falsi_methoda(float **matrix,int n)
{
    float x1,x2,x3,x;
    float *xco,*yco;
    int i=1,itreation;
    while(1)
    {
        if(findx(matrix,n,i)*findx(matrix,n,i-1)<0)
        {
            x1=i-1;
            x2=i;
            break;
        }
        i++;
    }
    printf(" \n\t\t The Root lies between %f and %f \n",x1,x2);
    i=1;
    printf("Enter the number of Iteation : ");
    scanf("%d",&itreation);
    x3=regular_formula(matrix,n,x1,x2);
    xco=(float*)calloc(itreation,sizeof(float*));
    yco=(float*)calloc(itreation,sizeof(float*));
    xco[0]=x1;
    xco[1]=x2;
    yco[0]=findx(matrix,n,x1);
    yco[1]=findx(matrix,n,x2);
    while (i<=itreation)
    {
        if(findx(matrix,n,x1)*findx(matrix,n,x3)<0)
        {
            x2=x3;
        }
        else
        {
            x1=x3;
        }
        x=regular_formula(matrix,n,x1,x2);
        if(fabs(x3-x)<EORRO)
        {
            printf("The roots are %f",x);
            i++;
            xco[i]=x;
            yco[i]=findx(matrix,n,x3);
            break;
        }
        printf("Itreation %d root %f\n",i,x3);
        x3=x;
        i++;
        xco[i]=x3;
        yco[i]=findx(matrix,n,x3);
    }
    i=draw_graph(xco,yco,i);

}
//**************************************************Newton Reptions Method*******************************************
void Newton_reption_methods(float **matrix,int n)
{
    float x1,x2,x3,x;
    float *xco,*yco;
    int i=1,itreation;
    while (1)
    {
        if(findx(matrix,n,i)*findx(matrix,n,i-1)<0)
        {
            x1=i-1;
            x2=i;
            break;
        }
        i++;
    }
    printf(" \n\t\t The Root lies between %f and %f \n",x1,x2);
    x=(x1+x2)/2;
    printf("Enter the number of Iteation : ");
    scanf("%d",&itreation);
    xco=(float*)calloc(itreation,sizeof(float*));
    yco=(float*)calloc(itreation,sizeof(float*));
    xco[0]=x1;
    xco[1]=x2;
    yco[0]=findx(matrix,n,x1);
    yco[1]=findx(matrix,n,x2);
    i=1;
    while (i<=itreation)
    {
        x3= x-(findx(matrix,n,x)/finddx(matrix,n,x));
        if(fabs(x3-x)<EORRO)
        {
            printf("The root of the equcation : %f",x3);
            i++;
            xco[i]=x3;
            yco[i]=findx(matrix,n,x3);
            break;
        }
        printf("Itreation %d ,root %f\n",i,x3);
        x=x3;
        i++;
        xco[i]=x3;
        yco[i]=findx(matrix,n,x3);
    }

    i=draw_graph(xco,yco,i);

}
int main()
{
    int gd=DETECT,gm;
    int n=0;
    int i;
    float **matrix;
    initgraph(&gd,&gm,(char*)"");

    matrix = Input_matrix(&n);
    print_matrix(matrix,n);
    do
    {
        printf("\nChoose the methods \n1.Biesction\n2.newton Raption\n3.Regulaer Falsi\n4.exit");
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            Bisection_Methods(matrix,n);
            break;
        case 2:
            Newton_reption_methods(matrix,n);
            break;
        case 3:
            Regular_falsi_methoda(matrix,n);
            break;

        default:
            printf("Invalid choise !!");
        }

    } while(i!=4);
    closegraph();
    return 0;
}
