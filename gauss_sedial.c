#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <math.h>
#define EORRO 0.0001
float *get_coefficient(char *str,int n) // fuction return  array of coffine of given equction
{
    int i,j=0,x=0;
    char temp[10];
    float val=0.0f;
    float *coefficient;
    coefficient=(float*)calloc(n+1,sizeof(float*));
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            if(atof(temp)==0 && str[i-1]!='0')
            {
                temp[j]='1';
                j++;
            }
            temp[j]='\0';
            val=atof(temp);
            coefficient[x++]=val;
            memset(temp,0,strlen(temp));
            j=0;
            i++;
        }
        if(str[i]=='=')
        {
            j=0;
            i++;
        }
        temp[j]=str[i];
        j++;
    }
    if(atof(temp)==0 && str[i-1]!='0')
            {
                temp[j]='1';
                j++;
            }
            temp[j]='\0';
            val=atof(temp);
            coefficient[x]=val;
    return coefficient;

}
float **input_equction(int n)//return matrix change input  equction to in matrix formate 
{
    float *coeffi;
    float **arr;
    int i,j;
    char equction[100];
    printf("Enter  the equction formate :\n 1x+5y+z=12\n 0x+y+0z=0\n 3x+4y+5z=1\n\n");
    arr=(float**)calloc(n,sizeof(float*));
    for( i=0;i<n;i++)
    {
        fflush(stdin);
        printf("Enter the equction %d :",i+1);
        scanf( "%[^\n]%*c",equction);
        coeffi=get_coefficient(equction,n);
        arr[i]=(float*)calloc(n+1,sizeof(float*));
        for( j=0;j<n+1;j++)
        {
            arr[i][j]=coeffi[j];
        }
        memset(equction,0,strlen(equction));
    }
    free(coeffi);
    return arr;
}
void print_matri(float **matrix,int n)//print the matrix
{
    int i,j;
    for( i=0;i<n;i++)
    {
        for( j=0;j<n+1;j++)
        {
            printf("%f  ",matrix[i][j]);
        }
        printf("\n");
    }
}
bool method_Applicable(float **matrix,int n)//check metohd is applicblle
{
    float summatrix=0,sum=0;
    int i,j;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            summatrix +=fabs(matrix[i][j]);
        }
        sum += fabs(matrix[i][n]);
    }
    if(sum<summatrix)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void print_value(float *value,int n)//print the value of x1,x2,x3,.....
{
    int i=0;
    for(int i=0;i<n;i++)
    {
        printf("X%d = %f    ",i+1,value[i]);
    }
}
void gauss_sedial(float **matrix,int n)//calculate the value of x1,x2,x3.......
{
        float *value_new,*value_old;
        float sum;
        int i,j,k=1,itreation,flag=0;
        value_new = (float*)calloc(n,sizeof(float*));
        value_old = (float*)calloc(n,sizeof(float*));
        for(i=0;i<n;i++)
        {
            value_new[i]=0;
            value_old[i]=0;
        }
        printf("Enter the max itration : ");
        scanf("%d",&itreation);
        for(k=1;k<=itreation;k++)
        {
            // get new value of x1,x2,x2....
            for(i=0;i<n;i++)
            {
                sum=0.0f;
                for(j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        sum = sum + matrix[i][j]*value_new[j];
                    }
                }
                value_new[i]=(matrix[i][n]-sum)/matrix[i][i];
            }
            // check the new value with old value;
            for(i=0;i<n;i++)
            {
                if(fabs(value_old[i]-value_new[i])<EORRO)
                {
                    continue;
                }
                else
                {
                    flag=1;
                }
            }
            // if value find print and return
            if(flag==0)
            {
                print_value(value_new,n);
                return;
            }
            flag=0;//set zero to next itreation
            //copy new value to old value
            for(i=0;i<n;i++)
            {
                value_old[i]=value_new[i];
            }
            printf("value of itration %d",k);
            print_value(value_new,n);
            printf("\n");
        } 
        //from eorro we cannot find we simply print when itreation is over
        print_value(value_new,n);
        free(value_new);
        free(value_old);
        
}
int main()
{
    float **matrix;
    int n;
    printf("Enter the number unknown variable :");
    scanf("%d",&n);
    matrix = input_equction(n);
    print_matri(matrix,n);
    if(method_Applicable(matrix,n))
    {
        printf("This method is not appicable");
        return 0;
    }
    printf("This method are appicable");
    gauss_sedial(matrix,n);
    free(matrix);
    return 0;
}