//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       Systick.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
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

void delay_us(u32 cmd)//��׼��ʱ1us
{
  cmd=(u32)(cmd*core_clk_M);
  SysTick_delay(cmd);
}

void DELAY_us(u32 cmd)//����׼��ʱ1us
{
  while(cmd--)
  {
    delay_us(1);
  }

}