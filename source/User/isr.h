//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       isr.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#ifndef __ISR_H
#define __ISR_H 

#include "include.h"

/* Example */
/*
#undef  VECTOR_036
#define VECTOR_036 RTC_Isr

// ISR(s) are defined in your project directory.
extern void RTC_Isr(void);
*/
#undef VECTOR_047
#define VECTOR_047      UART0_ISR// 0x0000_00BC 47    31     UART0             Single interrupt vector for UART status sources
#undef VECTOR_049
#define VECTOR_049      UART1_ISR// 0x0000_00C4 49    33     UART1             Single interrupt vector for UART status sources
#undef VECTOR_051
#define VECTOR_051      UART2_ISR// 0x0000_00CC 51    35     UART2             Single interrupt vector for UART status sources
#undef VECTOR_053
#define VECTOR_053      UART3_ISR// 0x0000_00D4 53    37     UART3             Single interrupt vector for UART status sources
#undef VECTOR_082
#define VECTOR_082      UART4_ISR// 0x0000_0148 82    66     UART4                  Single interrupt vector for UART status sources

#undef VECTOR_075
#define VECTOR_075      PORTA_ISR // 0x0000_012C 75    59     Port control module    Pin detect (Port A)
#undef VECTOR_076
#define VECTOR_076      PORTB_ISR // 0x0000_0130 76    60     Port control module    Pin detect (Port B)
#undef VECTOR_077
#define VECTOR_077      PORTC_ISR // 0x0000_0134 77    61     Port control module    Pin detect (Port C)
#undef VECTOR_078
#define VECTOR_078      PORTD_ISR // 0x0000_0138 78    62     Port control module    Pin detect (Port D)
#undef VECTOR_079
#define VECTOR_079      PORTE_ISR // 0x0000_013C 79    63     Port control module    Pin detect (Port E)

#undef VECTOR_074
#define VECTOR_074	LPTMR_ISR
#undef VECTOR_016
#define VECTOR_016	DMA0_ISR
#undef VECTOR_058
#define VECTOR_058	FTM0_ISR
#undef VECTOR_064
#define VECTOR_064	PIT0_ISR

extern void UART0_ISR(void);
extern void UART1_ISR(void);
extern void UART2_ISR(void);
extern void UART3_ISR(void);
extern void UART4_ISR(void);
extern void PORTA_ISR(void);
extern void PORTB_ISR(void);
extern void PORTC_ISR(void);
extern void PORTD_ISR(void);
extern void PORTE_ISR(void);
extern void LPTMR_ISR();	//LPTMR中断服务函数
extern void DMA0_ISR();	//DMA0中断服务函数
extern void FTM0_ISR();	//FTM0中断服务函数
extern void PIT0_ISR();	//PIT0中断服务函数
#endif  //__ISR_H

/* End of "isr.h" */