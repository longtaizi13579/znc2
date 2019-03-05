//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       UART.h
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#ifndef __UART_H__
#define __UART_H__

extern uint32 core_clk_M;//��λMHZ
extern uint32 bus_clk_M;//��λMHZ

//����ģ���
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

/**********************************  UART(���Ÿ���) ***************************************/
//      ģ��ͨ��    �˿�          ��ѡ��Χ                          ����
#define UART0_RX    PTB16       //PTA1��PTA15��PTB16��PTD6         PTA1��Ҫ�ã���J-LINK��ͻ��
#define UART0_TX    PTB17       //PTA2��PTA14��PTB17��PTD7        PTA2��Ҫ�ã���J-LINK��ͻ��

#define UART1_RX    PTC3        //PTC3��PTE1
#define UART1_TX    PTC4        //PTC4��PTE0

#define UART2_RX    PTD2        //PTD2
#define UART2_TX    PTD3        //PTD3

#define UART3_RX    PTC16       //PTB10��PTC16��PTE5
#define UART3_TX    PTC17       //PTB11��PTC17��PTE4

#define UART4_RX    PTE25       //PTC14��PTE25
#define UART4_TX    PTE24       //PTC15��PTE24
/**********************************  UART(���Ÿ���) ***************************************/



/*********************** UART���ܺ��� **************************/
//��ʼ��
extern void   uart_init      (UARTn_e, uint32 baud);             //��ʼ��uartxģ��

//������ش���
extern char   uart_getchar   (UARTn_e);                //�ȴ�����1���ֽ�

extern char   uart_querychar (UARTn_e, char *ch);                //��ѯ����1���ַ�
extern uint32 uart_querystr  (UARTn_e, char *str, uint32 max_len); //��ѯ�����ַ���
extern uint32 uart_querybuff (UARTn_e, char *buff,uint32 max_len); //��ѯ����buff

extern char   uart_query     (UARTn_e);                          //��ѯ�Ƿ���յ�һ���ֽ�


//������ش���
extern void uart_putchar   (UARTn_e, char ch);                 //����1���ֽ�
extern void uart_putbuff   (UARTn_e , uint8 *buff, uint32 len);//����len���ֽ�buff
extern void uart_putstr    (UARTn_e , const uint8 *str);       //�����ַ���
extern void uart_sendware(UARTn_e uratn,void *wareaddr, uint32 waresize);
extern void uart_printf(UARTn_e uratn,char *pcFmt,...);

//�ж���ش���
extern void uart_rx_irq_en (UARTn_e);                          //�����ڽ����ж�
extern void uart_tx_irq_en (UARTn_e);                          //�����ڷ����ж�
extern void uart_txc_irq_en (UARTn_e);                         //�����ڷ�������ж�

extern void uart_rx_irq_dis(UARTn_e);                          //�ش��ڽ����ж�
extern void uart_tx_irq_dis(UARTn_e);                          //�ش��ڷ����ж�
extern void uart_txc_irq_dis(UARTn_e);                         //�ش��ڷ�������ж�

//���ͻ�����ش���
extern void uart_sendbuffer_enable(UARTn_e uratn);	//����UART���ͻ��湦��
extern void uart_sendbuffer_disable(UARTn_e uratn);	//����UART���ͻ��湦��
extern void uart_sendbuffer_isr(UARTn_e uratn);	//UART���ͻ����жϷ�������ڶ�Ӧģ���жϷ�������﷢�ͼĴ�����ʱ���øú�����
/********************************************************************/

#endif 
