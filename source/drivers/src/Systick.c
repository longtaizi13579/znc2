//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       Systick.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#include "include.h"


void SysTick_delay(u32 cmd)
{
   SysTick->LOAD |=cmd;
   SysTick->VAL  |=0;
   SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk
                   |SysTick_CTRL_CLKSOURCE_Msk;
   while( !(SysTick->CTRL&SysTick_CTRL_COUNTFLAG_Msk) );
}

void delay_us(u32 cmd)//精准延时1us
{
  cmd=(u32)(cmd*core_clk_M);
  SysTick_delay(cmd);
}

void DELAY_us(u32 cmd)//不精准延时1us
{
  while(cmd--)
  {
    delay_us(1);
  }

}