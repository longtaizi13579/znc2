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

#ifndef __MOTOR_H__
#define __MOTOR_H__

#define MOTOR_DOUBLE 1   //Ϊ����ͷ����·����Ԥ��

#include "common.h"
#include "ftm.h"


#define MOTOR_MAX    9600
#define MOTOR_MIN    -9600


#define  MOTOR_FTMN       FTM0            
#define  MOTOR_FTMCH0     FTM_CH0           //PTC1
#define  MOTOR_FTMCH1     FTM_CH1           //PTC2 
 

#define  MOTOR_FREQ 16000           //���Ƶ��   16k
#define  MOTOR_INIT_VAL 0           //�����ʼֵ������1/10000  ��0/10000 0%


void motor_init();

#if !MOTOR_DOUBLE
    void PWMSetMotor(s32 speed_pwm);
#endif

#if MOTOR_DOUBLE
    //#define MOTOR_MAX    10000
    //#define MOTOR_MIN    -10000
    
    //#define  MOTOR_FTMN       FTM0            
    #define  MOTOR_FTMCH2     FTM_CH2           //PTC3
    #define  MOTOR_FTMCH3     FTM_CH3           //PTC4 
    
    //#define  MOTOR_FREQ 16000           //���Ƶ��   16k
    //#define  MOTOR_INIT_VAL 0           //�����ʼֵ������1/10000  ��0/10000 0%
        
    //void motor_init();
    
    void PWMSetMotor2(s32 speed_pwmL,s32 speed_pwmR);
#endif 

    
    void motorCtrl();
      
#endif