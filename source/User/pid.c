#include "pid.h"
//int begin_speed = 3000;//初始速度
int lasterror = 0;//上次误差
int accerror = 0;//累积误差
//方向环pid
float direction_p = 3;
float direction_i = 0;
float direction_d = 0;
//方向环控制,输入两个电感的测量值，输出两个轮子的PWM波
//750（右） -1020（左）
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