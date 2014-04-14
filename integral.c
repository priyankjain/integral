#include<stdio.h>
#include<math.h>
#define func(x) (a*pow(x,2)+b*pow(x,1)+c)
double trapezoidalIntegral(double a,double b,double c,double left,double right,int N)
{
    double h=(right-left)/N;
    double sum=func(left)+func(right);
    int i=2;
    while(i<=N)
    {
      sum=sum+2*func(left+(i-1)*h);
      i++;
    }
    double integral=h*sum/2;
    return integral;
}
int main()
{
    FILE* fin=fopen("data.txt","r");
    if(!fin)
    {
        printf("Error opening file data.txt");
        return -1;
    }
    double a,b,c,left,right;
    int N;
    fscanf(fin,"%lf %lf %lf %lf %lf %d",&a,&b,&c,&left,&right,&N);
    fclose(fin);
    printf("Final Result: %lf",trapezoidalIntegral(a,b,c,left,right,N));
    return 0;
}
