//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       UART.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "include.h"
#include "UART.h"
#include <stdarg.h>
#include <stdio.h>

UART_MemMapPtr UARTN[UART_MAX] = {UART0_BASE_PTR, UART1_BASE_PTR, UART2_BASE_PTR, UART3_BASE_PTR, UART4_BASE_PTR}; 
IRQn_Type UART_IRQn[UART_MAX]={UART0_RX_TX_IRQn,UART1_RX_TX_IRQn,UART2_RX_TX_IRQn,UART3_RX_TX_IRQn,UART4_RX_TX_IRQn};
UART_SENDBUFFER *uart_sendbuff[UART_MAX]={0};

#define pSB uart_sendbuff[(uint8)uratn]

void uart_sendbuffer_putchar(UARTn_e uratn, char c);//通过发送缓存发送一个字符（内部调用）

//-------------------------------------------------------------------------*
//函数名: uart_init                                                        
//功  能: 初始化UART                                                        
//参  数: uratn:模块名如：UART0 
//        baud: 波特率
//返  回: 无                                                              
//简  例: uart_init(UART4,115200);UART4对应引脚参考UART.H文件                                   
//-------------------------------------------------------------------------*

void uart_init (UARTn_e uratn, uint32 baud)
{
    register uint16 sbr, brfa;
    uint8 temp;
    uint32 sysclk;     //时钟

    /* 配置 UART功能的 复用管脚 */
    switch(uratn)
    {
    case UART_0:
        SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;      //使能 UART0 时钟

        if(UART0_RX == PTA1)
        {                    
            PORTA_PCR1= PORT_PCR_MUX(2);       //使能PTA1引脚第二功能，即UART0_RXD
        }
        else if(UART0_RX == PTA15)
        {
             PORTA_PCR15= PORT_PCR_MUX(3);       //使能PTA15引脚第3功能
        }
        else if(UART0_RX == PTB16)
        {
             PORTB_PCR16= PORT_PCR_MUX(3);       //使能PTB16引脚第3功能
        }
        else if(UART0_RX == PTD6)
        {
             PORTD_PCR6= PORT_PCR_MUX(3);       //使能PTD6引脚第3功能
        }
        else
        {
            break;
        }

        if(UART0_TX == PTA2)
        {
             PORTA_PCR2= PORT_PCR_MUX(2);       //使能PTA2引脚第二功能
        }
        else if(UART0_TX == PTA14)
        {
             PORTA_PCR14= PORT_PCR_MUX(3);       //PTA14
        }
        else if(UART0_TX == PTB17)
        {
             PORTB_PCR17= PORT_PCR_MUX(3);       //PTB17
        }
        else if(UART0_TX == PTD7)
        {
             PORTD_PCR7= PORT_PCR_MUX(3);       //PTD7
        }
        else
        {
             break;
        }

        break;

    case UART_1:
        SIM_SCGC4 |= SIM_SCGC4_UART1_MASK;

        if(UART1_RX == PTC3)
        {
             PORTC_PCR3= PORT_PCR_MUX(3);       //PTC3
        }
        else if(UART1_RX == PTE1)
        {
             PORTE_PCR1= PORT_PCR_MUX(3);       //PTE1
        }
        else
        {
            break;
        }

        if(UART1_TX == PTC4)
        {
             PORTC_PCR4= PORT_PCR_MUX(3);       //PTC4
        }
        else if(UART1_TX == PTE0)
        {
             PORTE_PCR0= PORT_PCR_MUX(3);       //PTE0
        }
        else
        {
            break;
        }

        break;

    case UART_2:
        SIM_SCGC4 |= SIM_SCGC4_UART2_MASK;
         PORTD_PCR3= PORT_PCR_MUX(3);       //PTD3
         PORTD_PCR2= PORT_PCR_MUX(3);       //PTD2
        break;

    case UART_3:
        SIM_SCGC4 |= SIM_SCGC4_UART3_MASK;

        if(UART3_RX == PTB10)
        {
             PORTB_PCR10= PORT_PCR_MUX(3);       //PTB10
        }
        else if(UART3_RX == PTC16)
        {
             PORTC_PCR16= PORT_PCR_MUX(3);       //PTC16
        }
        else if(UART3_RX == PTE5)
        {
             PORTE_PCR5= PORT_PCR_MUX(3);       //PTE5
        }
        else
        {
             break;
        }

        if(UART3_TX == PTB11)
        {
             PORTB_PCR11= PORT_PCR_MUX(3);       //PTB11
        }
        else if(UART3_TX == PTC17)
        {
             PORTC_PCR17= PORT_PCR_MUX(3);       //PTC17
        }
        else if(UART3_TX == PTE4)
        {
             PORTE_PCR4= PORT_PCR_MUX(3);       //PTE4
        }
        else
        {
             break;
        }
        break;

    case UART_4:
        SIM_SCGC1 |= SIM_SCGC1_UART4_MASK;

        if(UART4_RX == PTC14)
        {
             PORTC_PCR14= PORT_PCR_MUX(3);       //PTC14
        }
        else if(UART4_RX == PTE25)
        {
             PORTE_PCR25= PORT_PCR_MUX(3);       //PTE25
        }
        else
        {
            break;
        }

        if(UART4_TX == PTC15)
        {
             PORTC_PCR15= PORT_PCR_MUX(3);       //PTC15
        }
        else if(UART4_TX == PTE24)
        {
             PORTE_PCR24= PORT_PCR_MUX(3);       //PTE24
        }
        else
        {
             break;
        }
        break;
   
    default:
        break;
    }

    //设置的时候，应该禁止发送接受
    UART_C2_REG(UARTN[uratn]) &= ~(0
                                   | UART_C2_TE_MASK
                                   | UART_C2_RE_MASK
                                  );


    //配置成8位无校验模式
    //设置 UART 数据格式、校验方式和停止位位数。通过设置 UART 模块控制寄存器 C1 实现；
    UART_C1_REG(UARTN[uratn]) |= (0
                                  //| UART_C2_M_MASK                    //9 位或 8 位模式选择 : 0 为 8位 ，1 为 9位（注释了表示0，即8位） （如果是9位，位8在UARTx_C3里）
                                  //| UART_C2_PE_MASK                   //奇偶校验使能（注释了表示禁用）
                                  //| UART_C2_PT_MASK                   //校验位类型 : 0 为 偶校验 ，1 为 奇校验
                                 );

    //计算波特率，串口0、1使用内核时钟，其它串口使用bus时钟
    if ((uratn == UART_0) || (uratn == UART_1))
    {
        sysclk = (uint32)(core_clk_M * 1000*1000);                                   //内核时钟
    }
    else
    {
        sysclk = (uint32)(bus_clk_M * 1000*1000);                                    //bus时钟(是内核时钟的一半)
    }

    //UART 波特率 = UART 模块时钟 / (16 × (SBR[12:0] + BRFA))
    //不考虑 BRFA 的情况下， SBR = UART 模块时钟 / (16 * UART 波特率)
    sbr = (uint16)(sysclk / (baud * 16));
    if(sbr > 0x1FFF)sbr = 0x1FFF;                                       //SBR 是 13bit，最大为 0x1FFF

    //已知 SBR ，则 BRFA =  = UART 模块时钟 / UART 波特率 - 16 ×SBR[12:0]
    brfa = (sysclk / baud)  - (sbr * 16);
    

    //写 SBR
    temp = UART_BDH_REG(UARTN[uratn]) & (~UART_BDH_SBR_MASK);           //缓存 清空 SBR 的 UARTx_BDH的值
    UART_BDH_REG(UARTN[uratn]) = temp |  UART_BDH_SBR(sbr >> 8);        //先写入SBR高位
    UART_BDL_REG(UARTN[uratn]) = UART_BDL_SBR(sbr);                     //再写入SBR低位

    //写 BRFD
    temp = UART_C4_REG(UARTN[uratn]) & (~UART_C4_BRFA_MASK) ;           //缓存 清空 BRFA 的 UARTx_C4 的值
    UART_C4_REG(UARTN[uratn]) = temp |  UART_C4_BRFA(brfa);             //写入BRFA



    //设置FIFO(FIFO的深度是由硬件决定的，软件不能设置)
    UART_PFIFO_REG(UARTN[uratn]) |= (0
                                     | UART_PFIFO_TXFE_MASK               //使能TX FIFO(注释表示禁止)
                                     //| UART_PFIFO_TXFIFOSIZE(0)         //（只读）TX FIFO 大小，0为1字节，1~6为 2^(n+1)字节
                                     | UART_PFIFO_RXFE_MASK               //使能RX FIFO(注释表示禁止)
                                     //| UART_PFIFO_RXFIFOSIZE(0)         //（只读）RX FIFO 大小，0为1字节，1~6为 2^(n+1)字节
                                    );

    /* 允许发送和接收 */
    UART_C2_REG(UARTN[uratn]) |= (0
                                  | UART_C2_TE_MASK                     //发送使能
                                  | UART_C2_RE_MASK                     //接收使能
                                  //| UART_C2_TIE_MASK                  //发送中断或DMA传输请求使能（注释了表示禁用）
                                  //| UART_C2_TCIE_MASK                 //发送完成中断使能（注释了表示禁用）
                                  //| UART_C2_RIE_MASK                  //接收满中断或DMA传输请求使能（注释了表示禁用）
                                 );


}

/*!
 *  @brief      等待接受1个字节
 *  @param      UARTn_e       模块号（UART0~UART5）
 *  @since      v5.0
 *  @note       如果需要查询接收状态，可用 uart_query ，
                如果需要查询接收数据，可用 uart_querychar
 *  Sample usage:
                        char ch;
                        uart_getchar (UART3,&ch);   //等待接受1个字节，保存到 ch里
 */
char uart_getchar (UARTn_e uratn)
{
   while (!(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK));       //等待接收满了   
   return(UART_D_REG(UARTN[uratn]));
}

/*!
 *  @brief      查询接收1个字符
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @param      ch          接收地址
 *  @return     1为接收成功，0为接收失败
 *  @since      v5.0
 *  @note       如果需要等待接收，可用 uart_getchar
 *  Sample usage:       char ch ;
                        if( uart_querychar (UART_3,&ch) == 1)     //查询接收1个字符，保存到 ch里
                        {
                            printf("成功接收到一个字节");
                        }
 */
char uart_querychar (UARTn_e uratn, char *ch)
{
    if( UART_RCFIFO_REG(UARTN[uratn]) )         //查询是否接受到数据
    {
        *ch  =   UART_D_REG(UARTN[uratn]);      //接受到8位的数据
        return  1;                              //返回 1 表示接收成功
    }

    *ch = 0;                                    //接收不到，应该清空了接收区
    return 0;                                   //返回0表示接收失败
}

/*!
 *  @brief      查询接收字符串
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @param      str         接收地址
 *  @param      max_len     最大接收长度
 *  @return     接收到的字节数目
 *  @since      v5.0
 *  Sample usage:       char str[100];
                        uint32 num;
                        num = uart_querystr (UART_3,&str,100);
                        if( num != 0 )
                        {
                            printf("成功接收到%d个字节:%s",num,str);
                        }
 */
uint32 uart_querystr (UARTn_e uratn, char *str, uint32 max_len)
{
    uint32 i = 0,j;

    for(j=0;j<10000;j++)                 // 10000 的作用是延时，可自行根据情况修改
    {
        while(uart_querychar(uratn, str + i)  )
        {
            j=0;
            if( *(str + i) == NULL )    //接收到字符串结束符
            {
                return i;
            }

            i++;
            if(i >= max_len)            //超过设定的最大值，退出
            {
                *(str + i) = 0;     //确保字符串结尾是0x00
                return i;
            }
        }
    }

    *(str + i) = 0;                     //确保字符串结尾是0x00
    return i;
}


/*!
 *  @brief      查询接收buff
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @param      str         接收地址
 *  @param      max_len     最大接收长度
 *  @return     接收到的字节数目
 *  @since      v5.0
 *  Sample usage:       char buff[100];
                        uint32 num;
                        num = uart_querybuff (UART_3,&buff,100);
                        if( num != 0 )
                        {
                            printf("成功接收到%d个字节:%s",num,buff);
                        }
 */
uint32 uart_querybuff (UARTn_e uratn, char *buff, uint32 max_len)
{
    uint32 i = 0,j;
    for(j=0;j<10000;j++)                 // 10000 的作用是延时，可自行根据情况修改
    {
        while(uart_querychar(uratn, buff + i)  )
        {
            i++;
            if(i >= max_len)            //超过设定的最大值，退出
            {
                return i;
            }
        }
    }

    return i;
}


/*!
 *  @brief      串口发送一个字节
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @param      ch          需要发送的字节
 *  @since      v5.0
 *  @note       printf需要用到此函数
 *  @see        fputc
 *  Sample usage:       uart_putchar (UART_3, 'A');  //发送字节'A'
 */
void uart_putchar (UARTn_e uratn, char ch)
{
    if(pSB) uart_sendbuffer_putchar(uratn,ch);
    else{
        //等待发送缓冲区空
        while(!(UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK));

        //发送数据
        UART_D_REG(UARTN[uratn]) = (uint8)ch;
    }
}

/*!
 *  @brief      查询是否接受到一个字节
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @return     接收到数据返回1，没接收到数据返回0
 *  @since      v5.0
 *  Sample usage:       char ch;
                        if(uart_query (UART_3) == 1)     //查询是否接收到数据
                        {
                            ch = uart_getchar (UART_3);  //等待接收一个数据，保存到 ch里
                        }
 */
char uart_query (UARTn_e uratn)
{
    if(UART_RCFIFO_REG(UARTN[uratn]))                 //接收到数据数量非0
        //if(!(UART_SFIFO_REG(UARTN[uratn]) & UART_SFIFO_RXEMPT_MASK))
        //if(UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    //return UART_RCFIFO_REG(UARTN[uratn]);
}

/*!
 *  @brief      发送指定len个字节长度数组 （包括 NULL 也会发送）
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @param      buff        数组地址
 *  @param      len         发送数组的长度
 *  @since      v5.0
 *  Sample usage:       uart_putbuff (UART_3,"1234567", 3); //实际发送了3个字节'1','2','3'
 */
void uart_putbuff (UARTn_e uratn, uint8 *buff, uint32 len)
{
    while(len--)
    {
        uart_putchar(uratn, *buff);
        buff++;
    }
}


/*!
 *  @brief      发送字符串(遇 NULL 停止发送)
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @param      str         字符串地址
 *  @since      v5.0
 *  Sample usage:       uart_putstr (UART_3,"1234567"); //实际发送了7个字节
 */
void uart_putstr (UARTn_e uratn, const uint8 *str)
{
    while(*str)
    {
        uart_putchar(uratn, *str++);
    }
}

/*!
 *  @brief      开串口接收中断
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @since      v5.0
 *  Sample usage:       uart_rx_irq_en(UART_3);         //开串口3接收中断
 */
void uart_rx_irq_en(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) |= UART_C2_RIE_MASK;                          //使能UART接收中断    
    NVIC_EnableIRQ(UART_IRQn[uratn]);                  //使能IRQ中断
}

/*!
 *  @brief      开串口发送中断
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_en(UART_3);         //开串口3发送中断
 */
void uart_tx_irq_en(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) |= UART_C2_TIE_MASK;                          //使能UART发送中断
    NVIC_EnableIRQ(UART_IRQn[uratn]);                  //使能IRQ中断
}

/*!
 *  @brief      开串口发送完成中断
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_en(UART_3);         //开串口3发送中断
 */
void uart_txc_irq_en(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) |= UART_C2_TCIE_MASK;                         //使能UART发送中断
    NVIC_EnableIRQ(UART_IRQn[uratn]);                  //使能IRQ中断
}

/*!
 *  @brief      关串口接收中断
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @since      v5.0
 *  Sample usage:       uart_rx_irq_dis(UART_3);         //关串口3接收中断
 */
void uart_rx_irq_dis(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) &= ~UART_C2_RIE_MASK;                         //禁止UART接收中断

    //如果发送中断还没有关，则不关闭IRQ
    if(!(UART_C2_REG(UARTN[uratn]) & (UART_C2_TIE_MASK | UART_C2_TCIE_MASK)) )
    {
        NVIC_DisableIRQ(UART_IRQn[uratn]);             //关IRQ中断
    }
}

/*!
 *  @brief      关串口发送中断
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_dis(UART_3);         //关串口3发送中断
 */
void uart_txc_irq_dis(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) &= ~UART_C2_TCIE_MASK;                        //禁止UART发送完成中断

    //如果接收中断还没有关，则不关闭IRQ
    if(!(UART_C2_REG(UARTN[uratn]) & UART_C2_RIE_MASK) )
    {
        NVIC_DisableIRQ(UART_IRQn[uratn]);             //关IRQ中断
    }
}

/*!
 *  @brief      关串口发送中断
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_dis(UART_3);         //关串口3发送中断
 */
void uart_tx_irq_dis(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) &= ~UART_C2_TIE_MASK;                         //禁止UART发送中断

    //如果接收中断还没有关，则不关闭IRQ
    if(!(UART_C2_REG(UARTN[uratn]) & UART_C2_RIE_MASK) )
    {
        NVIC_DisableIRQ(UART_IRQn[uratn]);             //关IRQ中断
    }
}

/*!
 *  @brief      向虚拟示波器发送一个数据帧
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @param      wareaddr      数据帧数组首地址
 *  @param      waresize      数据帧数组大小（单位：字节）
 *  @since      v5.0
 *  Sample usage:       uart_sendware（UART_3,&floatnum,1*sizeof(float));   //在串口3向虚拟示波器发送一个浮点数
 */
void uart_sendware(UARTn_e uratn,void *wareaddr, uint32 waresize)
{
#define CMD_WARE     3
    uint8 cmdf[2] = {CMD_WARE, ~CMD_WARE};    //串口调试 使用的前命令
    uint8 cmdr[2] = {~CMD_WARE, CMD_WARE};    //串口调试 使用的后命令

    uart_putbuff(uratn, cmdf, sizeof(cmdf));    //先发送前命令
    uart_putbuff(uratn, wareaddr, waresize);    //发送数据
    uart_putbuff(uratn, cmdr, sizeof(cmdr));    //发送后命令

}

/*!
 *  @brief      用法同printf
 *  @param      UARTn_e       模块号（UART0~UART4）
 *  @since      v5.0
 *  Sample usage:       
 */
void uart_printf(UARTn_e uratn,char *pcFmt,...)
{
        va_list ap;
        char pbString[256];

        va_start(ap,pcFmt);
        vsprintf(pbString,pcFmt,ap);
		uart_putstr(uratn,(uint8 *)pbString);
        va_end(ap);
}

/*
启用发送缓存可以将串口的发送方式由程序查询改为中断，从而提高发送效率
经测试，以中断发送所占用的CPU时间可忽略不计
受到实际发送速率的限制，理论上串口发送速率应不超过 波特率/（1+8+1） byte/s
例如以115200的波特率，10ms发一次数据，那么每次发的数据量理论上不超过 115200/10*0.01=115.2字节
在实际中由于数据帧之间可能存在空隙，建议最大发送速率为 理论值*0.9
受到缓冲区大小限制，单次发送数据不要超过255字节
发送速率过快或单次发送数据量过大，都会导致缓冲区溢出
为了效率考虑，缓冲区溢出将不会给出任何提示，并直接丢弃缓冲区内所有数据
*/

/*!
 *  函数名：	uart_sendbuffer_enable
 *  功  能：	启用UART发送缓存功能
 *  返  回：	void
 *  参  数：	UARTn_e uratn	模块号（UART0~UART4）
 *  时  间：	2018-12-22 17:16
 */
void uart_sendbuffer_enable(UARTn_e uratn)
{
    if ( pSB== NULL){
        pSB = malloc(sizeof(UART_SENDBUFFER));
        if ( pSB== NULL) return;
    }
	pSB->i = 0;
	pSB->j = 0;
}

/*!
 *  函数名：	uart_sendbuffer_disable
 *  功  能：	禁用UART发送缓存功能
 *  返  回：	void
 *  参  数：	UARTn_e uratn	模块号（UART0~UART4）
 *  时  间：	2018-12-22 17:18
 */
void uart_sendbuffer_disable(UARTn_e uratn)
{
    if(pSB==NULL) return;
    while (pSB->i!=pSB->j);//等待数据发完
    free(pSB);
    pSB = NULL;
}

/*!
 *  函数名：	uart_sendbuffer_isr
 *  功  能：	UART发送缓存中断服务程序（在对应模块中断服务程序里调用该函数）
 *  返  回：	void
 *  参  数：	UARTn_e uratn	模块号（UART0~UART4）
 *  时  间：	2018-12-22 17:24
 */
void uart_sendbuffer_isr(UARTn_e uratn)
{
    if((UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK)&&pSB==NULL) return;
    if (pSB->i!=pSB->j) {
        UART_D_REG(UARTN[uratn]) = pSB->buff[pSB->j];
        (pSB->j)++;		
    }
    else uart_tx_irq_dis(uratn);
}

/*!
 *  函数名：	uart_sendbuffer_putchar
 *  功  能：	通过发送缓存发送一个字符（内部调用）
 *  返  回：	void
 *  参  数：	UARTn_e uratn	模块号（UART0~UART4）
 *  参  数：	char c	发送的字节
 *  时  间：	2018-12-22 17:28
 */
void uart_sendbuffer_putchar(UARTn_e uratn, char c)
{
    if(pSB==NULL) return;
    uart_tx_irq_en(uratn);	
    if ((UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK) && (pSB->i == pSB->j)) 
        UART_D_REG(UARTN[uratn]) = c;	
    else {
        pSB->buff[pSB->i] = c;
        (pSB->i)++;		
    }	
}

