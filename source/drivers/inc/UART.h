//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       UART.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef __UART_H__
#define __UART_H__

extern uint32 core_clk_M;//单位MHZ
extern uint32 bus_clk_M;//单位MHZ

//定义模块号
typedef enum
{
    UART_0,
    UART_1,
    UART_2,
    UART_3,
    UART_4,
    UART_MAX,
} UARTn_e;

typedef struct {
  char buff[256];
  uint8 i, j;
}UART_SENDBUFFER;
 
extern UART_MemMapPtr UARTN[UART_MAX];

/**********************************  UART(引脚复用) ***************************************/
//      模块通道    端口          可选范围                          建议
#define UART0_RX    PTB16       //PTA1、PTA15、PTB16、PTD6         PTA1不要用（与J-LINK冲突）
#define UART0_TX    PTB17       //PTA2、PTA14、PTB17、PTD7        PTA2不要用（与J-LINK冲突）

#define UART1_RX    PTC3        //PTC3、PTE1
#define UART1_TX    PTC4        //PTC4、PTE0

#define UART2_RX    PTD2        //PTD2
#define UART2_TX    PTD3        //PTD3

#define UART3_RX    PTC16       //PTB10、PTC16、PTE5
#define UART3_TX    PTC17       //PTB11、PTC17、PTE4

#define UART4_RX    PTE25       //PTC14、PTE25
#define UART4_TX    PTE24       //PTC15、PTE24
/**********************************  UART(引脚复用) ***************************************/



/*********************** UART功能函数 **************************/
//初始化
extern void   uart_init      (UARTn_e, uint32 baud);             //初始化uartx模块

//接收相关代码
extern char   uart_getchar   (UARTn_e);                //等待接收1个字节

extern char   uart_querychar (UARTn_e, char *ch);                //查询接收1个字符
extern uint32 uart_querystr  (UARTn_e, char *str, uint32 max_len); //查询接收字符串
extern uint32 uart_querybuff (UARTn_e, char *buff,uint32 max_len); //查询接收buff

extern char   uart_query     (UARTn_e);                          //查询是否接收到一个字节


//发送相关代码
extern void uart_putchar   (UARTn_e, char ch);                 //发送1个字节
extern void uart_putbuff   (UARTn_e , uint8 *buff, uint32 len);//发送len个字节buff
extern void uart_putstr    (UARTn_e , const uint8 *str);       //发送字符串
extern void uart_sendware(UARTn_e uratn,void *wareaddr, uint32 waresize);
extern void uart_printf(UARTn_e uratn,char *pcFmt,...);

//中断相关代码
extern void uart_rx_irq_en (UARTn_e);                          //开串口接收中断
extern void uart_tx_irq_en (UARTn_e);                          //开串口发送中断
extern void uart_txc_irq_en (UARTn_e);                         //开串口发送完成中断

extern void uart_rx_irq_dis(UARTn_e);                          //关串口接收中断
extern void uart_tx_irq_dis(UARTn_e);                          //关串口发送中断
extern void uart_txc_irq_dis(UARTn_e);                         //关串口发送完成中断

//发送缓存相关代码
extern void uart_sendbuffer_enable(UARTn_e uratn);	//启用UART发送缓存功能
extern void uart_sendbuffer_disable(UARTn_e uratn);	//禁用UART发送缓存功能
extern void uart_sendbuffer_isr(UARTn_e uratn);	//UART发送缓存中断服务程序（在对应模块中断服务程序里发送寄存器空时调用该函数）
/********************************************************************/

#endif 
