//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       PIT.h
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef _PIT_H_
#define _PIT_H_
#include "common.h"
#include "MK66F18.h"
extern uint32 bus_clk_M;//��λMHZ
//����PITģ���
typedef enum
{
    PIT0,
    PIT1,
    PIT2,
    PIT3,

    PIT_MAX,
} PITn_e;

#define     PIT_Flag_Clear(PITn_e)          PIT_TFLG(PITn_e)|=PIT_TFLG_TIF_MASK        //���жϱ�־��д1 ��ձ�־λ��

//ms�Ǻ���=0.001�� us��΢��=0.000001�� ns������=0.000000001��

/*****************************���´�������PIT�ж�*************************************/

void pit_init(PITn_e pitn, uint16_t freq);                                              //��ʼ��PITn��������Ƶ��
void pit_irq_en(PITn_e pitn);                                                           //PITn��ʱ�жϿ���
void pit_irq_dis(PITn_e pitn);                                                          //PITn��ʱ�жϹر�

/*****************************���ϴ�������PIT�ж�*************************************/
/*****************************���´�������PIT��ʱ*************************************/

//ע���ˣ���ʱ��������Ҫ��ʼ���ģ�ֱ�ӵ���

void        pit_delay(PITn_e, uint32 cnt);                                       //PIT��ʱ������Ҫ��ʼ���ģ�
#define     pit_delay_ms(PITn_e,ms)          pit_delay(PITn_e,ms * bus_clk_M*1000);        //PIT��ʱ ms
#define     pit_delay_us(PITn_e,us)          pit_delay(PITn_e,us * bus_clk_M);   //PIT��ʱ us
#define     pit_delay_ns(PITn_e,ns)          pit_delay(PITn_e,ns * bus_clk_M/1000);//PIT��ʱ ns

/*****************************���ϴ�������PIT��ʱ*************************************/
/*****************************���´�������PIT��ʱ*************************************/

void    pit_time_start  (PITn_e);                                                       //PIT��ʼ��ʱ
uint32  pit_time_get    (PITn_e);                                                       //��ȡ PITn��ʱʱ��(��ʱʱ��ر� ��ʱ��)����λΪ busʱ�ӣ�(��ֵΪ 0xFFFFFFFF�����ʾ���)

#define pit_time_get_ms(PITn_e)   (pit_time_get(PITn_e)/bus_clk_M/1000)                    //��ȡ��ʱʱ�䣨��λΪ ms��
#define pit_time_get_us(PITn_e)   (pit_time_get(PITn_e)/bus_clk_M)             //��ȡ��ʱʱ�䣨��λΪ us��
void    pit_close  (PITn_e);                                                            //�ر� PIT ��ʱ

/*****************************���ϴ�������PIT��ʱ*************************************/

#endif  