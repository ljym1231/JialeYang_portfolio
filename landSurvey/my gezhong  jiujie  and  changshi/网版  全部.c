//���귽λ�Ǽ�����
# include <stdio.h> 
# include <math.h>  
# define PI 3.1415926535897932 

int main(void) 
{ 
     long double RadianToAngle(long double alfa); 
     double JSFWJ(double vx,double vy); 
     double JSJL(double xa,double ya,double xb,double yb); 
     double xa,xb,ya,yb; 
     double vx,vy; 
     long double alfa; 
     double s; 
     printf ("������xa,ya,xb,yb������\n"); 
     scanf ("%lf,%lf,%lf,%lf",&xa,&ya,&xb,&yb); 
     vx=xb-xa; 
     vy=yb-ya;  
     alfa=JSFWJ(vx,vy); 
     s=JSJL(xa,ya,xb,yb);  
     printf ("��λ��alfa=%lf\n",alfa); 
     printf ("����s=%lf\n",s); }  
     long double RadianToAngle(long double alfa) 
     { 
          long double alfa1,alfa2; 
          alfa=alfa*180./PI; 
          alfa1=floor(alfa)+floor((alfa-floor(alfa))*60.)/100.; 
          alfa2=(alfa*60.-floor(alfa*60.))*0.006; 
          alfa1+=alfa2; 
          return(alfa1); 
     }  
     double JSFWJ(double vx,double vy) 
     { 
          double ml; 
          if (vx>0 && vy==0) 
                   ml=0; 
          else if (vx>0 && vy>0) 
                  ml=RadianToAngle(atan(vy/vx)); 
          else if (vx>0 && vy<0) 
                  ml=RadianToAngle(atan(vy/vx)+2*PI); 
          else if (vx<0 && vy==0) 
                  ml=RadianToAngle(PI); 
          else if (vx<0 && vy>0)  
                  ml=RadianToAngle(atan(vy/vx)+PI); 
          else if (vx<0 && vy<0) 
                  ml=RadianToAngle(atan(vy/vx)+PI); 
          else if (vx==0 && vy==0)  
               printf ("���������ͬһ����"); 
         else if (vx==0 && vy>0) 
               ml=RadianToAngle(PI/2); 
         else 
              ml=RadianToAngle(PI*3/2); 
         return ml; 
     }  
     double JSJL(double xa,double ya,double xb,double yb) 
     { 
                double s; 
                s=sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya)); 
                return s; 
     } 


  
