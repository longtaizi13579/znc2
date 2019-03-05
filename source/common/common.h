//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       common.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef _COMMON_H_
#define _COMMON_H_


#define ARM_INTERRUPT_LEVEL_BITS     4//中断优先级宏定义
//兼容旧代码
#define enable_irq(irq)                 NVIC_EnableIRQ((IRQn_Type)(irq))         //使能IRQ
#define disable_irq(irq)                NVIC_DisableIRQ((IRQn_Type)(irq))        //禁止IRQ
#define set_irq_priority(irq,pri0)      NVIC_SetPriority((IRQn_Type)(irq),pri0)  //设置优先级

#define EnableInterrupts                asm(" CPSIE i");            //使能全部中断
#define DisableInterrupts               asm(" CPSID i");            //禁止全部中断



/*****************************设置数据类型*****************************/


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


typedef unsigned char         u8;	  //无符号型
typedef unsigned short int   u16;
typedef unsigned int          u32;
typedef unsigned long int    u64;

typedef char		        s8;	  //有符号型
typedef short int	        s16;
typedef int		        s32;
typedef long int    	        s64;

/*
 * 定义带位域的联合体类型
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
} Dtype;    //sizeof(Dtype) 为 4

//-------------------------------------------------------------------------*
//函数名: stop                                                             *
//功  能: 设置CPU为STOP模式                                                *
//-------------------------------------------------------------------------*
void stop (void);

//-------------------------------------------------------------------------*
//函数名: wait                                                             *
//功  能: 设置CPU为WAIT模式                                                *
//-------------------------------------------------------------------------*
void wait (void);

//------------------------------------------------------------------------- *
//函数名: write_vtor                                                        *
//功  能: 更改中断向量表偏移寄存器的值                                       *
//参  数: 要更改的值    						           *
//-------------------------------------------------------------------------*
void write_vtor (int);
void set_vector_handler(int vector , void pfunc_handler(void));      //设置中断函数到中断向量表里

//-------------------------------------------------------------------------*
//函数名: main                                                             *
//功  能: 主函数声明                                                       *
//-------------------------------------------------------------------------*
void main(void);


#endif
