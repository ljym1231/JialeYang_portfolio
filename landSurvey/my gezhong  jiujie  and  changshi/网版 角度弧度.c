#include<stdio.h>
#define PI 3.14159265f
int main(void)
{ 
     int i; 
     float ooo; 
     printf("����Ƕ��밴1,���뻡���밴2\n"); 
     scanf("%d",&i); 
     switch(i) 
     { 
               case 1:  printf("����Ƕȣ�");  
                       scanf("%f",&ooo);  
                       printf("����Ϊ:%f\n",(ooo/180)*PI);
                       system("pause");  
                       break; 
               case 2:  printf("���뻡�ȣ�");  
                        scanf("%f",&ooo);  
                        printf("�Ƕ�Ϊ:%f\n",(ooo/PI)*180);
                        system("pause"); 
     }
}
