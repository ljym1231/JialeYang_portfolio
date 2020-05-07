#include <stdio.h>
#include <stdlib.h>
#define SIGN_WEEK 6
#define SIGN_YEAR 2000
void calendar(int week,int year) //显示日历 
{
    int month_day[14]={31,31,0,31,30,31,30,31,31,30,31,30,31,31};
    char month_name[12][10]={"January","February","March","Apirl","May","June","July","August","September","October","November","December"};
    int i,j,n,m,num0=0,num1=31,nweek0=week,nweek1;
    if(year%4==0)
    {
        if(year%100!=0)
        {
            month_day[2]=29;
        }
        else
        {
            if(year%400==0)
            {
                month_day[2]=29;
            }
            else month_day[2]=28; 
        } 
    }
    else month_day[2]=28;
    system("CLS");
    printf("The calendar of the year %d\n\n",year);
    for(m=0;m!=12;m+=2)
    {
        if(m-1<0)
        {
            nweek0=week;
            nweek1=(week+num1%7)>7?(week+num1%7)-7:(week+num1%7); 
        }
        else
        {
            num0=num0+month_day[m-1]+month_day[m];
            nweek0=(week+num0%7)>7?(week+num0%7)-7:(week+num0%7); 
            num1=num1+month_day[m]+month_day[m+1];
            nweek1=(week+num1%7)>7?(week+num1%7)-7:(week+num1%7); 
        }
        printf("%-10s %2d %-10s %2d\n=========================== ===========================\nSun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat\n",month_name[m],m+1,month_name[m+1],m+2);
        for(i=nweek0,j=nweek1,n=0;j!=nweek1-6*7;j--)
        {
            if(n<7)
            {
                if(i>0)
                {
                    printf("%3d ",month_day[m]-i+1);
                }
                else if(i<=0)
                {
                    if(i>-month_day[m+1]) printf("%3d ",-i+1);
                    else printf("%3d ",-i-month_day[m+1]+1);
                }
                i--;
                j+=1;
                n++;
            }
            else
            {
                if(j>0) printf("%3d ",month_day[m+1]-j+1);
                else if(j<=0)
                {
                    if(j>-month_day[m+2]) printf("%3d ",-j+1);
                    else printf("%3d ",-j-month_day[m+2]+1);
                }
                n++; 
            }
            if(n==14)
            {
                printf("\n");
                n=0; 
            }
        }
        printf("=========================== ===========================\n\n");
    } 

}
void startWeek(int year) //确定需要显示的年份的第一天是星期几
{ 
    int start_week,days;
    if(year>SIGN_YEAR)
    {
        days=(year-SIGN_YEAR)*365+(year-SIGN_YEAR)/4-(year-SIGN_YEAR)/100+(year-SIGN_YEAR)/400+(((year-SIGN_YEAR)%4)+3)/4+((year-SIGN_YEAR)%400==0?0:((year-SIGN_YEAR)%100==0?1:0));
        start_week=(SIGN_WEEK+days%7)>7?(SIGN_WEEK+days%7)-7:(SIGN_WEEK+days%7);
    } 
    else
    {
        days=(SIGN_YEAR-year)*365+(SIGN_YEAR-year)/4-(SIGN_YEAR-year)/100+(SIGN_YEAR-year)/400;
        start_week=(SIGN_WEEK-days%7)>0?(SIGN_WEEK-days%7):(SIGN_WEEK-days%7+7);
    }
    calendar(start_week,year);
} 
int main(void)
{
    int year,i;
    printf(" 1.Calendar\n 2.Query\n Select:");
    scanf("%d",&i);
    if(i==1)
    {
        printf("Enter year:");
        scanf("%d",&year);
        startWeek(year); 
    }
    else
    {
        //function 2 code 
    }
    getchar();
    getchar();
    system("pause");
    return 0;
}
