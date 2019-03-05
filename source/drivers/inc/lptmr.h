//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       Lptmr.h
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef __LPTMR_H__
#define __LPTMR_H__

/**
 *  @brief LPTMR�����������ܽ�ѡ��
 */
typedef enum
{
    //ֻ��1��2�ܽţ���û��0��3�ܽ�
    LPT0_ALT1 = 1,      // PTA19
    LPT0_ALT2 = 2       // PTC5
} LPT0_ALTn;

/**
 *  @brief LPTMR�������������ʽ
 */
typedef enum LPT_CFG
{
    LPT_Rising  = 0,    //�����ش���
    LPT_Falling = 1     //�½��ش���
} LPT_CFG;

#define LPTMR_Flag_Clear()  (LPTMR0_CSR |= LPTMR_CSR_TCF_MASK)         //���LPT�Ƚϱ�־λ


extern void time_delay_ms(u16);


/*          ������ʱ         */
extern void     LPTMR_delay_ms(uint16 ms);      //��ʱ(ms)
extern void     LPTMR_delay_us(uint16 us);      //��ʱ(us)

/*       ���ڶ�ʱ           */
extern void     LPTMR_timing_ms(uint16 ms);     //��ʱ(ms)
extern void     LPTMR_timing_us(uint16 ms);     //��ʱ(us)

/*        ���ڼ�ʱ           */
extern void     LPTMR_time_start_ms(void);      //��ʼ��ʱ(ms)
extern uint32   LPTMR_time_get_ms(void);        //��ȡ��ʱʱ�� 

extern void     LPTMR_time_start_us(void);      //��ʼ��ʱ(ns)
extern uint32   LPTMR_time_get_us(void);        //��ȡ��ʱʱ�� 

extern void     LPTMR_time_close();             //�رռ�ʱ��


/*       �����������        */
extern void     LPTMR_Pulse_Init  (LPT0_ALTn, uint16 count, LPT_CFG);   //��������ʼ������
extern uint16   LPTMR_Pulse_Get   (void);                               //��ȡ����ֵ
extern void     LPTMR_Pulse_Clean (void);                               //��ռ���ֵ


#endif 
