#include "pid.h"
//int begin_speed = 3000;//��ʼ�ٶ�
int lasterror = 0;//�ϴ����
int accerror = 0;//�ۻ����
//����pid
float direction_p = 3;
float direction_i = 0;
float direction_d = 0;
//���򻷿���,����������еĲ���ֵ������������ӵ�PWM��
//750���ң� -1020����
void direction_control(int leftvalue , int rightvalue)
{
   int leftspeed,rightspeed;
   int duty = 885;
   int error = leftvalue - rightvalue ;
   accerror = accerror + error;
   float pid = (float)(direction_p * error + direction_i * accerror + direction_d *(error - lasterror));
   lasterror = error;
   ftm_pwm_duty(FTM3, FTM_CH1,duty + pid);
}