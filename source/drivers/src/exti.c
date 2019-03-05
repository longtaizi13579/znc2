//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       exti.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-26 12:32
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "exti.h"

/*!
 *  函数名：	exti_enable
 *  功  能：	启用外部中断
 *  返  回：	void
 *  参  数：	PTXn_e ptxn	端口
 *  参  数：	uint32 cfg	中断配置（见port .h）
 *  时  间：	2018-12-25 20:18
 */
void exti_enable(PTXn_e ptxn, uint32 cfg)
{
  port_init(ptxn,ALT1|(cfg&(PORT_PCR_IRQC_MASK&0XFFFFFFFC)));
  enable_irq((int)PORTA_IRQn+PTX((int)ptxn));
}

/*!
 *  函数名：	exti_disable
 *  功  能：	禁用外部中断
 *  返  回：	void
 *  参  数：	PTXn_e ptxn	端口
 *  时  间：	2018-12-25 20:22
 */
void exti_disable(PTXn_e ptxn)
{
  port_init(ptxn,ALT1);
  disable_irq((int)PORTA_IRQn+PTX((int)ptxn));
}
