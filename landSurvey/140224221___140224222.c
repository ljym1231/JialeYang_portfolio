//���ϵ��߼��㣬����ҪĿ��Ϊ���ÿ�������������
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
     c[6][0]=46,c[6][1]=45,c[6][2]=24;
     
     
     
     printf("�Ƕȹ۲�ֵ����Ϊ��\n");//����������нǶȹ۲�ֵ 
     for(i=0;i<M;i++)
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
           if(sum_a_fen>=60)
           {
                 sum_a_fen=sum_a_fen-60.;
                 sum_a_du++;
           }
           sum_a_fen=sum_a_fen+a[i][1];
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
     if(wucha_miao<0)
     {
           wucha_miao=wucha_miao+60.;
     }
     if(wucha_fen<0)
     {
           wucha_miao=wucha_fen*60.+wucha_miao;
           wucha_fen++;
     }
     printf("���ֵΪ��\n    %.f��%.f��%.f��\n",wucha_du,wucha_fen,wucha_miao);
     printf("    (������ʾ���˴�������ĽǶ�����������ֶ���֤����ֹ�����󣬱�����δ�漰����1�������������)\n");
     
     
     
     
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
                       b[(M+1)/2][2]=b[(M+1)/2][2]+(-(wucha_miao-(gaizhengzhi*(M-1))));
                       printf("    ��%d���Ƕȸ���ֵ����ӦΪ��%.f��%.f��%.f��\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                 }
                 if(M%2==0)
                 {
                       b[M/2+1][2]=b[M/2+1][2]+(-(wucha_miao-(gaizhengzhi*(M-1))));
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
                       b[(M+1)/2][2]=b[(M+1)/2][2]-(wucha_miao-(gaizhengzhi*(M-1)));
                       printf("    ��%d���Ƕȸ���ֵ����ӦΪ��%.f��%.f��%.f��\n",(M+1)/2,b[(M+1)/2][0],b[(M+1)/2][1],b[(M+1)/2][2]);
                 }
                 if(M%2==0)
                 {
                       b[M/2+1][2]=b[M/2+1][2]-(wucha_miao-(gaizhengzhi*(M-1)));
                       printf("    ��%d���Ƕȸ���ֵ����ӦΪ��%.f��%.f��%.f��\n",M/2+1,b[M/2+1][0],b[M/2+1][1],b[M/2+1][2]);
                 }
           }
     }
     
     printf("���귽λ�Ƿֱ�Ϊ��\n");
     printf("    %.f��%.f��%.f��\n",c[0][0],c[0][1],c[0][2]);
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
           printf("    %.f��%.f��%.f��\n",c[i][0],c[i][1],c[i][2]);
     }
     
     
     
     
     
     
//���濪ʼ�����������йصļ���:
                               
     double d[M],e[M],f[M],g[M];//�������ı߳��ɿ�����֪�������������� 
     double PI=3.141592653f;
     d[i]=0;
     d[1]=225.752,d[2]=139.033,d[3]=172.571,d[4]=100.068,d[5]=102.486;
     printf("�߳�����Ϊ������λ���ף�\n");
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
