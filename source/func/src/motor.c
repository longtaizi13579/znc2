//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       motor.c
 *      ���ߣ�       snowwolf
 *    Email ��       snowwolf2012@qq.com
 *      ˵����       �����������
 *  �ο����ϣ�       ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 22:05
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#include "motor.h"



/********************************************************************
** ��������: void steer_init() 
** ��������: ���ö��ת��
** ��ڣ��Ƕ�ֵ
** ���ڣ�
** ˵��:  
*********************************************************************/
void motor_init()         
{    
    //��ʼ��FTM2_CH0���Ƶ��Ϊ100HZ,ռ�ձ�Ϊ13%��PWM ��FTM2_CH0��ӦPTA10��
    ftm_pwm_init(MOTOR_FTMN,MOTOR_FTMCH0,MOTOR_FREQ,MOTOR_INIT_VAL); 
    ftm_pwm_init(MOTOR_FTMN,MOTOR_FTMCH1,MOTOR_FREQ,MOTOR_INIT_VAL); 
#if MOTOR_DOUBLE
    ftm_pwm_init(MOTOR_FTMN,MOTOR_FTMCH2,MOTOR_FREQ,MOTOR_INIT_VAL); 
    ftm_pwm_init(MOTOR_FTMN,MOTOR_FTMCH3,MOTOR_FREQ,MOTOR_INIT_VAL); 
#endif
}
#if !MOTOR_DOUBLE
/********************************************************************
** ��������: PWMSetMotor
** ��������: �����ٶ�
** ��ڣ��ٶ�
** ���ڣ�
** ˵��:  
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
** ��������: motorCtrl
** ��������: �ٶȿ����㷨
** ��ڣ�
** ���ڣ�
** ˵��:  
*********************************************************************/
void motorCtrl()
{
    /***
  s32 speed_pwm;
    
    speed_pwm = 0;    //ȥ��warning
    
    //�Լ����ٶȿ����㷨
    
    
    
    PWMSetMotor(speed_pwm);
  ***/
}

#endif


#if MOTOR_DOUBLE
/********************************************************************
** ��������: PWMSetMotor
** ��������: �����ٶ�
** ��ڣ������ٶ�
** ���ڣ�
** ˵��:  
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
** ��������: motorCtrl
** ��������: �ٶȿ����㷨
** ��ڣ�
** ���ڣ�
** ˵��:  
*********************************************************************/
void motorCtrl()
{
  /***
    s32 speed_pwm;
    
    speed_pwm = 0;    //ȥ��warning
    
    //�Լ����ٶȿ����㷨
    
    
    
    PWMSetMotor2(speed_pwm,speed_pwm);
  ***/
}

#endif



