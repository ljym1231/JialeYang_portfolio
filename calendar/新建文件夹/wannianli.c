
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char* month_str[]={"January","February","March","April","May","June","July","August","September","October","November","December"}; 
char* week[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}; 

int leap (int year)//判断闰年
{ 
      if(year%4==0&&year%100!=0||year%400==0)
      return 1;
      else return 0;
}




int month_day(int year,int month) //判断这一个月有多少天
{ 
    int mon_day[]={31,28,31,30,31,30,31,31,30,31,30,31}; //初始化每个月的天数
    if(leap(year)&&month==2 ) 
    return 29; 
    else 
    return(mon_day[month-1]); 

}




int firstday(int year,int month,int day)//判断这一个月的第一天是星期几
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
    printf("\n\n**************%d年的日历**************\n",year); 
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
              while (j<=4*a)//乘4为了使空格对齐 
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
    time_t when;//调用系统时间
    struct tm *now;
    when = time(NULL);
    now = localtime(&when);
    printf("现在时间: %4d年 %d月 %02d日 %d:%02d:%02d\n", now->tm_year+1900, now->tm_mon+1, now->tm_mday,now->tm_hour, now->tm_min, now->tm_sec);

    while(1) 
    { 
        printf("\n请选择你所需要的服务:\n"); 
        printf("\n输入1判断某年是否为闰年"); 
        printf("\n输入2输出某年的日历"); 
        printf("\n输入3结束程序\n"); 
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
               fflush(stdin); //清空输入缓冲区 
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
