//���ϵ��߼��㣬����ҪĿ��Ϊ���ÿ�������������
//�������֧��������� 
//��������ԭ�򣬿����޷��Զ���֤ĳЩ�����Ƿ��ޣ���Ҫ��Ϊ�ֶ���֤ 
//������������ÿ�м���ܴ���δ��������������д���ݹ�����ÿ����������������д  
//��д�������������Ҫ�����ܻ�����Ƕ�Ϊ0��0��0��򳤶�Ϊ0�׵ȣ�һ�ɿ��Բ�д����Ҫ������ԭ��λ�ü������³�д
//�������У�ֱ�ӽ��۲�ֵ������֪����ʹ�ã���Ҫʹ���������ݣ���ֱ���ڳ����и�д�µ����� 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 7//Mֵ���ݲ�վ��������ģ��������м����У�����M-1����վ 
int main(void)
{
     
     //�����Ƚ��нǶȲ��ֵļ��㣺 
     
     int i;
     double a[M][3],b[M][3],c[M][3];
     /*a[i][0],a[i][1],a[i][2]�ֱ��Ӧ�Ƕȹ۲�ֵ�Ķȣ��֣��� 
       b[i][0],b[i][1],b[i][2]�ֱ��Ӧ�������ֵ�Ķȣ��֣��� 
       c[i][0],c[i][1],c[i][2]�ֱ��Ӧ���귽λ�ǵĶȣ��֣��� 
     �Ƕȹ۲�ֵΪ�۲����ݣ�������㣬�ɵ�����ֱֵ֪�Ӵ������ 
     ��֪�Ƕȹ۲�ֵ�����귽λ��ֵ�У�*/ 
     a[0][0]=0,a[0][1]=0,a[0][2]=0;
     a[1][0]=99,a[1][1]=1,a[1][2]=0;
     a[2][0]=167,a[2][1]=45,a[2][2]=36;
     a[3][0]=123,a[3][1]=11,a[3][2]=24;
     a[4][0]=189,a[4][1]=20,a[4][2]=35;
     a[5][0]=179,a[5][1]=59,a[5][2]=18;
     a[6][0]=129,a[6][1]=27,a[6][2]=24;
     c[0][0]=237,c[0][1]=59,c[0][2]=30;
     c[M-1][0]=46,c[M-1][1]=45,c[M-1][2]=24;
     
     
     
     printf("�Ƕȹ۲�ֵ����Ϊ��\n");//����������нǶȹ۲�ֵ 
     for(i=1;i<M;i++)
     {
           
           printf("    %.f��%.f��%.f��\n",a[i][0],a[i][1],a[i][2]);
     }
     
     
     
     double sum_a_du=0,sum_a_fen=0,sum_a_miao=0;
     for(i=0;i<M;i++)//��������нǶȹ۲�ֵ�ĺ� 
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
     //printf("�Ƕȹ۲�ֵ�ĺ�Ϊ��\n");
     //printf("    %.f��%.f��%.f��\n",sum_a_du,sum_a_fen,sum_a_miao);
     
     
     
     //�����Ƕȣ�����Ƕȹ۲���� ��ʹ����������귽λ��ֵ����֪���귽λ��ֵ��ȣ�
     double zuobiaojiao;//zuobiaojiaoΪ�ò������ݼ���������һ��������귽λ��ֵ 
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
     printf("�ò�����������������ǣ�\n    %.f��%.f��%.f��\n",zuobiaojiao_du,zuobiaojiao_fen,zuobiaojiao_miao);
     
     wucha_du=zuobiaojiao_du-c[6][0];
     wucha_fen=zuobiaojiao_fen-c[6][1];
     wucha_miao=zuobiaojiao_miao-c[6][2];
     //printf("���ֵΪ��\n    %.f��%.f��%.f��\n",wucha_du,wucha_fen,wucha_miao);
     if(wucha_du!=0)
     {
           printf("���������������ز�\n");
           exit(1); 
     }
     if(wucha_fen!=0)
     {
           wucha_miao=wucha_fen*60.+wucha_miao;
           wucha_fen=0;
     }
     printf("���ֵΪ��\n    %.f��%.f��%.f��\n",wucha_du,wucha_fen,wucha_miao);
     
     //printf("(������ʾ���˴�������ĽǶ�����������ֶ���֤����ֹ�����󣬱�����δ�漰����1�������������)\n");
     
     
     
     
     //������������ֵ �� 
     double gaizhengzhi; 
     gaizhengzhi=wucha_miao/(M-1);
     printf("�Ƕȸ���ֵ�ֱ�Ϊ��\n");
     for(i=1;i<M;i++)
     {
           if(wucha_miao<0)//����������Ų�һ��ʱ�����䷽��Ҳ��һ���������������� 
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
           printf("    %.f��%.f��%.f��\n",b[i][0],b[i][1],b[i][2]);
     }
     
     if(wucha_miao<0)//�˲�������Ϊ�˽������ȫ���䣬ʹ�����׼ȷ 
     {
           if((wucha_miao-gaizhengzhi*(M-1))!=0)
           {
                 if(M%2==1)
                 {
                       /*(���Գ���������) 
                         printf("    ###��%d���Ƕȸ���ֵӦΪ��%.f��%.f��%.f��\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                         printf("\n@@@@  wucha_miao=%.0f,gaizhengzhi=%.0f,M-1=%d\n",wucha_miao,gaizhengzhi,M-1);
                         printf("\n@@@@@@@%.f��%.f��%.f��\n",b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                         printf("\n@@@@@@@++++ gaizhengzhi*(M-1)=   %d \n",((int)gaizhengzhi*(M-1)));
                         printf("\n@@@@@@@++++    %.d\n",(int)wucha_miao-((int)gaizhengzhi*(M-1)));*/
                       b[(M+1)/2][2]=b[(M+1)/2][2]-((int)wucha_miao-((int)gaizhengzhi*(M-1)));
                       printf("    ��%d���Ƕȸ���ֵ����ӦΪ��%.f��%.f��%.f��\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                 }
                 if(M%2==0)
                 {
                       b[M/2+1][2]=b[M/2+1][2]-((int)wucha_miao-((int)gaizhengzhi*(M-1)));
                       printf("    ��%d���Ƕȸ���ֵ����ӦΪ��%.f��%.f��%.f��\n",M/2+1,b[M/2+1][0],b[M/2+1][1],b[M/2+1][2]);
                 }
           }
     }
     if(wucha_miao>=0)
     {
           if((wucha_miao-gaizhengzhi*(M-1))!=0)//ͬ�ϣ��˲�������Ϊ�˽������ȫ���䣬ʹ�����׼ȷ
           {
                 if(M%2==1)
                 {
                       b[(M+1)/2][2]=b[(M+1)/2][2]-((int)wucha_miao-((int)gaizhengzhi*(M-1)));
                       printf("    ��%d���Ƕȸ���ֵ����ӦΪ��%.f��%.f��%.f��\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                 }
                 if(M%2==0)
                 {
                       b[M/2+1][2]=b[M/2+1][2]-((int)wucha_miao-((int)gaizhengzhi*(M-1)));
                       printf("    ��%d���Ƕȸ���ֵ����ӦΪ��%.f��%.f��%.f��\n",M/2+1,b[M/2+1][0],b[M/2+1][1],b[M/2+1][2]);
                 }
           }
     }
     
     printf("���귽λ�Ƿֱ�Ϊ��\n");
     printf("    %.f��%.f��%.f��\n",c[0][0],c[0][1],c[0][2]);
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
           printf("    %.f��%.f��%.f��\n",c[i][0],c[i][1],c[i][2]);
     }
     
     
     printf("\n\n-----------------------------------------------------\n\n"); 
     
     
    
     
//���濪ʼ�����������йصļ���:
                               
     double d[M],e[M],f[M],g[M],h[M],j[M],k[M];//�������ı߳��ɿ�����֪�������������� 
     double x[M],y[M];
     double PI=3.141592653;
     x[1]=2507.687,x[M-1]=2166.741;
     y[1]=1215.630,y[M-1]=1757.266;
     d[i]=0;
     d[1]=225.752,d[2]=139.033,d[3]=172.571,d[4]=100.068,d[5]=102.486;
     printf("�߳�����Ϊ������λ���ף�\n");
     
     double sum_bianchang=0;
     for(i=1;i<M-1;i++)
     {
           printf("    %.3f\n",d[i]);
           sum_bianchang=sum_bianchang+d[i];
     }
     printf("�߳��ĺ�Ϊ������λ���ף�\n    %.3f \n",sum_bianchang);
     
     printf("-----------------------------------------------------\n\n"); 
     
     double sum_x=0;
     double precicion = 0.0001;
     printf("x������������ֵΪ������λ���ף�\n");//��x������������ֵ
     for(i=1;i<M-1;i++)
     {
           c[i][0]=((c[i][2]/3600+c[i][1]/60+c[i][0])/180)*PI;
           e[i]=cos(c[i][0]);
           f[i]=d[i]*e[i];
           printf("    %.3f\n",f[i]);
     }
     
     
     for(i=1;i<M-1;i++)//��x����������
     {
           f[i]=(int)(f[i]/precicion+0.005)*precicion;
           //printf(" @@@@   %.3f\n",f[i]);
           sum_x=sum_x+f[i];
     }
     printf("x����������Ϊ������λ���ף�\n    %.3f \n",sum_x);
     
     
     double wucha_x;//��x�����������
     wucha_x=sum_x-(x[M-1]-x[1]);
     printf("x�����������Ϊ������λ���ף�    \n    %.3f\n",wucha_x);
     
     
     double gaizhengzhi_xx[i];//��x��������������ֵ
     double sum1=0;
     printf("x��������������ֵΪ������λ���ף�    \n");
     for(i=1;i<M-1;i++)
     {
           gaizhengzhi_xx[i]=-wucha_x*((int)d[i]/sum_bianchang);
           //@@@@@@@gaizhengzhi_xx[i]=(int)(gaizhengzhi_xx[i]/precicion+0.005)*precicion;
           printf("    %.3f\n",gaizhengzhi_xx[i]);
     }
     
     
     printf("x��������������ֵΪ������λ���ף�    \n");//��x��������������ֵ 
     for(i=1;i<M-1;i++)
     {
           j[i]=f[i]+gaizhengzhi_xx[i];
           printf("    %.3f\n",j[i]);
     }
     
     
     printf("x����Ϊ������λ���ף�    \n");//�ó������ۣ���x����
     printf("    %.3f \n",x[1]);
     for(i=2;i<M-1;i++)
     {
           x[i]=x[i-1]+j[i-1];
           printf("    %.3f \n",x[i]);
     }
     printf("    %.3f \n",x[M-1]);
     printf("-----------------------------------------------------\n\n"); 
     
     
     
     
     
     
     
     double sum_y=0;
     printf("y������������ֵΪ������λ���ף�\n");//��y������������ֵ
     for(i=1;i<M-1;i++)
     {
           g[i]=sin(c[i][0]);
           h[i]=d[i]*g[i];
           printf("    %.3f\n",h[i]);
     }
     
     
     for(i=1;i<M-1;i++)//��y����������
     {
           h[i]=(int)(h[i]/precicion+0.005)*precicion;
           //printf(" @@@@   %.3f\n",h[i]);
           sum_y=sum_y+h[i];
           
     }
     printf("y����������Ϊ������λ���ף�\n    %.3f \n",sum_y);
     
     
     double wucha_y;//��y�����������
     wucha_y=sum_y-(y[M-1]-y[1]);
     printf("y�����������Ϊ������λ���ף�    \n    %.3f\n",wucha_y);
     
     
     double gaizhengzhi_yy[i];//��y��������������ֵ
     printf("y��������������ֵΪ������λ���ף�    \n");
     for(i=1;i<M-1;i++)
     {
           gaizhengzhi_yy[i]=-wucha_y*((int)d[i]/sum_bianchang);
           printf("    %.3f\n",gaizhengzhi_yy[i]);
     }
     
     
     printf("y��������������ֵΪ������λ���ף�    \n");//��y��������������ֵ 
     for(i=1;i<M-1;i++)
     {
           k[i]=h[i]+gaizhengzhi_yy[i];
           printf("    %.3f\n",k[i]);
     }
     
     
     printf("y����Ϊ������λ���ף�    \n");//�ó������ۣ���y����
     printf("    %.3f \n",y[1]);
     for(i=2;i<M-1;i++)
     {
           y[i]=k[i-1]+y[i-1];
           printf("    %.3f \n",y[i]);
     }
     printf("    %.3f \n",y[M-1]);
    
     printf("\n\n\n    ��������в�����͡���������Ƿ��޵ȹ�������ԭ��δ�����������ʹ���������ֶ���֤���������㣬�����½⡣\n\n\n");


     system("pause");
     return 0;   
}
