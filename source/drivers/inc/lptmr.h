//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       Lptmr.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef __LPTMR_H__
#define __LPTMR_H__

/**
 *  @brief LPTMR脉冲计数输入管脚选项
 */
typedef enum
{
    //只有1、2管脚，并没有0、3管脚
    LPT0_ALT1 = 1,      // PTA19
    LPT0_ALT2 = 2       // PTC5
} LPT0_ALTn;

/**
 *  @brief LPTMR脉冲计数触发方式
 */
typedef enum LPT_CFG
{
    LPT_Rising  = 0,    //上升沿触发
    LPT_Falling = 1     //下降沿触发
} LPT_CFG;

#define LPTMR_Flag_Clear()  (LPTMR0_CSR |= LPTMR_CSR_TCF_MASK)         //清除LPT比较标志位


extern void time_delay_ms(u16);


/*          用于延时         */
extern void     LPTMR_delay_ms(uint16 ms);      //延时(ms)
extern void     LPTMR_delay_us(uint16 us);      //延时(us)

/*       用于定时           */
extern void     LPTMR_timing_ms(uint16 ms);     //定时(ms)
extern void     LPTMR_timing_us(uint16 ms);     //定时(us)

/*        用于计时           */
extern void     LPTMR_time_start_ms(void);      //开始计时(ms)
extern uint32   LPTMR_time_get_ms(void);        //获取计时时间 

extern void     LPTMR_time_start_us(void);      //开始计时(ns)
extern uint32   LPTMR_time_get_us(void);        //获取计时时间 

extern void     LPTMR_time_close();             //关闭计时器


/*       用于脉冲计数        */
extern void     LPTMR_Pulse_Init  (LPT0_ALTn, uint16 count, LPT_CFG);   //计数器初始化设置
extern uint16   LPTMR_Pulse_Get   (void);                               //获取计数值
extern void     LPTMR_Pulse_Clean (void);                               //清空计数值


#endif 
