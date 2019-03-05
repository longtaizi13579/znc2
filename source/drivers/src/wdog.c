//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       wdog.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "include.h"
#include "wdog.h"	//包含wdog.h头文件
       
//-------------------------------------------------------------------------*
//函数名: wdog_disable                                                     *
//功  能: 关闭看门狗模块                                                   * 
//参  数: 无			  					   *	
//返  回: 无                                                               *
//说  明: 无                                                               *
//-------------------------------------------------------------------------*
void wdog_disable(void)
{
    //给看门狗模块解锁，以便写寄存器
    wdog_unlock();
    //关闭看门狗
    WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK;
}

//-------------------------------------------------------------------------*
//函数名: wdog_unlock                                                      *
//功  能: 看门狗解锁                                                       * 
//参  数: 无							           *	
//返  回: 无                                                               *
//说  明: 无                                                               *
//-------------------------------------------------------------------------*
void wdog_unlock(void)
{
    /* 注意: 不要单步调试此程序!!! ，否则会引起CPU复位*/
    //关总中断
    DisableInterrupts;		
    //写解锁寄存器
    WDOG_UNLOCK = 0xC520;	
    //完成解锁
    WDOG_UNLOCK = 0xD928;	
    //开总中断
    EnableInterrupts;		
}
