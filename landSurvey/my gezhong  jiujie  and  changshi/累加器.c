#include <stdio.h>
#include <stdlib.h>
#define M 6;
int main(void)
{
     int i,x[i],n;
     x[1]=225.752;
     x[2]=139.033;
     x[3]=172.571;
     x[4]=100.068;
     x[5]=102.486;
     for(i=0;i<6;i++)
     {
          n=x[i]++;
          printf("n=%d",n);
     }
     system("pause");
     return 0;   
} 
