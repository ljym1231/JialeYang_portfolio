#include<stdio.h>
#include<math.h>
int main(void)
{    
     double a[]={1.2, 3.2, 4, 5.3, 0.3};  
     double b[]={1.3, 0.2, 2.3, 3, 8.3};
     double num=0, den, temp1=0, temp2=0, theta;  
     int i;    // ͨ�����������Ƿ���ͬ���ж�2����ά���Ƿ�һ��   
     if(sizeof(a)/sizeof(a[0]) != sizeof(b)/sizeof(b[0]))     
          printf("����ά����һ��");   
     for(i=0; i<sizeof(a)/sizeof(a[0]); i++)   
     {     
          num += a[i]*b[i];   // ��ʽ�з��ӵ�ֵ     
          temp1 += a[i]*a[i];   
          temp2 += b[i]*b[i];    
     }   
     den = sqrt(temp1)*sqrt(temp2);  // ��ʽ�з�ĸ��ֵ    
     theta = acos(num/den);  // ����ĽǶ�ֵ
     system("pause");
}
