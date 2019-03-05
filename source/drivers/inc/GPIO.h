//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       GPIO.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef __GPIO_H__
#define __GPIO_H__
#include "GPIO_Cfg.h"
#include "port.h"
/*
 * 定义管脚方向
 */
typedef enum GPIO_CFG
{
    //这里的值不能改！！！
    GPI         = 0,                                //定义管脚输入方向      GPIOx_PDDRn里，0表示输入，1表示输出
    GPO         = 1,                                //定义管脚输出方向
} GPIO_CFG;

#define HIGH  1u
#define LOW   0u

extern  GPIO_MemMapPtr      GPIOX[PTX_MAX];
#define GPIOX_BASE(PTxn)    GPIOX[PTX(PTxn)]       //GPIO模块的地址


/****************************外部使用****************************/

extern void    gpio_init  (PTXn_e, GPIO_CFG, uint8 data);    //初始化gpio
extern void    gpio_ddr   (PTXn_e, GPIO_CFG);                //设置引脚数据方向
extern void    gpio_set   (PTXn_e,           uint8 data);    //设置引脚状态
extern void    gpio_turn  (PTXn_e);                          //反转引脚状态
extern uint8   gpio_get   (PTXn_e);                          //读取引脚状态

//如下 4个 函数 的 PTxn 只能是 宏定义，不能是 变量
#define GPIO_SET(PTxn,data)       (PTXn_T(PTxn,OUT)= (data))    //设置输出电平
#define GPIO_TURN(PTxn)           (PTXn_T(PTxn,T)= 1)           //翻转输出电平
#define GPIO_GET(PTxn)            (PTXn_T(PTxn,IN))             //读取引脚输入状态
#define GPIO_DDR(PTxn,ddr)        (PTXn_T(PTxn,DDR) = ddr)      //输入输出状态


//如下  函数 的 PTxn 可以是  宏定义，也可以是 变量


//n位操作
#define GPIO_SET_NBIT(NBIT,PTxn,data)   GPIO_PDOR_REG(GPIOX_BASE(PTxn)) =   (                                                   \
                                                                                (                                               \
                                                                                    GPIO_PDOR_REG(GPIOX_BASE(PTxn))             \
                                                                                    &                                           \
                                                                                    ((uint32)( ~(((1<<NBIT)-1)<<PTn(PTxn))))    \
                                                                                )                                               \
                                                                                |   ( ((data)&( (1<<(NBIT))-1))<<PTn(PTxn) )    \
                                                                            )


#define GPIO_DDR_NBIT(NBIT,PTxn,ddr)   GPIO_PDDR_REG(GPIOX_BASE(PTxn))  =   (                                                   \
                                                                                (                                               \
                                                                                    GPIO_PDDR_REG(GPIOX_BASE(PTxn))             \
                                                                                    &                                           \
                                                                                    ((uint32)( ~(((1<<(NBIT))-1)<<PTn(PTxn))))  \
                                                                                )                                               \
                                                                                |   ( ( (ddr) &  ( (1<<(NBIT))-1))<<PTn(PTxn) ) \
                                                                            )

#define GPIO_T_NBIT(NBIT,PTxn,data)   GPIO_PTOR_REG(GPIOX_BASE(PTxn))  =   (                                                    \
                                                                                (                                               \
                                                                                    GPIO_PTOR_REG(GPIOX_BASE(PTxn))             \
                                                                                    &                                           \
                                                                                    ((uint32)( ~(((1<<NBIT)-1)<<PTn(PTxn))))    \
                                                                                )                                               \
                                                                                |   ( ((data)&( (1<<(NBIT))-1))<<PTn(PTxn) )    \
                                                                            )


#define GPIO_GET_NBIT(NBIT,PTxn)    (( GPIO_PDIR_REG(GPIOX_BASE(PTxn))>>PTn(PTxn) ) & ((1<<NBIT)-1))


#endif
