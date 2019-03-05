//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       PLL.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef __PLL_H__
#define __PLL_H__

extern uint32 core_clk_M;//单位MHZ
extern uint32 bus_clk_M;//单位MHZ

//PLL参数
typedef enum clk_option
{
    PLLUNULL ,
    PLL80    ,
    PLL90    ,
    PLL100   ,
    PLL120   ,
    PLL130   ,
    PLL140   ,
    PLL150   ,
    PLL160   ,
    PLL170   ,
    PLL180   ,
    PLL200   ,
    PLL220   ,
    PLL225   ,
    PLL230   ,
    PLL235   ,
    PLL237_5 , //实际为237.5M
} clk_option;



/*********************** PLL功能函数 **************************/
void PLL_Init(clk_option);     //锁相环初始化




#endif
