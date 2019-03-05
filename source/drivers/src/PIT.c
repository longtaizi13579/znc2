//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       PIT.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#include "PIT.h"


/*!
 *  @brief      PITn定时中断
 *  @param      PITn        模块号（PIT0~PIT3）
 *  @param      freq  ：定时器频率
 *  @since      v5.0
 *  Sample usage:
                pit_init(PIT0, 100);                          //定时 每10ms中断

 */
void pit_init(PITn_e pitn, uint16_t freq)
{
    //PIT 用的是 Bus Clock 总线频率
    //溢出计数 = 总线频率 * 时间    

    SIM_SCGC6       |= SIM_SCGC6_PIT_MASK;          //使能PIT时钟

    PIT_MCR         = (0
                       //| PIT_MCR_MDIS_MASK       //禁用PIT定时器时钟选择（0表示使能PIT，1表示禁止PIT）
                       //| PIT_MCR_FRZ_MASK        //调试模式下停止运行（0表示继续运行，1表示停止运行）
                      );

    PIT_LDVAL(pitn)  = (uint32)(bus_clk_M * 1000*1000)/freq - 1 ;                    //设置溢出中断时间

    PIT_Flag_Clear(pitn);                           //清中断标志位

    PIT_TCTRL(pitn) &= ~ PIT_TCTRL_TEN_MASK;        //禁止PITn定时器（用于清空计数值）
    PIT_TCTRL(pitn)  = ( 0
                         | PIT_TCTRL_TEN_MASK        //使能 PITn定时器
                         | PIT_TCTRL_TIE_MASK        //开PITn中断
                       );

    //enable_irq((int)pitn + PIT0_IRQn);            //开中断
}

/*************************************************************************
*  函数名称：PIT_IRQ_EN
*  功能说明：PITn定时中断使能
*  参数说明：PITn        模块号（PIT0~PIT3）
*  函数返回：无
*  修改时间：2018-12-19
*  备    注：
*************************************************************************/
void pit_irq_en(PITn_e pitn)
{
  PIT_TCTRL(pitn)  = ( 0
                         | PIT_TCTRL_TEN_MASK        //使能 PITn定时器
                         | PIT_TCTRL_TIE_MASK        //开PITn中断
                       );
  enable_irq((int)pitn + (int)PIT0_IRQn); 
}

/*************************************************************************
*  函数名称：PIT_IRQ_DIS
*  功能说明：PITn定时中断关闭
*  参数说明：PITn        模块号（PIT0~PIT3）
*  函数返回：无
*  修改时间：2018-12-19
*  备    注：
*************************************************************************/
void pit_irq_dis(PITn_e pitn)
{
  PIT_TCTRL(pitn) &= ~ PIT_TCTRL_TEN_MASK;        //禁止PITn定时器
  disable_irq((int)pitn + (int)PIT0_IRQn);
}

/*!
 *  @brief      PITn延时
 *  @param      PITn        模块号（PIT0~PIT3）
 *  @param      cnt         延时时间(单位为bus时钟周期)
 *  @since      v5.0
 *  Sample usage:
                    pit_delay(PIT0, 1000);                         //延时 1000 个bus时钟
 */
void pit_delay(PITn_e pitn, uint32 cnt)
{
    //PIT 用的是 Bus Clock 总线频率
    //溢出计数 = 总线频率 * 时间

    SIM_SCGC6       |= SIM_SCGC6_PIT_MASK;                          //使能PIT时钟

    PIT_MCR         &= ~(PIT_MCR_MDIS_MASK | PIT_MCR_FRZ_MASK );    //使能PIT定时器时钟 ，调试模式下继续运行

    PIT_TCTRL(pitn) &= ~( PIT_TCTRL_TEN_MASK );                     //禁用PIT ，以便设置加载值生效

    PIT_LDVAL(pitn)  = cnt - 1;                                     //设置溢出中断时间

    PIT_Flag_Clear(pitn);                                           //清中断标志位

    PIT_TCTRL(pitn) &= ~ PIT_TCTRL_TEN_MASK;                        //禁止PITn定时器（用于清空计数值）
    PIT_TCTRL(pitn)  = ( 0
                         | PIT_TCTRL_TEN_MASK                        //使能 PITn定时器
                         //| PIT_TCTRL_TIE_MASK                      //开PITn中断
                       );

    while( !(PIT_TFLG(pitn)& PIT_TFLG_TIF_MASK));

    PIT_Flag_Clear(pitn);                                           //清中断标志位
}

/*!
 *  @brief      PITn计时开始
 *  @param      PITn        模块号（PIT0~PIT3）
 *  @since      v5.0
 *  Sample usage:
                    pit_time_start(PIT0);                          //PIT0计时开始
 */
void pit_time_start(PITn_e pitn)
{
    //PIT 用的是 Bus Clock 总线频率
    //溢出计数 = 总线频率 * 时间

    SIM_SCGC6       |= SIM_SCGC6_PIT_MASK;                          //使能PIT时钟

    PIT_MCR         &= ~(PIT_MCR_MDIS_MASK | PIT_MCR_FRZ_MASK );    //使能PIT定时器时钟 ，调试模式下继续运行

    PIT_TCTRL(pitn) &= ~( PIT_TCTRL_TEN_MASK );                     //禁用PIT ，以便设置加载值生效

    PIT_LDVAL(pitn)  = ~0;                                          //设置溢出中断时间

    PIT_Flag_Clear(pitn);                                           //清中断标志位

    PIT_TCTRL(pitn) &= ~ PIT_TCTRL_TEN_MASK;                        //禁止PITn定时器（用于清空计数值）
    PIT_TCTRL(pitn)  = ( 0
                         | PIT_TCTRL_TEN_MASK                        //使能 PITn定时器
                         //| PIT_TCTRL_TIE_MASK                      //开PITn中断
                       );
}

/*!
 *  @brief      获取 PITn计时时间(超时时会关闭 定时器)
 *  @param      PITn        模块号（PIT0~PIT3）
 *  @since      v5.0
 *  Sample usage:
                        uint32 time = pit_time_get(PIT0);                         //获取 PITn计时时间
                        if(time != ~0)       //没超时
                        {
                            printf("\n计时时间为：%d us",time*1000/bus_clk_khz);
                        }
 */
uint32 pit_time_get(PITn_e pitn)
{
    uint32 val;

    val = (~0) - PIT_CVAL(pitn);

    if(PIT_TFLG(pitn)& PIT_TFLG_TIF_MASK)                           //判断是否时间超时
    {
        PIT_Flag_Clear(pitn);                                       //清中断标志位
        PIT_TCTRL(pitn) &= ~ PIT_TCTRL_TEN_MASK;                    //禁止PITn定时器（用于清空计数值）
        return ~0;
    }

    if(val == (~0))
    {
        val--;              //确保 不等于 ~0
    }
    return val;
}

/*!
 *  @brief      关闭 pit
 *  @param      PITn        模块号（PIT0~PIT3）
 *  @since      v5.0
 *  Sample usage:
                        pit_close(PIT0);                         //关闭PIT
 */
void pit_close(PITn_e pitn)
{
    PIT_Flag_Clear(pitn);                                       //清中断标志位
    PIT_TCTRL(pitn) &= ~ PIT_TCTRL_TEN_MASK;                    //禁止PITn定时器（用于清空计数值）
}