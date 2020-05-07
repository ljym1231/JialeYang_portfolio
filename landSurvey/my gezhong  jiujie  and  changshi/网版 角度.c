#include<stdio.h>
#include<math.h>
int main(void)
{    
     double a[]={1.2, 3.2, 4, 5.3, 0.3};  
     double b[]={1.3, 0.2, 2.3, 3, 8.3};
     double num=0, den, temp1=0, temp2=0, theta;  
     int i;    // 通过向量个数是否相同来判断2向量维数是否一致   
     if(sizeof(a)/sizeof(a[0]) != sizeof(b)/sizeof(b[0]))     
          printf("向量维数不一致");   
     for(i=0; i<sizeof(a)/sizeof(a[0]); i++)   
     {     
          num += a[i]*b[i];   // 公式中分子的值     
          temp1 += a[i]*a[i];   
          temp2 += b[i]*b[i];    
     }   
     den = sqrt(temp1)*sqrt(temp2);  // 公式中分母的值    
     theta = acos(num/den);  // 所求的角度值
     system("pause");
}
