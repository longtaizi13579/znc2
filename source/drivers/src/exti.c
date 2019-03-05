//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       exti.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-26 12:32
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "exti.h"

/*!
 *  ��������	exti_enable
 *  ��  �ܣ�	�����ⲿ�ж�
 *  ��  �أ�	void
 *  ��  ����	PTXn_e ptxn	�˿�
 *  ��  ����	uint32 cfg	�ж����ã���port .h��
 *  ʱ  �䣺	2018-12-25 20:18
 */
void exti_enable(PTXn_e ptxn, uint32 cfg)
{
  port_init(ptxn,ALT1|(cfg&(PORT_PCR_IRQC_MASK&0XFFFFFFFC)));
  enable_irq((int)PORTA_IRQn+PTX((int)ptxn));
}

/*!
 *  ��������	exti_disable
 *  ��  �ܣ�	�����ⲿ�ж�
 *  ��  �أ�	void
 *  ��  ����	PTXn_e ptxn	�˿�
 *  ʱ  �䣺	2018-12-25 20:22
 */
void exti_disable(PTXn_e ptxn)
{
  port_init(ptxn,ALT1);
  disable_irq((int)PORTA_IRQn+PTX((int)ptxn));
}
