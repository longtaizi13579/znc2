//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       include.h
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#ifndef INCLUDE_H_
#define INCLUDE_H_

//ͨ��ͷ�ļ�
    #include    <stdio.h>                       //printf
    #include    <string.h>                      //memcpy
    #include    <stdlib.h>                      //malloc

//Cortex-M�ں�MCU�Ĵ���ͷ�ļ�
    #include "MK66F18.h"   //�Ĵ���ӳ��ͷ�ļ�
    #include "arm_math.h "
    #include "Systick.h"

//MCU�ڲ�ģ��������ͷ�ļ�
    #include "GPIO.h"
    #include "GPIO_Cfg.h"
    #include "PLL.h"
    #include "FTM.h"    
    #include "UART.h"
    #include "ADC.h"
    #include "PLL.h"    
    #include "PIT.h"
    #include "I2C.h"
    //#include "SPI.h"
    #include "DMA.h"
    #include "lptmr.h"    
    #include "RTC.h"
    #include "exti.h"

//�ж��������жϺ�������
    #include "vectors.h"
    #include "isr.h"

//�������ͼ��˿������ض���
    #include "common.h"

//�ⲿ�豸���Զ��幦��������ͷ�ļ�
#include "func.h"
#include "oled.h"
#include "motor.h"
#include "steer.h"
#include "u_iic.h"
#include "pid.h"
#include "LQMPU6050.h"
#include "LQMT9V034.h"
#endif