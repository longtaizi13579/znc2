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

#include "steer.h"



/********************************************************************
** �������� : void steer_init() 
** �������� : ���ö��ת��
** ���     ��
** ����     ��
** ˵��     :  ��ʼ��PWM����ռ�ձ�
*********************************************************************/
void steer_init()         
{
    //ASSERT_RST(STEER_INIT_VAL <= FTM_PRECISON,"���0���ֵ���ܳ���PWM����ֵ");        
    ftm_pwm_init(STEER_FTMN,STEER_FTMCH,STEER_FREQ,STEER_INIT_VAL); 
#if STEER_DOUBLE
    //ASSERT_RST(STEER_INIT_VAL1 <= FTM_PRECISON,"������ֵ���ܳ���PWM����ֵ");
    ftm_pwm_init(STEER_FTMN,STEER_FTMCH1,STEER_FREQ,STEER_INIT_VAL1); 
#endif
}

/********************************************************************
** ��������: void PWMSetSteer(int angle_pwm) 
** ��������: ���ö��ת��
** ��ڣ��Ƕ�ֵ
** ���ڣ�
** ˵��:  
*********************************************************************/
void PWMSetSteer(int angle_pwm)         
{
    //ռ�ձȲ��ܳ������ޣ���ֹ��ѹ��
    //ͬʱ��ֹ�������  
    //���������ʩ�Ǳ�Ҫ��
    if(angle_pwm < STEER_RIGHT)
         angle_pwm = STEER_RIGHT;
    if(angle_pwm > STEER_LEFT)
         angle_pwm = STEER_LEFT;
        
    ftm_pwm_duty(STEER_FTMN,STEER_FTMCH,angle_pwm);
}


/********************************************************************
** ��������: steerCtrl
** ��������: �ٶȿ����㷨
** ��ڣ�
** ���ڣ�
** ˵��:  
*********************************************************************/
void steerCtrl()
{
    /*
    int angle_pwm;
    angle_pwm = 0;    //ȥ��warning
    
    //�Լ��Ķ�������㷨
    
    
    PWMSetSteer(angle_pwm) ; 
    */ 
}


#if STEER_DOUBLE
void PWMSetSteer1(int angle_pwm)         
{
    //ռ�ձȲ��ܳ������ޣ���ֹ��ѹ��
    //ͬʱ��ֹ�������  
    //���������ʩ�Ǳ�Ҫ��
    if(angle_pwm < STEER_RIGHT1)
         angle_pwm = STEER_RIGHT1;
    if(angle_pwm > STEER_LEFT1)
         angle_pwm = STEER_LEFT1;
    
    
    ftm_pwm_duty(STEER_FTMN,STEER_FTMCH1,angle_pwm);
}


/********************************************************************
** ��������: steerCtrl
** ��������: �ٶȿ����㷨
** ��ڣ�
** ���ڣ�
** ˵��:  
*********************************************************************/
void steerCtrl1()
{
    /*
    int angle_pwm;
    angle_pwm = 0;    //ȥ��warning
    
    //�Լ��Ķ�������㷨
    
    
    
    PWMSetSteer1(angle_pwm) ;  
    */
}

#endif
