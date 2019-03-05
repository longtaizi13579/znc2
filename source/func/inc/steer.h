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

#ifndef __STEER_H__
#define __STEER_H__

#include "common.h"
#include "ftm.h"


//Ϊ˫���Ԥ��������ͷ��͵���������� 0
#define STEER_DOUBLE 0


#define STEER_LEFT      2000     //����ڽ�����  �����ֵ�����ڲ��Եģ���Ҹ����Լ��Ķ������
#define STEER_MIDDLE    1500     //����ڽ���ֵ
#define STEER_RIGHT      1000   //����ڽ��Ҽ���  


#define  STEER_FTMN     FTM1
#define  STEER_FTMCH    FTM_CH1     //FTM1_CH1��ӦPTA13��
#define  STEER_FREQ     100    //���Ƶ��   ����һ��FTMģ��ֻ�����һ��Ƶ�ʣ�                               //�����������Ҳֻ����һ��Ƶ�� ����ͳһ100Hz
#define  STEER_INIT_VAL 1200   //�����ʼֵ������1/10000  ��1200/10000  = 12%

void steer_init();

void PWMSetSteer(int angle_pwm);

void steerCtrl();

#if STEER_DOUBLE
    #define STEER_LEFT1      2000     //����ڽ�����
    #define STEER_MIDDLE1    1500     //����ڽ���ֵ
    #define STEER_RIGHT1     1000      //����ڽ��Ҽ���
    
    
    //#define  STEER_FTMN     FTM1   //�����������
    #define  STEER_FTMCH1    FTM_CH0     //FTM1_CH0��ӦPTA13��
    //#define  STEER_FREQ     100    //���Ƶ��   ����һ��FTMģ��ֻ�����һ��Ƶ�ʣ�                               //�����������Ҳֻ����һ��Ƶ�� ����ͳһ100Hz
    #define  STEER_INIT_VAL1 1200   //�����ʼֵ������1/10000  ��1200/10000  = 12%
    void PWMSetSteer1(int angle_pwm);
    void steerCtrl1();
#endif





#endif