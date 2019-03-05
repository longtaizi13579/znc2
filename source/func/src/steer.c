//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       motor.c
 *      作者：       snowwolf
 *    Email ：       snowwolf2012@qq.com
 *      说明：       舵机驱动函数
 *  参考资料：       无
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 22:05
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#include "steer.h"



/********************************************************************
** 函数名称 : void steer_init() 
** 功能描述 : 设置舵机转向
** 入口     ：
** 出口     ：
** 说明     :  初始化PWM波及占空比
*********************************************************************/
void steer_init()         
{
    //ASSERT_RST(STEER_INIT_VAL <= FTM_PRECISON,"舵机0最大值不能超过PWM精度值");        
    ftm_pwm_init(STEER_FTMN,STEER_FTMCH,STEER_FREQ,STEER_INIT_VAL); 
#if STEER_DOUBLE
    //ASSERT_RST(STEER_INIT_VAL1 <= FTM_PRECISON,"舵机最大值不能超过PWM精度值");
    ftm_pwm_init(STEER_FTMN,STEER_FTMCH1,STEER_FREQ,STEER_INIT_VAL1); 
#endif
}

/********************************************************************
** 函数名称: void PWMSetSteer(int angle_pwm) 
** 功能描述: 设置舵机转向
** 入口：角度值
** 出口：
** 说明:  
*********************************************************************/
void PWMSetSteer(int angle_pwm)         
{
    //占空比不能超过上限（防止过压）
    //同时防止方向打死  
    //这个保护措施是必要的
    if(angle_pwm < STEER_RIGHT)
         angle_pwm = STEER_RIGHT;
    if(angle_pwm > STEER_LEFT)
         angle_pwm = STEER_LEFT;
        
    ftm_pwm_duty(STEER_FTMN,STEER_FTMCH,angle_pwm);
}


/********************************************************************
** 函数名称: steerCtrl
** 功能描述: 速度控制算法
** 入口：
** 出口：
** 说明:  
*********************************************************************/
void steerCtrl()
{
    /*
    int angle_pwm;
    angle_pwm = 0;    //去除warning
    
    //自己的舵机控制算法
    
    
    PWMSetSteer(angle_pwm) ; 
    */ 
}


#if STEER_DOUBLE
void PWMSetSteer1(int angle_pwm)         
{
    //占空比不能超过上限（防止过压）
    //同时防止方向打死  
    //这个保护措施是必要的
    if(angle_pwm < STEER_RIGHT1)
         angle_pwm = STEER_RIGHT1;
    if(angle_pwm > STEER_LEFT1)
         angle_pwm = STEER_LEFT1;
    
    
    ftm_pwm_duty(STEER_FTMN,STEER_FTMCH1,angle_pwm);
}


/********************************************************************
** 函数名称: steerCtrl
** 功能描述: 速度控制算法
** 入口：
** 出口：
** 说明:  
*********************************************************************/
void steerCtrl1()
{
    /*
    int angle_pwm;
    angle_pwm = 0;    //去除warning
    
    //自己的舵机控制算法
    
    
    
    PWMSetSteer1(angle_pwm) ;  
    */
}

#endif
