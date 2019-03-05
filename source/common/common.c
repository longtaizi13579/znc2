//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       common.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "include.h"
#include "common.h"

//-------------------------------------------------------------------------*
//������: stop                                                             *
//��  ��: ����CPUΪSTOPģʽ                                                *
//��  ��: ��								   *
//��  ��: ��                                                               *
//˵  ��: ��                                                               *
//-------------------------------------------------------------------------*
void stop (void)
{
    //��λSLEEPDEEP��ʹ��STOPģʽ
  //  SCB->SCR |= SCB_SCR_SLEEPDEEP_MASK;
    //����STOPģʽ
  //  asm("WFI");
}

//-------------------------------------------------------------------------*
//������: wait                                                             *
//��  ��: ����CPUΪWAITģʽ                                                *
//��  ��: ��								   *
//��  ��: ��                                                               *
//˵  ��: ��                                                               *
//-------------------------------------------------------------------------*
void wait (void)
{
    //��SLEEPDEEPλ��ȷ������WAITģʽ
   // SCB->SCR &= ~SCB_SCR_SLEEPDEEP_MASK;
    //����WAITģʽ
   // asm("WFI");
}

//-------------------------------------------------------------------------*
//������: write_vtor                                                       *
//��  ��: �����ж�������ƫ�ƼĴ�����ֵ                                     *
//��  ��: Ҫ���ĵ�ֵ    						   *
//��  ��: ��                                                               *
//˵  ��: ��                                                               *
//-------------------------------------------------------------------------*
void write_vtor (int vtor)
{
    //д��ֵ
    SCB->VTOR = vtor;
}

/*!
 *  @brief      �����ж�����������жϷ�����
 *  @since      v5.0
 *  @warning    ֻ���ж�������λ��icfָ����RAM����ʱ���˺�������Ч
 *  Sample usage:       set_vector_handler(UART3_RX_TX_VECTORn , uart3_handler);    //�� uart3_handler ������ӵ��ж�������
 */
void set_vector_handler(int vector , void pfunc_handler(void))
{
    extern uint32 __VECTOR_RAM[];

    __VECTOR_RAM[(int)vector] = (uint32)pfunc_handler;
}


