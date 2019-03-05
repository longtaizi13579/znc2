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

#ifndef __MOTOR_H__
#define __MOTOR_H__

#define MOTOR_DOUBLE 1   //为摄像头组两路控制预留

#include "common.h"
#include "ftm.h"


#define MOTOR_MAX    9600
#define MOTOR_MIN    -9600


#define  MOTOR_FTMN       FTM0            
#define  MOTOR_FTMCH0     FTM_CH0           //PTC1
#define  MOTOR_FTMCH1     FTM_CH1           //PTC2 
 

#define  MOTOR_FREQ 16000           //电机频率   16k
#define  MOTOR_INIT_VAL 0           //电机初始值，精度1/10000  即0/10000 0%


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
    
    //#define  MOTOR_FREQ 16000           //电机频率   16k
    //#define  MOTOR_INIT_VAL 0           //电机初始值，精度1/10000  即0/10000 0%
        
    //void motor_init();
    
    void PWMSetMotor2(s32 speed_pwmL,s32 speed_pwmR);
#endif 

    
    void motorCtrl();
      
#endif