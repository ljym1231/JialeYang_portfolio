#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
     int a,s,d,x;
     char m[x],n[x],i[x];
     printf("������Ƕ�ֵ��");
     scanf("%d%d%d",m[x],n[x],i[x]);
     for(x=0;x<6;x++)
     { 
          a=m[x]++;
          s=n[x]++;
          d=i[x]++;
     }
     printf("%d��%d��%d��",a,s,d);
      
     system("pause");
     return 0;   
} 
