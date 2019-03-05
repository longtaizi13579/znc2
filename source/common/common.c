//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       common.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "include.h"
#include "common.h"

//-------------------------------------------------------------------------*
//函数名: stop                                                             *
//功  能: 设置CPU为STOP模式                                                *
//参  数: 无								   *
//返  回: 无                                                               *
//说  明: 无                                                               *
//-------------------------------------------------------------------------*
void stop (void)
{
    //置位SLEEPDEEP来使能STOP模式
  //  SCB->SCR |= SCB_SCR_SLEEPDEEP_MASK;
    //进入STOP模式
  //  asm("WFI");
}

//-------------------------------------------------------------------------*
//函数名: wait                                                             *
//功  能: 设置CPU为WAIT模式                                                *
//参  数: 无								   *
//返  回: 无                                                               *
//说  明: 无                                                               *
//-------------------------------------------------------------------------*
void wait (void)
{
    //清SLEEPDEEP位来确定进入WAIT模式
   // SCB->SCR &= ~SCB_SCR_SLEEPDEEP_MASK;
    //进入WAIT模式
   // asm("WFI");
}

//-------------------------------------------------------------------------*
//函数名: write_vtor                                                       *
//功  能: 更改中断向量表偏移寄存器的值                                     *
//参  数: 要更改的值    						   *
//返  回: 无                                                               *
//说  明: 无                                                               *
//-------------------------------------------------------------------------*
void write_vtor (int vtor)
{
    //写新值
    SCB->VTOR = vtor;
}

/*!
 *  @brief      设置中断向量表里的中断服务函数
 *  @since      v5.0
 *  @warning    只有中断向量表位于icf指定的RAM区域时，此函数才有效
 *  Sample usage:       set_vector_handler(UART3_RX_TX_VECTORn , uart3_handler);    //把 uart3_handler 函数添加到中断向量表
 */
void set_vector_handler(int vector , void pfunc_handler(void))
{
    extern uint32 __VECTOR_RAM[];

    __VECTOR_RAM[(int)vector] = (uint32)pfunc_handler;
}


