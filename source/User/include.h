//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       include.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#ifndef INCLUDE_H_
#define INCLUDE_H_

//通用头文件
    #include    <stdio.h>                       //printf
    #include    <string.h>                      //memcpy
    #include    <stdlib.h>                      //malloc

//Cortex-M内核MCU寄存器头文件
    #include "MK66F18.h"   //寄存器映像头文件
    #include "arm_math.h "
    #include "Systick.h"

//MCU内部模块驱动的头文件
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

//中断向量表及中断函数声明
    #include "vectors.h"
    #include "isr.h"

//数据类型及端口名称重定义
    #include "common.h"

//外部设备及自定义功能驱动的头文件
#include "func.h"
#include "oled.h"
#include "motor.h"
#include "steer.h"
#include "u_iic.h"
#include "pid.h"
#include "LQMPU6050.h"
#include "LQMT9V034.h"
#endif