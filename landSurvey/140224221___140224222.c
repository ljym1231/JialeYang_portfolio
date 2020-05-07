//附合导线计算，其主要目的为求出每个点的最终坐标
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
     c[6][0]=46,c[6][1]=45,c[6][2]=24;
     
     
     
     printf("角度观测值依次为：\n");//依次输出所有角度观测值 
     for(i=0;i<M;i++)
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
           if(sum_a_fen>=60)
           {
                 sum_a_fen=sum_a_fen-60.;
                 sum_a_du++;
           }
           sum_a_fen=sum_a_fen+a[i][1];
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
     if(wucha_miao<0)
     {
           wucha_miao=wucha_miao+60.;
     }
     if(wucha_fen<0)
     {
           wucha_miao=wucha_fen*60.+wucha_miao;
           wucha_fen++;
     }
     printf("误差值为：\n    %.f°%.f′%.f″\n",wucha_du,wucha_fen,wucha_miao);
     printf("    (友情提示：此处计算出的角度误差需自行手动验证，防止误差过大，本程序未涉及处理1度以上误差问题)\n");
     
     
     
     
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
                       b[(M+1)/2][2]=b[(M+1)/2][2]+(-(wucha_miao-(gaizhengzhi*(M-1))));
                       printf("    第%d个角度改正值错误，应为：%.f°%.f′%.f″\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                 }
                 if(M%2==0)
                 {
                       b[M/2+1][2]=b[M/2+1][2]+(-(wucha_miao-(gaizhengzhi*(M-1))));
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
                       b[(M+1)/2][2]=b[(M+1)/2][2]-(wucha_miao-(gaizhengzhi*(M-1)));
                       printf("    第%d个角度改正值错误，应为：%.f°%.f′%.f″\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                 }
                 if(M%2==0)
                 {
                       b[M/2+1][2]=b[M/2+1][2]-(wucha_miao-(gaizhengzhi*(M-1)));
                       printf("    第%d个角度改正值错误，应为：%.f°%.f′%.f″\n",M/2+1,b[M/2+1][0],b[M/2+1][1],b[M/2+1][2]);
                 }
           }
     }
     
     printf("坐标方位角分别为：\n");
     printf("    %.f°%.f′%.f″\n",c[0][0],c[0][1],c[0][2]);
     for(i=1;i<M;i++)
     {
           c[i][2]=c[i-1][2]+b[i][2];
           c[i][1]=c[i-1][1]+b[i][1];
           c[i][0]=c[i-1][0]+b[i][0]-180.;
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
     
     
     
     
     
     
//下面开始进行与坐标有关的计算:
                               
     double d[M],e[M],f[M],g[M];//测量出的边长可看作已知数据来进行运算 
     double PI=3.141592653f;
     d[i]=0;
     d[1]=225.752,d[2]=139.033,d[3]=172.571,d[4]=100.068,d[5]=102.486;
     printf("边长依次为：（单位：米）\n");
     for(i=0;i<M-1;i++)
     {
           printf("    %.3f\n",d[i]);
     }
     for(i=0;i<M-1;i++)
     {
           c[i][0]=((c[i][2]/3600+c[i][1]/60+c[i][0])/180)*PI;
           e[i]=double cos(double c[i][0]);
           f[i]=d[i]*e[i];
     }
     printf("    %.3f\n",e[i]);


     system("pause");
     return 0;   
}
