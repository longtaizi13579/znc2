//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       common.h
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef _COMMON_H_
#define _COMMON_H_


#define ARM_INTERRUPT_LEVEL_BITS     4//�ж����ȼ��궨��
//���ݾɴ���
#define enable_irq(irq)                 NVIC_EnableIRQ((IRQn_Type)(irq))         //ʹ��IRQ
#define disable_irq(irq)                NVIC_DisableIRQ((IRQn_Type)(irq))        //��ֹIRQ
#define set_irq_priority(irq,pri0)      NVIC_SetPriority((IRQn_Type)(irq),pri0)  //�������ȼ�

#define EnableInterrupts                asm(" CPSIE i");            //ʹ��ȫ���ж�
#define DisableInterrupts               asm(" CPSID i");            //��ֹȫ���ж�



/*****************************������������*****************************/


typedef unsigned char	uint8;  /*  8 bits */
typedef unsigned short int	uint16; /* 16 bits */
typedef unsigned long int	uint32; /* 32 bits */

//typedef unsigned char	uint8_t;  /*  8 bits */
//typedef unsigned short int	uint16_t; /* 16 bits */
//typedef unsigned long int	uint32_t; /* 32 bits */

typedef char		int8;   /*  8 bits */
typedef short int	       	int16;  /* 16 bits */
typedef int		       	int32;  /* 32 bits */

typedef volatile int8	vint8;  /*  8 bits */
typedef volatile int16	vint16; /* 16 bits */
typedef volatile int32	vint32; /* 32 bits */

typedef volatile uint8	        vuint8;  /*  8 bits */
typedef volatile uint16	vuint16; /* 16 bits */
typedef volatile uint32	vuint32; /* 32 bits */


typedef unsigned char         u8;	  //�޷�����
typedef unsigned short int   u16;
typedef unsigned int          u32;
typedef unsigned long int    u64;

typedef char		        s8;	  //�з�����
typedef short int	        s16;
typedef int		        s32;
typedef long int    	        s64;

/*
 * �����λ�������������
 */
typedef union
{
    uint32  DW;
    uint16  W[2];
    uint8   B[4];
    struct
    {
        uint32 b0: 1;
        uint32 b1: 1;
        uint32 b2: 1;
        uint32 b3: 1;
        uint32 b4: 1;
        uint32 b5: 1;
        uint32 b6: 1;
        uint32 b7: 1;
        uint32 b8: 1;
        uint32 b9: 1;
        uint32 b10: 1;
        uint32 b11: 1;
        uint32 b12: 1;
        uint32 b13: 1;
        uint32 b14: 1;
        uint32 b15: 1;
        uint32 b16: 1;
        uint32 b17: 1;
        uint32 b18: 1;
        uint32 b19: 1;
        uint32 b20: 1;
        uint32 b21: 1;
        uint32 b22: 1;
        uint32 b23: 1;
        uint32 b24: 1;
        uint32 b25: 1;
        uint32 b26: 1;
        uint32 b27: 1;
        uint32 b28: 1;
        uint32 b29: 1;
        uint32 b30: 1;
        uint32 b31: 1;
    };
} Dtype;    //sizeof(Dtype) Ϊ 4

//-------------------------------------------------------------------------*
//������: stop                                                             *
//��  ��: ����CPUΪSTOPģʽ                                                *
//-------------------------------------------------------------------------*
void stop (void);

//-------------------------------------------------------------------------*
//������: wait                                                             *
//��  ��: ����CPUΪWAITģʽ                                                *
//-------------------------------------------------------------------------*
void wait (void);

//------------------------------------------------------------------------- *
//������: write_vtor                                                        *
//��  ��: �����ж�������ƫ�ƼĴ�����ֵ                                       *
//��  ��: Ҫ���ĵ�ֵ    						           *
//-------------------------------------------------------------------------*
void write_vtor (int);
void set_vector_handler(int vector , void pfunc_handler(void));      //�����жϺ������ж���������

//-------------------------------------------------------------------------*
//������: main                                                             *
//��  ��: ����������                                                       *
//-------------------------------------------------------------------------*
void main(void);


#endif
