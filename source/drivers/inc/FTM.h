//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       FTM.h
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#ifndef _FTM_H_
#define _FTM_H_
#include "MK66F18.h"
/**********************************  FTM(���Ÿ���) ***************************************/

//      ģ��ͨ��    �˿�          ��ѡ��Χ              ����
#define FTM0_CH0_PIN    PTC1        //PTC1��PTA3            PTA3��Ҫ�ã���JLINK��ͻ��
#define FTM0_CH1_PIN    PTC2        //PTC2��PTA4
#define FTM0_CH2_PIN    PTC3        //PTC3��PTA5
#define FTM0_CH3_PIN    PTC4        //PTC4��PTA6
#define FTM0_CH4_PIN    PTD4        //PTD4��PTA7
#define FTM0_CH5_PIN    PTD5        //PTD5��PTA0            PTA0��Ҫ�ã���JLINK��ͻ��
#define FTM0_CH6_PIN    PTD6        //PTD6��PTA1            PTA1��Ҫ�ã���JLINK��ͻ��
#define FTM0_CH7_PIN    PTD7        //PTD7��PTA2            PTA2��Ҫ�ã���JLINK��ͻ��

//      ģ��ͨ��    �˿�          ��ѡ��Χ
#define FTM1_CH0_PIN    PTA8       //PTA8��PTA12��PTB0
#define FTM1_CH1_PIN    PTA9       //PTA9��PTA13��PTB1

//      ģ��ͨ��    �˿�          ��ѡ��Χ
#define FTM2_CH0_PIN    PTA10       //PTA10��PTB18
#define FTM2_CH1_PIN    PTA11       //PTA11��PTB19

//      ģ��ͨ��    �˿�          ��ѡ��Χ
#define FTM3_CH0_PIN    PTE5        // PTE5��PTD0
#define FTM3_CH1_PIN    PTE6        // PTE6��PTD1
#define FTM3_CH2_PIN    PTE7        // PTE7��PTD2
#define FTM3_CH3_PIN    PTE8        // PTE8��PTD3
#define FTM3_CH4_PIN    PTE9        // PTE9��PTC8
#define FTM3_CH5_PIN    PTE10       // PTE10��PTC9
#define FTM3_CH6_PIN    PTE11       // PTE11��PTC10
#define FTM3_CH7_PIN    PTE12       // PTE12��PTC11

//��������ģ��ͨ��  �˿�          ��ѡ��Χ
#define FTM1_QDPHA_PIN  PTA8       //PTA8��PTA12��PTB0
#define FTM1_QDPHB_PIN  PTA9       //PTA9��PTA13��PTB1

#define FTM2_QDPHA_PIN  PTA10       //PTA10��PTB18
#define FTM2_QDPHB_PIN  PTA11       //PTA11��PTB19

/**********************************  FTM(���Ÿ���) ***************************************/


//����FTMģ���
typedef enum
{
    FTM0,
    FTM1,
    FTM2,
    FTM3,

    FTM_MAX,
} FTMn_e;

//����FTM ͨ����
typedef enum
{

    FTM_CH0,
    FTM_CH1,
    FTM_CH2,
    FTM_CH3,
    FTM_CH4,
    FTM_CH5,
    FTM_CH6,
    FTM_CH7,

} FTM_CHn_e;

//��Ƶϵ��
typedef enum
{
    FTM_PS_1,
    FTM_PS_2,
    FTM_PS_4,
    FTM_PS_8,
    FTM_PS_16,
    FTM_PS_32,
    FTM_PS_64,
    FTM_PS_128,

    FTM_PS_MAX,
}FTM_PS_e;      //��Ƶֵ =  (1<< FTM_PS_e) ,����  FTM_PS_2  ��Ӧ�� ��Ƶֵ = (1<<FTM_PS_2) = (1<<1) = 2

extern FTM_MemMapPtr FTMN[FTM_MAX];

/*********************** PWM **************************/
#define FTM_PRECISON  10000u
#define FTM0_PRECISON 10000u     //����ռ�ձȾ��ȣ�100������Ϊ1%��1000u�򾫶�Ϊ0.1%������ռ�ձ� duty �βδ��룬��ռ�ձ�Ϊ duty/FTM_PRECISON
#define FTM1_PRECISON 10000u     //����ռ�ձȾ��ȣ�100������Ϊ1%��1000u�򾫶�Ϊ0.1%������ռ�ձ� duty �βδ��룬��ռ�ձ�Ϊ duty/FTM_PRECISON
#define FTM2_PRECISON 10000u     //����ռ�ձȾ��ȣ�100������Ϊ1%��1000u�򾫶�Ϊ0.1%������ռ�ձ� duty �βδ��룬��ռ�ձ�Ϊ duty/FTM_PRECISON
#define FTM3_PRECISON 10000u     //����ռ�ձȾ��ȣ�100������Ϊ1%��1000u�򾫶�Ϊ0.1%������ռ�ձ� duty �βδ��룬��ռ�ձ�Ϊ duty/FTM_PRECISON

extern void  ftm_pwm_init(FTMn_e, FTM_CHn_e, uint32 freq, uint32 duty);  //��ʼ��FTM��PWM���ܲ�����Ƶ�ʡ�ռ�ձȡ�����ͨ�����ռ�ձȡ�ͬһ��FTM����ͨ����PWMƵ����һ���ģ���3��FTM(FX��4��)

extern void  ftm_pwm_duty(FTMn_e, FTM_CHn_e,              uint32 duty);  //����ͨ��ռ�ձ�,ռ�ձ�Ϊ ��duty * ���ȣ� % ����� FTM_PRECISON ����Ϊ 1000 ��duty = 100 ����ռ�ձ� 100*0.1%=10%
extern void  ftm_pwm_freq(FTMn_e,            uint32 freq);               //����FTM��Ƶ�ʣ���Ƶ�ʺ���Ҫ��������ռ�ձȣ�


/*********************** ���벶׽ **************************/
//FTM ���벶׽����
typedef enum
{
    FTM_Rising,               //�����ز�׽
    FTM_Falling,              //�½��ز�׽
    FTM_Rising_or_Falling     //�����ز�׽
} FTM_Input_cfg;


extern void     ftm_input_init  (FTMn_e, FTM_CHn_e, FTM_Input_cfg,FTM_PS_e ps);     //���벶׽��ʼ������
extern uint16   ftm_input_get   (FTMn_e, FTM_CHn_e);                                //���벶׽ģʽ�£���ȡ��׽�¼�����ʱ�ļ�����ֵ(�������β�׽֮��Ĳ�ֵ���ж�����Ƶ��)
extern void     ftm_input_clean (FTMn_e );                                          //��ռ�������ֵ


#define FTM_IRQ_EN(FTMn,CHn)        FTM_CnSC_REG(FTMN[FTMn],CHn) |= FTM_CnSC_CHIE_MASK       //���� FTMn_CHn �ж�
#define FTM_IRQ_DIS(FTMn,CHn)       FTM_CnSC_REG(FTMN[FTMn],CHn) &= ~FTM_CnSC_CHIE_MASK      //�ر� FTMn_CHn �ж�

/*********************** �������빦�� **************************/
extern void     ftm_quad_init   (FTMn_e);           //��ʼ��FTM ���������� ����
extern int16    ftm_quad_get    (FTMn_e);           //��ȡFTM �������� ��������(������ʾ������)
extern void     ftm_quad_clean  (FTMn_e);           //�� FTM �������� ��������


#endif



