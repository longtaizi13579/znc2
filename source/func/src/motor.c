//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       motor.c
 *      作者：       snowwolf
 *    Email ：       snowwolf2012@qq.com
 *      说明：       电机驱动函数
 *  参考资料：       无
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 22:05
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#include "motor.h"



/********************************************************************
** 函数名称: void steer_init() 
** 功能描述: 设置舵机转向
** 入口：角度值
** 出口：
** 说明:  
*********************************************************************/
void motor_init()         
{    
    //初始化FTM2_CH0输出频率为100HZ,占空比为13%的PWM ：FTM2_CH0对应PTA10口
    ftm_pwm_init(MOTOR_FTMN,MOTOR_FTMCH0,MOTOR_FREQ,MOTOR_INIT_VAL); 
    ftm_pwm_init(MOTOR_FTMN,MOTOR_FTMCH1,MOTOR_FREQ,MOTOR_INIT_VAL); 
#if MOTOR_DOUBLE
    ftm_pwm_init(MOTOR_FTMN,MOTOR_FTMCH2,MOTOR_FREQ,MOTOR_INIT_VAL); 
    ftm_pwm_init(MOTOR_FTMN,MOTOR_FTMCH3,MOTOR_FREQ,MOTOR_INIT_VAL); 
#endif
}
#if !MOTOR_DOUBLE
/********************************************************************
** 函数名称: PWMSetMotor
** 功能描述: 设置速度
** 入口：速度
** 出口：
** 说明:  
*********************************************************************/
void PWMSetMotor(s32 speed_pwm)         
{
    if(speed_pwm < MOTOR_MIN)
    {
      speed_pwm = MOTOR_MIN;
    }
    if(speed_pwm > MOTOR_MAX)
    {
      speed_pwm = MOTOR_MAX;
    }
    
    if(speed_pwm > 0) 
    {
        ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH0,(u32)speed_pwm);
        ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH1,0);
    } 
    else 
    {
       speed_pwm = -speed_pwm;
       ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH1,(u32)speed_pwm);
       ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH0,0);
    }
}

/********************************************************************
** 函数名称: motorCtrl
** 功能描述: 速度控制算法
** 入口：
** 出口：
** 说明:  
*********************************************************************/
void motorCtrl()
{
    /***
  s32 speed_pwm;
    
    speed_pwm = 0;    //去除warning
    
    //自己的速度控制算法
    
    
    
    PWMSetMotor(speed_pwm);
  ***/
}

#endif


#if MOTOR_DOUBLE
/********************************************************************
** 函数名称: PWMSetMotor
** 功能描述: 设置速度
** 入口：左右速度
** 出口：
** 说明:  
*********************************************************************/
void PWMSetMotor2(s32 speed_pwmL,s32 speed_pwmR)         
{
    if(speed_pwmL < MOTOR_MIN)
    {
      speed_pwmL = MOTOR_MIN;
    }
    if(speed_pwmL > MOTOR_MAX)
    {
      speed_pwmL = MOTOR_MAX;
    }
    
    if(speed_pwmR < MOTOR_MIN)
    {
      speed_pwmR = MOTOR_MIN;
    }
    if(speed_pwmR > MOTOR_MAX)
    {
      speed_pwmR = MOTOR_MAX;
    }
    
    if(speed_pwmL > 0) 
    {
        ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH0,(u32)speed_pwmL);
        ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH1,0);
    } 
    else 
    {
       speed_pwmL = -speed_pwmL;
       ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH1,(u32)speed_pwmL);
       ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH0,0);
    }
    
    if(speed_pwmR > 0) 
    {
        ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH2,(u32)speed_pwmR);
        ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH3,0);
    } 
    else 
    {
       speed_pwmR = -speed_pwmR;
       ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH3,(u32)speed_pwmR);
       ftm_pwm_duty(MOTOR_FTMN,MOTOR_FTMCH2,0);
    }
}

/********************************************************************
** 函数名称: motorCtrl
** 功能描述: 速度控制算法
** 入口：
** 出口：
** 说明:  
*********************************************************************/
void motorCtrl()
{
  /***
    s32 speed_pwm;
    
    speed_pwm = 0;    //去除warning
    
    //自己的速度控制算法
    
    
    
    PWMSetMotor2(speed_pwm,speed_pwm);
  ***/
}

#endif



