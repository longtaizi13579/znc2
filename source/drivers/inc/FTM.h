//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       FTM.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#ifndef _FTM_H_
#define _FTM_H_
#include "MK66F18.h"
/**********************************  FTM(引脚复用) ***************************************/

//      模块通道    端口          可选范围              建议
#define FTM0_CH0_PIN    PTC1        //PTC1、PTA3            PTA3不要用（与JLINK冲突）
#define FTM0_CH1_PIN    PTC2        //PTC2、PTA4
#define FTM0_CH2_PIN    PTC3        //PTC3、PTA5
#define FTM0_CH3_PIN    PTC4        //PTC4、PTA6
#define FTM0_CH4_PIN    PTD4        //PTD4、PTA7
#define FTM0_CH5_PIN    PTD5        //PTD5、PTA0            PTA0不要用（与JLINK冲突）
#define FTM0_CH6_PIN    PTD6        //PTD6、PTA1            PTA1不要用（与JLINK冲突）
#define FTM0_CH7_PIN    PTD7        //PTD7、PTA2            PTA2不要用（与JLINK冲突）

//      模块通道    端口          可选范围
#define FTM1_CH0_PIN    PTA8       //PTA8、PTA12、PTB0
#define FTM1_CH1_PIN    PTA9       //PTA9、PTA13、PTB1

//      模块通道    端口          可选范围
#define FTM2_CH0_PIN    PTA10       //PTA10、PTB18
#define FTM2_CH1_PIN    PTA11       //PTA11、PTB19

//      模块通道    端口          可选范围
#define FTM3_CH0_PIN    PTE5        // PTE5、PTD0
#define FTM3_CH1_PIN    PTE6        // PTE6、PTD1
#define FTM3_CH2_PIN    PTE7        // PTE7、PTD2
#define FTM3_CH3_PIN    PTE8        // PTE8、PTD3
#define FTM3_CH4_PIN    PTE9        // PTE9、PTC8
#define FTM3_CH5_PIN    PTE10       // PTE10、PTC9
#define FTM3_CH6_PIN    PTE11       // PTE11、PTC10
#define FTM3_CH7_PIN    PTE12       // PTE12、PTC11

//正交解码模块通道  端口          可选范围
#define FTM1_QDPHA_PIN  PTA8       //PTA8、PTA12、PTB0
#define FTM1_QDPHB_PIN  PTA9       //PTA9、PTA13、PTB1

#define FTM2_QDPHA_PIN  PTA10       //PTA10、PTB18
#define FTM2_QDPHB_PIN  PTA11       //PTA11、PTB19

/**********************************  FTM(引脚复用) ***************************************/


//定义FTM模块号
typedef enum
{
    FTM0,
    FTM1,
    FTM2,
    FTM3,

    FTM_MAX,
} FTMn_e;

//定义FTM 通道号
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

//分频系数
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
}FTM_PS_e;      //分频值 =  (1<< FTM_PS_e) ,例如  FTM_PS_2  对应的 分频值 = (1<<FTM_PS_2) = (1<<1) = 2

extern FTM_MemMapPtr FTMN[FTM_MAX];

/*********************** PWM **************************/
#define FTM_PRECISON  10000u
#define FTM0_PRECISON 10000u     //定义占空比精度，100即精度为1%，1000u则精度为0.1%，用于占空比 duty 形参传入，即占空比为 duty/FTM_PRECISON
#define FTM1_PRECISON 10000u     //定义占空比精度，100即精度为1%，1000u则精度为0.1%，用于占空比 duty 形参传入，即占空比为 duty/FTM_PRECISON
#define FTM2_PRECISON 10000u     //定义占空比精度，100即精度为1%，1000u则精度为0.1%，用于占空比 duty 形参传入，即占空比为 duty/FTM_PRECISON
#define FTM3_PRECISON 10000u     //定义占空比精度，100即精度为1%，1000u则精度为0.1%，用于占空比 duty 形参传入，即占空比为 duty/FTM_PRECISON

extern void  ftm_pwm_init(FTMn_e, FTM_CHn_e, uint32 freq, uint32 duty);  //初始化FTM的PWM功能并设置频率、占空比。设置通道输出占空比。同一个FTM，各通道的PWM频率是一样的，共3个FTM(FX有4个)

extern void  ftm_pwm_duty(FTMn_e, FTM_CHn_e,              uint32 duty);  //设置通道占空比,占空比为 （duty * 精度） % ，如果 FTM_PRECISON 定义为 1000 ，duty = 100 ，则占空比 100*0.1%=10%
extern void  ftm_pwm_freq(FTMn_e,            uint32 freq);               //设置FTM的频率（改频率后，需要重新配置占空比）


/*********************** 输入捕捉 **************************/
//FTM 输入捕捉配置
typedef enum
{
    FTM_Rising,               //上升沿捕捉
    FTM_Falling,              //下降沿捕捉
    FTM_Rising_or_Falling     //跳变沿捕捉
} FTM_Input_cfg;


extern void     ftm_input_init  (FTMn_e, FTM_CHn_e, FTM_Input_cfg,FTM_PS_e ps);     //输入捕捉初始化函数
extern uint16   ftm_input_get   (FTMn_e, FTM_CHn_e);                                //输入捕捉模式下，读取捕捉事件发生时的计数器值(根据两次捕捉之间的差值可判断周期频率)
extern void     ftm_input_clean (FTMn_e );                                          //清空计数器的值


#define FTM_IRQ_EN(FTMn,CHn)        FTM_CnSC_REG(FTMN[FTMn],CHn) |= FTM_CnSC_CHIE_MASK       //开启 FTMn_CHn 中断
#define FTM_IRQ_DIS(FTMn,CHn)       FTM_CnSC_REG(FTMN[FTMn],CHn) &= ~FTM_CnSC_CHIE_MASK      //关闭 FTMn_CHn 中断

/*********************** 正交解码功能 **************************/
extern void     ftm_quad_init   (FTMn_e);           //初始化FTM 的正交解码 功能
extern int16    ftm_quad_get    (FTMn_e);           //获取FTM 正交解码 的脉冲数(负数表示反方向)
extern void     ftm_quad_clean  (FTMn_e);           //清 FTM 正交解码 的脉冲数


#endif



