//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       RTC.h
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

/*
 * File:		rtc.h
 * Purpose:     Provide common rtc functions
 *
 * Notes:
 */

#ifndef __RTC_H__
#define __RTC_H__
#include "include.h"
/********************************************************************/
/******************************************************************************
* Macros
******************************************************************************/

#define RTC_OUTPUT_ENABLE		        1
#define RTC_INTERRUPT_ENABLE		    1
#define RTC_CLKSRC_EXTERNAL		        0
#define RTC_CLKSRC_1KHZ			        1
#define RTC_CLKSRC_IREF		            2
#define RTC_CLKSRC_BUS		            3
#define RTC_CLK_PRESCALER_128           1
#define RTC_CLK_PRESCALER_256           2
#define RTC_CLK_PRESCALER_512           3
#define RTC_CLK_PRESCALER_1024          4
#define RTC_CLK_PRESCALER_2048          5
#define RTC_CLK_PRESCALER_100           6
#define RTC_CLK_PRESCALER_1000          7

/******************************************************************************
* Types
******************************************************************************/

/*
 * Callback type
 */
/*!
 * @brief RTC Callback type.
 *
 */
typedef void (*RTC_CallbackType)(void);


/* RTC configuration structure 
 */  
/*!
 * @brief RTC configuration type.
 *
 */
typedef struct
{   
    uint16_t bReserved                  : 4;    /*!< reserved */     
    uint16_t bRTCOut                    : 1;    /*!< 1: RTCO pin is enable, 0: RTCO pin is disable */
    uint16_t bReserved1                 : 1;    /*!< reserved */ 
    uint16_t bInterruptEn               : 1;    /*!< 1: RTC interrupt is enable, 0: RTC interrupt is disable */
    uint16_t bFlag                      : 1;    /*!< 1: RTC flag is set, 0: RTC flag is not set */   
    uint16_t bClockPresaler             : 3;    /*!< 1: RTC presclaer, from 0x0 to 0x7 */    
    uint16_t bReserved2                 : 3;    /*!< reserved */ 
    uint16_t bClockSource               : 2;    /*!< RTC clock source selection from 0x0 to 0x3 */
    uint16_t u16ModuloValue                ;    /*!< 16-bit rtc modulo value */
} RTC_ConfigType, *RTC_ConfigPtr; 




void rtc_init(uint32 seconds, uint32 alarm, uint8 c_interval, uint8 c_value, uint8 interrupt);      
void rtc_isr(void);

/********************************************************************/

#endif /* __RTC_H__ */
