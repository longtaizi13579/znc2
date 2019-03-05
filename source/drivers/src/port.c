//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       port.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "common.h"
#include "port.h"

PORT_MemMapPtr PORTX[PTX_MAX] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};

/*!
 *  @brief      PORT初始化
 *  @param      PTxn    端口
 *  @param      cfg     端口属性配置，如触发选项和上拉下拉选项
 *  @since      v5.0
 *  @note       与port_init_NoALT不同的是，此函数需要配置 MUX 复用功能，
                否则 MUX = ALT0
 *  Sample usage:       port_init (PTA8, IRQ_RISING | PF | ALT1 | PULLUP );    //初始化 PTA8 管脚，上升沿触发中断，带无源滤波器，复用功能为GPIO ，上拉电阻
 */
void  port_init(PTXn_e ptxn, uint32 cfg )
{
    SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK << PTX(ptxn));                           //开启PORTx端口

    PORT_ISFR_REG(PORTX_BASE(ptxn)) = (1<<PTn(ptxn));                           // 清空标志位

    PORT_PCR_REG(PORTX_BASE(ptxn), PTn(ptxn)) = cfg;                            // 复用功能 , 确定触发模式 ,开启上拉或下拉电阻
}

/*!
 *  @brief      PORT初始化
 *  @param      PTxn    端口
 *  @param      cfg     端口属性配置，如触发选项和上拉下拉选项
 *  @since      v5.0
 *  @note       与port_init不同的是，此函数不需要配置 MUX 复用功能（即使配置了也不生效），
                MUX 保留 为原先寄存器配置的值
 *  Sample usage:       port_init_NoALT (PTA8, IRQ_RISING | PF | PULLUP );    //初始化 PTA8 管脚，上升沿触发中断，带无源滤波器，保留原先复用功能，上拉电阻
 */
void  port_init_NoALT(PTXn_e ptxn, uint32 cfg)
{
    SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK << PTX(ptxn));                           //开启PORTx端口

    PORT_ISFR_REG(PORTX_BASE(ptxn)) = (1<<PTn(ptxn));                           // 清空标志位

    //清空cfg里的MUX，加载寄存器里的MUX
    cfg &= ~PORT_PCR_MUX_MASK;                      //清了MUX 字段（即不需要配置ALT，保持原来的ALT）
    cfg |=  (PORT_PCR_REG(PORTX_BASE(ptxn), PTn(ptxn)) & PORT_PCR_MUX_MASK);    //读取寄存器里配置的 MUX

    PORT_PCR_REG(PORTX_BASE(ptxn), PTn(ptxn)) = cfg;            // 复用功能 , 确定触发模式 ,开启上拉或下拉电阻
}

