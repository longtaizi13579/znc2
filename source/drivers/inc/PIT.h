//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       PIT.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef _PIT_H_
#define _PIT_H_
#include "common.h"
#include "MK66F18.h"
extern uint32 bus_clk_M;//单位MHZ
//定义PIT模块号
typedef enum
{
    PIT0,
    PIT1,
    PIT2,
    PIT3,

    PIT_MAX,
} PITn_e;

#define     PIT_Flag_Clear(PITn_e)          PIT_TFLG(PITn_e)|=PIT_TFLG_TIF_MASK        //清中断标志（写1 清空标志位）

//ms是毫秒=0.001秒 us是微秒=0.000001秒 ns是纳秒=0.000000001秒

/*****************************以下代码用于PIT中断*************************************/

void pit_init(PITn_e pitn, uint16_t freq);                                              //初始化PITn，并设置频率
void pit_irq_en(PITn_e pitn);                                                           //PITn定时中断开启
void pit_irq_dis(PITn_e pitn);                                                          //PITn定时中断关闭

/*****************************以上代码用于PIT中断*************************************/
/*****************************以下代码用于PIT延时*************************************/

//注意了，延时函数不需要初始化的，直接调用

void        pit_delay(PITn_e, uint32 cnt);                                       //PIT延时（不需要初始化的）
#define     pit_delay_ms(PITn_e,ms)          pit_delay(PITn_e,ms * bus_clk_M*1000);        //PIT延时 ms
#define     pit_delay_us(PITn_e,us)          pit_delay(PITn_e,us * bus_clk_M);   //PIT延时 us
#define     pit_delay_ns(PITn_e,ns)          pit_delay(PITn_e,ns * bus_clk_M/1000);//PIT延时 ns

/*****************************以上代码用于PIT延时*************************************/
/*****************************以下代码用于PIT计时*************************************/

void    pit_time_start  (PITn_e);                                                       //PIT开始计时
uint32  pit_time_get    (PITn_e);                                                       //获取 PITn计时时间(超时时会关闭 定时器)（单位为 bus时钟）(若值为 0xFFFFFFFF，则表示溢出)

#define pit_time_get_ms(PITn_e)   (pit_time_get(PITn_e)/bus_clk_M/1000)                    //获取计时时间（单位为 ms）
#define pit_time_get_us(PITn_e)   (pit_time_get(PITn_e)/bus_clk_M)             //获取计时时间（单位为 us）
void    pit_close  (PITn_e);                                                            //关闭 PIT 计时

/*****************************以上代码用于PIT计时*************************************/

#endif  