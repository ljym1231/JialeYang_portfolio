#include<stdio.h>
#define PI 3.14159265f
int main(void)
{ 
     int i; 
     float ooo; 
     printf("输入角度请按1,输入弧度请按2\n"); 
     scanf("%d",&i); 
     switch(i) 
     { 
               case 1:  printf("输入角度：");  
                       scanf("%f",&ooo);  
                       printf("弧度为:%f\n",(ooo/180)*PI);
                       system("pause");  
                       break; 
               case 2:  printf("输入弧度：");  
                        scanf("%f",&ooo);  
                        printf("角度为:%f\n",(ooo/PI)*180);
                        system("pause"); 
     }
}
