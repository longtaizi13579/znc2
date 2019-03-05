//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       port.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "common.h"
#include "port.h"

PORT_MemMapPtr PORTX[PTX_MAX] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};

/*!
 *  @brief      PORT��ʼ��
 *  @param      PTxn    �˿�
 *  @param      cfg     �˿��������ã��紥��ѡ�����������ѡ��
 *  @since      v5.0
 *  @note       ��port_init_NoALT��ͬ���ǣ��˺�����Ҫ���� MUX ���ù��ܣ�
                ���� MUX = ALT0
 *  Sample usage:       port_init (PTA8, IRQ_RISING | PF | ALT1 | PULLUP );    //��ʼ�� PTA8 �ܽţ������ش����жϣ�����Դ�˲��������ù���ΪGPIO ����������
 */
void  port_init(PTXn_e ptxn, uint32 cfg )
{
    SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK << PTX(ptxn));                           //����PORTx�˿�

    PORT_ISFR_REG(PORTX_BASE(ptxn)) = (1<<PTn(ptxn));                           // ��ձ�־λ

    PORT_PCR_REG(PORTX_BASE(ptxn), PTn(ptxn)) = cfg;                            // ���ù��� , ȷ������ģʽ ,������������������
}

/*!
 *  @brief      PORT��ʼ��
 *  @param      PTxn    �˿�
 *  @param      cfg     �˿��������ã��紥��ѡ�����������ѡ��
 *  @since      v5.0
 *  @note       ��port_init��ͬ���ǣ��˺�������Ҫ���� MUX ���ù��ܣ���ʹ������Ҳ����Ч����
                MUX ���� Ϊԭ�ȼĴ������õ�ֵ
 *  Sample usage:       port_init_NoALT (PTA8, IRQ_RISING | PF | PULLUP );    //��ʼ�� PTA8 �ܽţ������ش����жϣ�����Դ�˲���������ԭ�ȸ��ù��ܣ���������
 */
void  port_init_NoALT(PTXn_e ptxn, uint32 cfg)
{
    SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK << PTX(ptxn));                           //����PORTx�˿�

    PORT_ISFR_REG(PORTX_BASE(ptxn)) = (1<<PTn(ptxn));                           // ��ձ�־λ

    //���cfg���MUX�����ؼĴ������MUX
    cfg &= ~PORT_PCR_MUX_MASK;                      //����MUX �ֶΣ�������Ҫ����ALT������ԭ����ALT��
    cfg |=  (PORT_PCR_REG(PORTX_BASE(ptxn), PTn(ptxn)) & PORT_PCR_MUX_MASK);    //��ȡ�Ĵ��������õ� MUX

    PORT_PCR_REG(PORTX_BASE(ptxn), PTn(ptxn)) = cfg;            // ���ù��� , ȷ������ģʽ ,������������������
}

