#include<stdio.h>
main()
{
    float x,y;
    float *z;
    y=10.0;
    z=&y;
    x=*z;
    printf("%f\t %f",y,x);
    *z=9.0;
      printf("%f\t %f",y,x);
    }
