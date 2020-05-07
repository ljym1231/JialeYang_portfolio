
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char* month_str[]={"January","February","March","April","May","June","July","August","September","October","November","December"}; 
char* week[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}; 

int leap (int year)//�ж�����
{ 
      if(year%4==0&&year%100!=0||year%400==0)
      return 1;
      else return 0;
}




int month_day(int year,int month) //�ж���һ�����ж�����
{ 
    int mon_day[]={31,28,31,30,31,30,31,31,30,31,30,31}; //��ʼ��ÿ���µ�����
    if(leap(year)&&month==2 ) 
    return 29; 
    else 
    return(mon_day[month-1]); 

}




int firstday(int year,int month,int day)//�ж���һ���µĵ�һ�������ڼ�
{
    int c=0; 
    float s; 
    int m; 
    for(m=1;m<month;m++) 
    c=c+month_day(year,m)+day; 
    s=year-1+(float)(year-1)/4+(float)(year-1)/100+(float)(year-1)/400-40+c; 
    return ((int)s%7); 
}




int PrintAllYear(int year) 
{ 
    int a,b; 
    int i,j=1,n=1,k; 
    printf("\n\n**************%d�������**************\n",year); 
    for(k=1;k<=12;k++) 
    {
        j=1,n=1;               
        b=month_day(year,k);
        a=firstday(year,k,1);
        printf("\n\n%s(%d)\n",month_str[k-1],k); 
        printf(" **************Sun Mon Tue Wed Thu Fri Sat \n**************");
        if(a==7)
        {
             for(i=1;i<=b;i++)
             {
                 printf("%d",i); 
                 if(i%7==0)
                 {
                     printf("**************\n**************");
                 }
              }
         }
        if(a!=7)
        {
              while (j<=4*a)//��4Ϊ��ʹ�ո���� 
              {
                     printf(" ");
                     j++;
               }
               for(i=1;i<=b;i++)
               {
                    printf("%4d",i); 
                    if(i==7*n-a)
                    {
                       printf("**************\n**************");
                       n++;
                     }
                }
        }
        printf("**************\n"); 
    }
    return 1;
}


int main()
{
    int option; 
    char m; 
    int year,month,day; 
    printf("\n\nWelcome to use the WanNianLi system!\n");
    time_t when;//����ϵͳʱ��
    struct tm *now;
    when = time(NULL);
    now = localtime(&when);
    printf("����ʱ��: %4d�� %d�� %02d�� %d:%02d:%02d\n", now->tm_year+1900, now->tm_mon+1, now->tm_mday,now->tm_hour, now->tm_min, now->tm_sec);

    while(1) 
    { 
        printf("\n��ѡ��������Ҫ�ķ���:\n"); 
        printf("\n����1�ж�ĳ���Ƿ�Ϊ����"); 
        printf("\n����2���ĳ�������"); 
        printf("\n����3��������\n"); 
        scanf("%d",&option); 

        switch(option) 
        { 
           case 1: 
           while(1) 
           { 
               printf("\nPlease input the year which needs searched?(XXXX)"); 
               scanf("%d",&year); 
               if(leap(year)) 
               {
                  printf("\n%d is Leap year,do you want to continue?(Y/N)",year); 
               }
               else 
               {
                  printf("\n%d is not Leap year,do you want to continue(Y/N)?",year); 
               }   
               fflush(stdin); //������뻺���� 
               scanf("%c",&m); 
               if(m=='N'||m=='n') 
               break; 
           } 
           break; 
           case 2: 
           while(1) 
           { 
               printf("\nPlease input the year which needs printed(XXXX)"); 
               scanf("%d",&year); 
               PrintAllYear(year); 
               printf("\nDo you want to continue to print(Y/N)?"); 
               fflush(stdin); 
               scanf("%c",&m); 
               if(m=='N'||m=='n') 
               break; 
           } 
           break; 
           case 3: 
           fflush(stdin); 
           printf("Are you sure?(Y/N)"); 
           scanf("%c",&m); 
           if(m=='Y'||m=='y') 
           exit(0); 
           break; 
           default: 
           printf("\nError:Sorry,there is no this service now!\n"); 
           break; 
        } 

     } 

     return 0;
} 
