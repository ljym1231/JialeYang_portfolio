#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
     int a,s,d,x;
     char m[x],n[x],i[x];
     printf("«Î ‰»ÎΩ«∂»÷µ£∫");
     scanf("%d%d%d",m[x],n[x],i[x]);
     for(x=0;x<6;x++)
     { 
          a=m[x]++;
          s=n[x]++;
          d=i[x]++;
     }
     printf("%d°„%d°‰%d°Â",a,s,d);
      
     system("pause");
     return 0;   
} 
