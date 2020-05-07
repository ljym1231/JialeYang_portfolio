//附合导线计算，其主要目的为求出每个点的最终坐标
//本程序仅支持盘左计算 
//因程序设计原因，可能无法自动验证某些数据是否超限，需要人为手动验证 
//因导线坐标计算表每行间可能存在未对齐现象，请在填写数据过程中每列数据依次向下誊写  
//抄写过程中因设计需要，可能会见到角度为0度0分0秒或长度为0米等，一律可以不写，但要空下其原有位置继续向下抄写
//本程序中，直接将观测值当作已知变量使用，若要使用其他数据，可直接在程序中改写新的数据 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 7//M值根据测站数具体更改，即代表有几横行，即有M-1个测站 
int main(void)
{
     
     //下面先进行角度部分的计算： 
     
     int i;
     double a[M][3],b[M][3],c[M][3];
     /*a[i][0],a[i][1],a[i][2]分别对应角度观测值的度，分，秒 
       b[i][0],b[i][1],b[i][2]分别对应改正后角值的度，分，秒 
       c[i][0],c[i][1],c[i][2]分别对应坐标方位角的度，分，秒 
     角度观测值为观测数据，无需计算，可当作已知值直接代入程序 
     已知角度观测值和坐标方位角值有：*/ 
     a[0][0]=0,a[0][1]=0,a[0][2]=0;
     a[1][0]=99,a[1][1]=1,a[1][2]=0;
     a[2][0]=167,a[2][1]=45,a[2][2]=36;
     a[3][0]=123,a[3][1]=11,a[3][2]=24;
     a[4][0]=189,a[4][1]=20,a[4][2]=35;
     a[5][0]=179,a[5][1]=59,a[5][2]=18;
     a[6][0]=129,a[6][1]=27,a[6][2]=24;
     c[0][0]=237,c[0][1]=59,c[0][2]=30;
     c[M-1][0]=46,c[M-1][1]=45,c[M-1][2]=24;
     
     
     
     printf("角度观测值依次为：\n");//依次输出所有角度观测值 
     for(i=1;i<M;i++)
     {
           
           printf("    %.f°%.f′%.f″\n",a[i][0],a[i][1],a[i][2]);
     }
     
     
     
     double sum_a_du=0,sum_a_fen=0,sum_a_miao=0;
     for(i=0;i<M;i++)//计算出所有角度观测值的和 
     {
           sum_a_miao=sum_a_miao+a[i][2];
           if(sum_a_miao>=60)
           {
                 sum_a_miao=sum_a_miao-60.;
                 sum_a_fen++;
                 if(sum_a_fen>=60)
                 {
                       sum_a_fen=sum_a_fen-60.;
                       sum_a_du++;
                 }
           }
           
           sum_a_fen=sum_a_fen+a[i][1];
           if(sum_a_fen>=60)
           {
                 sum_a_fen=sum_a_fen-60.;
                 sum_a_du++;
           }
           sum_a_du=sum_a_du+a[i][0];
     }
     //printf("角度观测值的和为：\n");
     //printf("    %.f°%.f′%.f″\n",sum_a_du,sum_a_fen,sum_a_miao);
     
     
     
     //改正角度，分配角度观测误差 ，使计算出的坐标方位角值与已知坐标方位角值相等：
     double zuobiaojiao;//zuobiaojiao为用测量数据计算出的最后一个点的坐标方位角值 
     double zuobiaojiao_du,zuobiaojiao_fen,zuobiaojiao_miao;
     double wucha;
     double wucha_du=0,wucha_fen=0,wucha_miao=0;
     
     zuobiaojiao_du=c[0][0]+sum_a_du;
     zuobiaojiao_fen=c[0][1]+sum_a_fen;
     zuobiaojiao_miao=c[0][2]+sum_a_miao;
     if(zuobiaojiao_miao>=60)
     {
           zuobiaojiao_miao=zuobiaojiao_miao-60.;
           zuobiaojiao_fen++;
           if(zuobiaojiao_fen>=60)
           {
                 zuobiaojiao_fen=zuobiaojiao_fen-60.;
                 zuobiaojiao_du++;
           }
     }
     if(zuobiaojiao_fen>=60)
     {
           zuobiaojiao_fen=zuobiaojiao_fen-60.;
           zuobiaojiao_du++;
     }
     zuobiaojiao_du=zuobiaojiao_du-(M-1)*180.; 
     printf("用测量结果计算出的坐标角：\n    %.f°%.f′%.f″\n",zuobiaojiao_du,zuobiaojiao_fen,zuobiaojiao_miao);
     
     wucha_du=zuobiaojiao_du-c[6][0];
     wucha_fen=zuobiaojiao_fen-c[6][1];
     wucha_miao=zuobiaojiao_miao-c[6][2];
     //printf("误差值为：\n    %.f°%.f′%.f″\n",wucha_du,wucha_fen,wucha_miao);
     if(wucha_du!=0)
     {
           printf("数据误差过大超限需重测\n");
           exit(1); 
     }
     if(wucha_fen!=0)
     {
           wucha_miao=wucha_fen*60.+wucha_miao;
           wucha_fen=0;
     }
     printf("误差值为：\n    %.f°%.f′%.f″\n",wucha_du,wucha_fen,wucha_miao);
     
     //printf("(友情提示：此处计算出的角度误差需自行手动验证，防止误差过大，本程序未涉及处理1度以上误差问题)\n");
     
     
     
     
     //计算出坐标改正值 ： 
     double gaizhengzhi; 
     gaizhengzhi=wucha_miao/(M-1);
     printf("角度改正值分别为：\n");
     for(i=1;i<M;i++)
     {
           if(wucha_miao<0)//当误差正负号不一样时，分配方法也不一样，因此需分类讨论 
           {
                 b[i][2]=a[i][2]+(-gaizhengzhi);
                 b[i][1]=a[i][1];
                 b[i][0]=a[i][0];
                 if(b[i][2]>60)
                 {
                       b[i][2]=b[i][2]-60.;
                       b[i][1]++;
                       if(b[i][1]>60)
                       {
                             b[i][1]=b[i][1]-60.;
                             b[i][0]++;
                       }
                 }
                 if(b[i][1]>60)
                 {
                       b[i][1]=b[i][1]-60.;
                       b[i][0]++;
                 }  
           }
           else
           {
                 b[i][2]=a[i][2]-gaizhengzhi;
                 b[i][1]=a[i][1];
                 b[i][0]=a[i][0];
                 if(b[i][2]>60)
                 {
                       b[i][2]=b[i][2]-60.;
                       b[i][1]++;
                       if(b[i][1]>60)
                       {
                             b[i][1]=b[i][1]-60.;
                             b[i][0]++;
                       }
                 }
                 if(b[i][1]>60)
                 {
                       b[i][1]=b[i][1]-60.;
                       b[i][0]++;
                 }
           }
           printf("    %.f°%.f′%.f″\n",b[i][0],b[i][1],b[i][2]);
     }
     
     if(wucha_miao<0)//此部分内容为了将误差完全分配，使结果更准确 
     {
           if((wucha_miao-gaizhengzhi*(M-1))!=0)
           {
                 if(M%2==1)
                 {
                       /*(调试程序，试验误差：) 
                         printf("    ###第%d个角度改正值应为：%.f°%.f′%.f″\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                         printf("\n@@@@  wucha_miao=%.0f,gaizhengzhi=%.0f,M-1=%d\n",wucha_miao,gaizhengzhi,M-1);
                         printf("\n@@@@@@@%.f°%.f′%.f″\n",b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                         printf("\n@@@@@@@++++ gaizhengzhi*(M-1)=   %d \n",((int)gaizhengzhi*(M-1)));
                         printf("\n@@@@@@@++++    %.d\n",(int)wucha_miao-((int)gaizhengzhi*(M-1)));*/
                       b[(M+1)/2][2]=b[(M+1)/2][2]-((int)wucha_miao-((int)gaizhengzhi*(M-1)));
                       printf("    第%d个角度改正值错误，应为：%.f°%.f′%.f″\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                 }
                 if(M%2==0)
                 {
                       b[M/2+1][2]=b[M/2+1][2]-((int)wucha_miao-((int)gaizhengzhi*(M-1)));
                       printf("    第%d个角度改正值错误，应为：%.f°%.f′%.f″\n",M/2+1,b[M/2+1][0],b[M/2+1][1],b[M/2+1][2]);
                 }
           }
     }
     if(wucha_miao>=0)
     {
           if((wucha_miao-gaizhengzhi*(M-1))!=0)//同上，此部分内容为了将误差完全分配，使结果更准确
           {
                 if(M%2==1)
                 {
                       b[(M+1)/2][2]=b[(M+1)/2][2]-((int)wucha_miao-((int)gaizhengzhi*(M-1)));
                       printf("    第%d个角度改正值错误，应为：%.f°%.f′%.f″\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                 }
                 if(M%2==0)
                 {
                       b[M/2+1][2]=b[M/2+1][2]-((int)wucha_miao-((int)gaizhengzhi*(M-1)));
                       printf("    第%d个角度改正值错误，应为：%.f°%.f′%.f″\n",M/2+1,b[M/2+1][0],b[M/2+1][1],b[M/2+1][2]);
                 }
           }
     }
     
     printf("坐标方位角分别为：\n");
     printf("    %.f°%.f′%.f″\n",c[0][0],c[0][1],c[0][2]);
     for(i=1;i<M;i++)
     {
           c[i][2]=(int)c[i-1][2]+(int)b[i][2];
           c[i][1]=(int)c[i-1][1]+(int)b[i][1];
           c[i][0]=(int)c[i-1][0]+(int)b[i][0]-180.;
           if(c[i][2]>=60)
           {
                 c[i][2]=c[i][2]-60.;
                 c[i][1]++;
                 if(c[i][1]>=60)
                 {
                       c[i][1]=c[i][1]-60.;
                       c[i][0]++;
                 }
           }
           if(c[i][1]>=60)
           {
                 c[i][1]=c[i][1]-60.;
                 c[i][0]++;
           }
           printf("    %.f°%.f′%.f″\n",c[i][0],c[i][1],c[i][2]);
     }
     
     
     printf("\n\n-----------------------------------------------------\n\n"); 
     
     
    
     
//下面开始进行与坐标有关的计算:
                               
     double d[M],e[M],f[M],g[M],h[M],j[M],k[M];//测量出的边长可看作已知数据来进行运算 
     double x[M],y[M];
     double PI=3.141592653;
     x[1]=2507.687,x[M-1]=2166.741;
     y[1]=1215.630,y[M-1]=1757.266;
     d[i]=0;
     d[1]=225.752,d[2]=139.033,d[3]=172.571,d[4]=100.068,d[5]=102.486;
     printf("边长依次为：（单位：米）\n");
     
     double sum_bianchang=0;
     for(i=1;i<M-1;i++)
     {
           printf("    %.3f\n",d[i]);
           sum_bianchang=sum_bianchang+d[i];
     }
     printf("边长的和为：（单位：米）\n    %.3f \n",sum_bianchang);
     
     printf("-----------------------------------------------------\n\n"); 
     
     double sum_x=0;
     double precicion = 0.0001;
     printf("x坐标增量计算值为：（单位：米）\n");//求x坐标增量计算值
     for(i=1;i<M-1;i++)
     {
           c[i][0]=((c[i][2]/3600+c[i][1]/60+c[i][0])/180)*PI;
           e[i]=cos(c[i][0]);
           f[i]=d[i]*e[i];
           printf("    %.3f\n",f[i]);
     }
     
     
     for(i=1;i<M-1;i++)//求x坐标增量和
     {
           f[i]=(int)(f[i]/precicion+0.005)*precicion;
           //printf(" @@@@   %.3f\n",f[i]);
           sum_x=sum_x+f[i];
     }
     printf("x坐标增量和为：（单位：米）\n    %.3f \n",sum_x);
     
     
     double wucha_x;//求x坐标增量误差
     wucha_x=sum_x-(x[M-1]-x[1]);
     printf("x坐标增量误差为：（单位：米）    \n    %.3f\n",wucha_x);
     
     
     double gaizhengzhi_xx[i];//求x坐标增量误差改正值
     double sum1=0;
     printf("x坐标增量误差改正值为：（单位：米）    \n");
     for(i=1;i<M-1;i++)
     {
           gaizhengzhi_xx[i]=-wucha_x*((int)d[i]/sum_bianchang);
           //@@@@@@@gaizhengzhi_xx[i]=(int)(gaizhengzhi_xx[i]/precicion+0.005)*precicion;
           printf("    %.3f\n",gaizhengzhi_xx[i]);
     }
     
     
     printf("x坐标增量改正后值为：（单位：米）    \n");//求x坐标增量改正后值 
     for(i=1;i<M-1;i++)
     {
           j[i]=f[i]+gaizhengzhi_xx[i];
           printf("    %.3f\n",j[i]);
     }
     
     
     printf("x坐标为：（单位：米）    \n");//得出最后结论，即x坐标
     printf("    %.3f \n",x[1]);
     for(i=2;i<M-1;i++)
     {
           x[i]=x[i-1]+j[i-1];
           printf("    %.3f \n",x[i]);
     }
     printf("    %.3f \n",x[M-1]);
     printf("-----------------------------------------------------\n\n"); 
     
     
     
     
     
     
     
     double sum_y=0;
     printf("y坐标增量计算值为：（单位：米）\n");//求y坐标增量计算值
     for(i=1;i<M-1;i++)
     {
           g[i]=sin(c[i][0]);
           h[i]=d[i]*g[i];
           printf("    %.3f\n",h[i]);
     }
     
     
     for(i=1;i<M-1;i++)//求y坐标增量和
     {
           h[i]=(int)(h[i]/precicion+0.005)*precicion;
           //printf(" @@@@   %.3f\n",h[i]);
           sum_y=sum_y+h[i];
           
     }
     printf("y坐标增量和为：（单位：米）\n    %.3f \n",sum_y);
     
     
     double wucha_y;//求y坐标增量误差
     wucha_y=sum_y-(y[M-1]-y[1]);
     printf("y坐标增量误差为：（单位：米）    \n    %.3f\n",wucha_y);
     
     
     double gaizhengzhi_yy[i];//求y坐标增量误差改正值
     printf("y坐标增量误差改正值为：（单位：米）    \n");
     for(i=1;i<M-1;i++)
     {
           gaizhengzhi_yy[i]=-wucha_y*((int)d[i]/sum_bianchang);
           printf("    %.3f\n",gaizhengzhi_yy[i]);
     }
     
     
     printf("y坐标增量改正后值为：（单位：米）    \n");//求y坐标增量改正后值 
     for(i=1;i<M-1;i++)
     {
           k[i]=h[i]+gaizhengzhi_yy[i];
           printf("    %.3f\n",k[i]);
     }
     
     
     printf("y坐标为：（单位：米）    \n");//得出最后结论，即y坐标
     printf("    %.3f \n",y[1]);
     for(i=2;i<M-1;i++)
     {
           y[i]=k[i-1]+y[i-1];
           printf("    %.3f \n",y[i]);
     }
     printf("    %.3f \n",y[M-1]);
    
     printf("\n\n\n    计算过程中部分求和、计算误差是否超限等过程因技术原因未给出，需程序使用者自行手动验证。带来不便，敬请谅解。\n\n\n");


     system("pause");
     return 0;   
}
