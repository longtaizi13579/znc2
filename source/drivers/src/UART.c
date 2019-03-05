//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       UART.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
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

void uart_sendbuffer_putchar(UARTn_e uratn, char c);//ͨ�����ͻ��淢��һ���ַ����ڲ����ã�

//-------------------------------------------------------------------------*
//������: uart_init                                                        
//��  ��: ��ʼ��UART                                                        
//��  ��: uratn:ģ�����磺UART0 
//        baud: ������
//��  ��: ��                                                              
//��  ��: uart_init(UART4,115200);UART4��Ӧ���Ųο�UART.H�ļ�                                   
//-------------------------------------------------------------------------*

void uart_init (UARTn_e uratn, uint32 baud)
{
    register uint16 sbr, brfa;
    uint8 temp;
    uint32 sysclk;     //ʱ��

    /* ���� UART���ܵ� ���ùܽ� */
    switch(uratn)
    {
    case UART_0:
        SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;      //ʹ�� UART0 ʱ��

        if(UART0_RX == PTA1)
        {                    
            PORTA_PCR1= PORT_PCR_MUX(2);       //ʹ��PTA1���ŵڶ����ܣ���UART0_RXD
        }
        else if(UART0_RX == PTA15)
        {
             PORTA_PCR15= PORT_PCR_MUX(3);       //ʹ��PTA15���ŵ�3����
        }
        else if(UART0_RX == PTB16)
        {
             PORTB_PCR16= PORT_PCR_MUX(3);       //ʹ��PTB16���ŵ�3����
        }
        else if(UART0_RX == PTD6)
        {
             PORTD_PCR6= PORT_PCR_MUX(3);       //ʹ��PTD6���ŵ�3����
        }
        else
        {
            break;
        }

        if(UART0_TX == PTA2)
        {
             PORTA_PCR2= PORT_PCR_MUX(2);       //ʹ��PTA2���ŵڶ�����
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

    //���õ�ʱ��Ӧ�ý�ֹ���ͽ���
    UART_C2_REG(UARTN[uratn]) &= ~(0
                                   | UART_C2_TE_MASK
                                   | UART_C2_RE_MASK
                                  );


    //���ó�8λ��У��ģʽ
    //���� UART ���ݸ�ʽ��У�鷽ʽ��ֹͣλλ����ͨ������ UART ģ����ƼĴ��� C1 ʵ�֣�
    UART_C1_REG(UARTN[uratn]) |= (0
                                  //| UART_C2_M_MASK                    //9 λ�� 8 λģʽѡ�� : 0 Ϊ 8λ ��1 Ϊ 9λ��ע���˱�ʾ0����8λ�� �������9λ��λ8��UARTx_C3�
                                  //| UART_C2_PE_MASK                   //��żУ��ʹ�ܣ�ע���˱�ʾ���ã�
                                  //| UART_C2_PT_MASK                   //У��λ���� : 0 Ϊ żУ�� ��1 Ϊ ��У��
                                 );

    //���㲨���ʣ�����0��1ʹ���ں�ʱ�ӣ���������ʹ��busʱ��
    if ((uratn == UART_0) || (uratn == UART_1))
    {
        sysclk = (uint32)(core_clk_M * 1000*1000);                                   //�ں�ʱ��
    }
    else
    {
        sysclk = (uint32)(bus_clk_M * 1000*1000);                                    //busʱ��(���ں�ʱ�ӵ�һ��)
    }

    //UART ������ = UART ģ��ʱ�� / (16 �� (SBR[12:0] + BRFA))
    //������ BRFA ������£� SBR = UART ģ��ʱ�� / (16 * UART ������)
    sbr = (uint16)(sysclk / (baud * 16));
    if(sbr > 0x1FFF)sbr = 0x1FFF;                                       //SBR �� 13bit�����Ϊ 0x1FFF

    //��֪ SBR ���� BRFA =  = UART ģ��ʱ�� / UART ������ - 16 ��SBR[12:0]
    brfa = (sysclk / baud)  - (sbr * 16);
    

    //д SBR
    temp = UART_BDH_REG(UARTN[uratn]) & (~UART_BDH_SBR_MASK);           //���� ��� SBR �� UARTx_BDH��ֵ
    UART_BDH_REG(UARTN[uratn]) = temp |  UART_BDH_SBR(sbr >> 8);        //��д��SBR��λ
    UART_BDL_REG(UARTN[uratn]) = UART_BDL_SBR(sbr);                     //��д��SBR��λ

    //д BRFD
    temp = UART_C4_REG(UARTN[uratn]) & (~UART_C4_BRFA_MASK) ;           //���� ��� BRFA �� UARTx_C4 ��ֵ
    UART_C4_REG(UARTN[uratn]) = temp |  UART_C4_BRFA(brfa);             //д��BRFA



    //����FIFO(FIFO���������Ӳ�������ģ������������)
    UART_PFIFO_REG(UARTN[uratn]) |= (0
                                     | UART_PFIFO_TXFE_MASK               //ʹ��TX FIFO(ע�ͱ�ʾ��ֹ)
                                     //| UART_PFIFO_TXFIFOSIZE(0)         //��ֻ����TX FIFO ��С��0Ϊ1�ֽڣ�1~6Ϊ 2^(n+1)�ֽ�
                                     | UART_PFIFO_RXFE_MASK               //ʹ��RX FIFO(ע�ͱ�ʾ��ֹ)
                                     //| UART_PFIFO_RXFIFOSIZE(0)         //��ֻ����RX FIFO ��С��0Ϊ1�ֽڣ�1~6Ϊ 2^(n+1)�ֽ�
                                    );

    /* �����ͺͽ��� */
    UART_C2_REG(UARTN[uratn]) |= (0
                                  | UART_C2_TE_MASK                     //����ʹ��
                                  | UART_C2_RE_MASK                     //����ʹ��
                                  //| UART_C2_TIE_MASK                  //�����жϻ�DMA��������ʹ�ܣ�ע���˱�ʾ���ã�
                                  //| UART_C2_TCIE_MASK                 //��������ж�ʹ�ܣ�ע���˱�ʾ���ã�
                                  //| UART_C2_RIE_MASK                  //�������жϻ�DMA��������ʹ�ܣ�ע���˱�ʾ���ã�
                                 );


}

/*!
 *  @brief      �ȴ�����1���ֽ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART5��
 *  @since      v5.0
 *  @note       �����Ҫ��ѯ����״̬������ uart_query ��
                �����Ҫ��ѯ�������ݣ����� uart_querychar
 *  Sample usage:
                        char ch;
                        uart_getchar (UART3,&ch);   //�ȴ�����1���ֽڣ����浽 ch��
 */
char uart_getchar (UARTn_e uratn)
{
   while (!(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK));       //�ȴ���������   
   return(UART_D_REG(UARTN[uratn]));
}

/*!
 *  @brief      ��ѯ����1���ַ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @param      ch          ���յ�ַ
 *  @return     1Ϊ���ճɹ���0Ϊ����ʧ��
 *  @since      v5.0
 *  @note       �����Ҫ�ȴ����գ����� uart_getchar
 *  Sample usage:       char ch ;
                        if( uart_querychar (UART_3,&ch) == 1)     //��ѯ����1���ַ������浽 ch��
                        {
                            printf("�ɹ����յ�һ���ֽ�");
                        }
 */
char uart_querychar (UARTn_e uratn, char *ch)
{
    if( UART_RCFIFO_REG(UARTN[uratn]) )         //��ѯ�Ƿ���ܵ�����
    {
        *ch  =   UART_D_REG(UARTN[uratn]);      //���ܵ�8λ������
        return  1;                              //���� 1 ��ʾ���ճɹ�
    }

    *ch = 0;                                    //���ղ�����Ӧ������˽�����
    return 0;                                   //����0��ʾ����ʧ��
}

/*!
 *  @brief      ��ѯ�����ַ���
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @param      str         ���յ�ַ
 *  @param      max_len     �����ճ���
 *  @return     ���յ����ֽ���Ŀ
 *  @since      v5.0
 *  Sample usage:       char str[100];
                        uint32 num;
                        num = uart_querystr (UART_3,&str,100);
                        if( num != 0 )
                        {
                            printf("�ɹ����յ�%d���ֽ�:%s",num,str);
                        }
 */
uint32 uart_querystr (UARTn_e uratn, char *str, uint32 max_len)
{
    uint32 i = 0,j;

    for(j=0;j<10000;j++)                 // 10000 ����������ʱ�������и�������޸�
    {
        while(uart_querychar(uratn, str + i)  )
        {
            j=0;
            if( *(str + i) == NULL )    //���յ��ַ���������
            {
                return i;
            }

            i++;
            if(i >= max_len)            //�����趨�����ֵ���˳�
            {
                *(str + i) = 0;     //ȷ���ַ�����β��0x00
                return i;
            }
        }
    }

    *(str + i) = 0;                     //ȷ���ַ�����β��0x00
    return i;
}


/*!
 *  @brief      ��ѯ����buff
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @param      str         ���յ�ַ
 *  @param      max_len     �����ճ���
 *  @return     ���յ����ֽ���Ŀ
 *  @since      v5.0
 *  Sample usage:       char buff[100];
                        uint32 num;
                        num = uart_querybuff (UART_3,&buff,100);
                        if( num != 0 )
                        {
                            printf("�ɹ����յ�%d���ֽ�:%s",num,buff);
                        }
 */
uint32 uart_querybuff (UARTn_e uratn, char *buff, uint32 max_len)
{
    uint32 i = 0,j;
    for(j=0;j<10000;j++)                 // 10000 ����������ʱ�������и�������޸�
    {
        while(uart_querychar(uratn, buff + i)  )
        {
            i++;
            if(i >= max_len)            //�����趨�����ֵ���˳�
            {
                return i;
            }
        }
    }

    return i;
}


/*!
 *  @brief      ���ڷ���һ���ֽ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @param      ch          ��Ҫ���͵��ֽ�
 *  @since      v5.0
 *  @note       printf��Ҫ�õ��˺���
 *  @see        fputc
 *  Sample usage:       uart_putchar (UART_3, 'A');  //�����ֽ�'A'
 */
void uart_putchar (UARTn_e uratn, char ch)
{
    if(pSB) uart_sendbuffer_putchar(uratn,ch);
    else{
        //�ȴ����ͻ�������
        while(!(UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK));

        //��������
        UART_D_REG(UARTN[uratn]) = (uint8)ch;
    }
}

/*!
 *  @brief      ��ѯ�Ƿ���ܵ�һ���ֽ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @return     ���յ����ݷ���1��û���յ����ݷ���0
 *  @since      v5.0
 *  Sample usage:       char ch;
                        if(uart_query (UART_3) == 1)     //��ѯ�Ƿ���յ�����
                        {
                            ch = uart_getchar (UART_3);  //�ȴ�����һ�����ݣ����浽 ch��
                        }
 */
char uart_query (UARTn_e uratn)
{
    if(UART_RCFIFO_REG(UARTN[uratn]))                 //���յ�����������0
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
 *  @brief      ����ָ��len���ֽڳ������� ������ NULL Ҳ�ᷢ�ͣ�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @param      buff        �����ַ
 *  @param      len         ��������ĳ���
 *  @since      v5.0
 *  Sample usage:       uart_putbuff (UART_3,"1234567", 3); //ʵ�ʷ�����3���ֽ�'1','2','3'
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
 *  @brief      �����ַ���(�� NULL ֹͣ����)
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @param      str         �ַ�����ַ
 *  @since      v5.0
 *  Sample usage:       uart_putstr (UART_3,"1234567"); //ʵ�ʷ�����7���ֽ�
 */
void uart_putstr (UARTn_e uratn, const uint8 *str)
{
    while(*str)
    {
        uart_putchar(uratn, *str++);
    }
}

/*!
 *  @brief      �����ڽ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @since      v5.0
 *  Sample usage:       uart_rx_irq_en(UART_3);         //������3�����ж�
 */
void uart_rx_irq_en(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) |= UART_C2_RIE_MASK;                          //ʹ��UART�����ж�    
    NVIC_EnableIRQ(UART_IRQn[uratn]);                  //ʹ��IRQ�ж�
}

/*!
 *  @brief      �����ڷ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_en(UART_3);         //������3�����ж�
 */
void uart_tx_irq_en(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) |= UART_C2_TIE_MASK;                          //ʹ��UART�����ж�
    NVIC_EnableIRQ(UART_IRQn[uratn]);                  //ʹ��IRQ�ж�
}

/*!
 *  @brief      �����ڷ�������ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_en(UART_3);         //������3�����ж�
 */
void uart_txc_irq_en(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) |= UART_C2_TCIE_MASK;                         //ʹ��UART�����ж�
    NVIC_EnableIRQ(UART_IRQn[uratn]);                  //ʹ��IRQ�ж�
}

/*!
 *  @brief      �ش��ڽ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @since      v5.0
 *  Sample usage:       uart_rx_irq_dis(UART_3);         //�ش���3�����ж�
 */
void uart_rx_irq_dis(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) &= ~UART_C2_RIE_MASK;                         //��ֹUART�����ж�

    //��������жϻ�û�йأ��򲻹ر�IRQ
    if(!(UART_C2_REG(UARTN[uratn]) & (UART_C2_TIE_MASK | UART_C2_TCIE_MASK)) )
    {
        NVIC_DisableIRQ(UART_IRQn[uratn]);             //��IRQ�ж�
    }
}

/*!
 *  @brief      �ش��ڷ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_dis(UART_3);         //�ش���3�����ж�
 */
void uart_txc_irq_dis(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) &= ~UART_C2_TCIE_MASK;                        //��ֹUART��������ж�

    //��������жϻ�û�йأ��򲻹ر�IRQ
    if(!(UART_C2_REG(UARTN[uratn]) & UART_C2_RIE_MASK) )
    {
        NVIC_DisableIRQ(UART_IRQn[uratn]);             //��IRQ�ж�
    }
}

/*!
 *  @brief      �ش��ڷ����ж�
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @since      v5.0
 *  Sample usage:       uart_tx_irq_dis(UART_3);         //�ش���3�����ж�
 */
void uart_tx_irq_dis(UARTn_e uratn)
{
    UART_C2_REG(UARTN[uratn]) &= ~UART_C2_TIE_MASK;                         //��ֹUART�����ж�

    //��������жϻ�û�йأ��򲻹ر�IRQ
    if(!(UART_C2_REG(UARTN[uratn]) & UART_C2_RIE_MASK) )
    {
        NVIC_DisableIRQ(UART_IRQn[uratn]);             //��IRQ�ж�
    }
}

/*!
 *  @brief      ������ʾ��������һ������֡
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
 *  @param      wareaddr      ����֡�����׵�ַ
 *  @param      waresize      ����֡�����С����λ���ֽڣ�
 *  @since      v5.0
 *  Sample usage:       uart_sendware��UART_3,&floatnum,1*sizeof(float));   //�ڴ���3������ʾ��������һ��������
 */
void uart_sendware(UARTn_e uratn,void *wareaddr, uint32 waresize)
{
#define CMD_WARE     3
    uint8 cmdf[2] = {CMD_WARE, ~CMD_WARE};    //���ڵ��� ʹ�õ�ǰ����
    uint8 cmdr[2] = {~CMD_WARE, CMD_WARE};    //���ڵ��� ʹ�õĺ�����

    uart_putbuff(uratn, cmdf, sizeof(cmdf));    //�ȷ���ǰ����
    uart_putbuff(uratn, wareaddr, waresize);    //��������
    uart_putbuff(uratn, cmdr, sizeof(cmdr));    //���ͺ�����

}

/*!
 *  @brief      �÷�ͬprintf
 *  @param      UARTn_e       ģ��ţ�UART0~UART4��
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
���÷��ͻ�����Խ����ڵķ��ͷ�ʽ�ɳ����ѯ��Ϊ�жϣ��Ӷ���߷���Ч��
�����ԣ����жϷ�����ռ�õ�CPUʱ��ɺ��Բ���
�ܵ�ʵ�ʷ������ʵ����ƣ������ϴ��ڷ�������Ӧ������ ������/��1+8+1�� byte/s
������115200�Ĳ����ʣ�10ms��һ�����ݣ���ôÿ�η��������������ϲ����� 115200/10*0.01=115.2�ֽ�
��ʵ������������֮֡����ܴ��ڿ�϶���������������Ϊ ����ֵ*0.9
�ܵ���������С���ƣ����η������ݲ�Ҫ����255�ֽ�
�������ʹ���򵥴η������������󣬶��ᵼ�»��������
Ϊ��Ч�ʿ��ǣ��������������������κ���ʾ����ֱ�Ӷ�������������������
*/

/*!
 *  ��������	uart_sendbuffer_enable
 *  ��  �ܣ�	����UART���ͻ��湦��
 *  ��  �أ�	void
 *  ��  ����	UARTn_e uratn	ģ��ţ�UART0~UART4��
 *  ʱ  �䣺	2018-12-22 17:16
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
 *  ��������	uart_sendbuffer_disable
 *  ��  �ܣ�	����UART���ͻ��湦��
 *  ��  �أ�	void
 *  ��  ����	UARTn_e uratn	ģ��ţ�UART0~UART4��
 *  ʱ  �䣺	2018-12-22 17:18
 */
void uart_sendbuffer_disable(UARTn_e uratn)
{
    if(pSB==NULL) return;
    while (pSB->i!=pSB->j);//�ȴ����ݷ���
    free(pSB);
    pSB = NULL;
}

/*!
 *  ��������	uart_sendbuffer_isr
 *  ��  �ܣ�	UART���ͻ����жϷ�������ڶ�Ӧģ���жϷ����������øú�����
 *  ��  �أ�	void
 *  ��  ����	UARTn_e uratn	ģ��ţ�UART0~UART4��
 *  ʱ  �䣺	2018-12-22 17:24
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
 *  ��������	uart_sendbuffer_putchar
 *  ��  �ܣ�	ͨ�����ͻ��淢��һ���ַ����ڲ����ã�
 *  ��  �أ�	void
 *  ��  ����	UARTn_e uratn	ģ��ţ�UART0~UART4��
 *  ��  ����	char c	���͵��ֽ�
 *  ʱ  �䣺	2018-12-22 17:28
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

