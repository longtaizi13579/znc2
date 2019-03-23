//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       isr.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#include "isr.h"

//UART0~UART4 串口中断服务函数
void UART0_ISR(void){}
void UART1_ISR(void){}
void UART2_ISR(void){}
void UART3_ISR(void){}
void UART4_ISR(void)
{
    UARTn_e uratn = UART_4;//UART0 中断服务函数
    if(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK)   //接收数据寄存器满
    {
        //用户需要处理接收数据
      uart_putchar(uratn,uart_getchar(uratn));//回显

    }

    if(UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK )  //发送数据寄存器空
    {
        //用户需要处理发送数据
      uart_sendbuffer_isr(uratn);//发送缓存中断处理函数

    }

}
/***********************************************************************************/
//PORTA~PORTE 端口中断服务函数
void PORTA_ISR(void){}
void PORTB_ISR(void)
{

    uint8  n = 3;    //引脚号
    //PTB3
   
    if(PORTB_ISFR & (1 << n))           //PTE0触发中断
    {
        PORTB_ISFR  |= (1 << n);        //写1清中断标志位

        /*  以下为用户任务  */


        /*  以上为用户任务  */
    }
}
void PORTC_ISR(void){}

void PORTE_ISR(void)
{
}



/*!
 *  函数名：	LPTMR_ISR
 *  功  能：	LPTMR中断服务函数
 *  返  回：	void
 *  时  间：	2018-12-21 20:17
 */
void LPTMR_ISR(){}



/*!
 *  函数名：	DMA0_ISR
 *  功  能：	DMA0中断服务函数
 *  返  回：	void
 *  时  间：	2018-12-22 16:17
 */
void DMA0_ISR()
{

}


/*!
 *  函数名：	FTM0_ISR
 *  功  能：	FTM0中断服务函数
 *  返  回：	void
 *  时  间：	2018-12-22 16:18
 */
void FTM0_ISR()
{
    uint8 s = FTM0_STATUS;             //读取捕捉和比较状态  All CHnF bits can be checked using only one read of STATUS.
    uint8 CHn;

    FTM0_STATUS = 0x00;             //清中断标志位

    CHn = 0;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_DIS(FTM1, CHn);     //禁止输入捕捉中断
        /*     用户任务       */

        /*********************/
        //FTM_IRQ_EN(FTM1, CHn); //开启输入捕捉中断

    }

    /* 这里添加 n=1 的模版，根据模版来添加 */
    CHn = 1;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_EN(FTM1, CHn); //开启输入捕捉中断
        /*     用户任务       */


        /*********************/
        //不建议在这里开启输入捕捉中断
        //FTM_IRQ_EN(FTM1, CHn); //开启输入捕捉中断
    }
}

/*!
 *  函数名：	PIT0_ISR
 *  功  能：	PIT0中断服务函数
 *  返  回：	void
 *  时  间：	2018-12-22 16:45
 */
int time_count = 0;
float left_speed_in = 0, left_speed_out = 0, left_speed_set = 180;
float right_speed_in = 0, right_speed_out = 0, right_speed_set = 180;
pid_t pid1,pid2;
void PIT0_ISR()
{
    PIT_Flag_Clear(PIT0);//清中断标志位 
   /*if(time_count == 10)
    {
      left_speed_in = (float)ftm_quad_get(FTM1);
      right_speed_in = -(float)ftm_quad_get(FTM2);
      
      pid_compute(pid1);//左
      pid_compute(pid2);//右
      PWMSetMotor2((s32)right_speed_out,(s32)left_speed_out); 
      //uart_printf(UART_0, "%f %f\n",left_speed_in,right_speed_in);
      //清空ftm计数器
      ftm_quad_clean(FTM1);
      ftm_quad_clean(FTM2);
      time_count = 0;
    }
    time_count = time_count + 1;*/
    PWMSetMotor2(4000,4000);
    //方向环
    int adc1 = 0, adc2 = 0, adc3 = 0,adc4=0;
    adc1 = adc_once(ADC1_DM0, ADC_8bit);     //通过drivers_cfg.h找到引脚E0对应的ADC资源 ：ADC1_AD4a
    adc2 = adc_once(ADC0_DP3, ADC_8bit);
    adc3 = adc_once(ADC1_SE18, ADC_8bit);
    adc4 = adc_once(ADC1_SE16, ADC_8bit);
    //uart_printf(UART_0, "%d %d %d %d\n",adc1,adc2,adc3,adc4);
    direction_control(adc3+adc4 , adc1+adc2);  
}
