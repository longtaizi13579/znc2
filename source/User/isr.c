//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       isr.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4

#include "isr.h"

//UART0~UART4 �����жϷ�����
void UART0_ISR(void){}
void UART1_ISR(void){}
void UART2_ISR(void){}
void UART3_ISR(void){}
void UART4_ISR(void)
{
    UARTn_e uratn = UART_4;//UART0 �жϷ�����
    if(UART_S1_REG(UARTN[uratn]) & UART_S1_RDRF_MASK)   //�������ݼĴ�����
    {
        //�û���Ҫ�����������
      uart_putchar(uratn,uart_getchar(uratn));//����

    }

    if(UART_S1_REG(UARTN[uratn]) & UART_S1_TDRE_MASK )  //�������ݼĴ�����
    {
        //�û���Ҫ����������
      uart_sendbuffer_isr(uratn);//���ͻ����жϴ�����

    }

}
/***********************************************************************************/
//PORTA~PORTE �˿��жϷ�����
void PORTA_ISR(void){}
void PORTB_ISR(void)
{

    uint8  n = 3;    //���ź�
    //PTB3
   
    if(PORTB_ISFR & (1 << n))           //PTE0�����ж�
    {
        PORTB_ISFR  |= (1 << n);        //д1���жϱ�־λ

        /*  ����Ϊ�û�����  */


        /*  ����Ϊ�û�����  */
    }
}
void PORTC_ISR(void){}

void PORTE_ISR(void)
{
}



/*!
 *  ��������	LPTMR_ISR
 *  ��  �ܣ�	LPTMR�жϷ�����
 *  ��  �أ�	void
 *  ʱ  �䣺	2018-12-21 20:17
 */
void LPTMR_ISR(){}



/*!
 *  ��������	DMA0_ISR
 *  ��  �ܣ�	DMA0�жϷ�����
 *  ��  �أ�	void
 *  ʱ  �䣺	2018-12-22 16:17
 */
void DMA0_ISR()
{

}


/*!
 *  ��������	FTM0_ISR
 *  ��  �ܣ�	FTM0�жϷ�����
 *  ��  �أ�	void
 *  ʱ  �䣺	2018-12-22 16:18
 */
void FTM0_ISR()
{
    uint8 s = FTM0_STATUS;             //��ȡ��׽�ͱȽ�״̬  All CHnF bits can be checked using only one read of STATUS.
    uint8 CHn;

    FTM0_STATUS = 0x00;             //���жϱ�־λ

    CHn = 0;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_DIS(FTM1, CHn);     //��ֹ���벶׽�ж�
        /*     �û�����       */

        /*********************/
        //FTM_IRQ_EN(FTM1, CHn); //�������벶׽�ж�

    }

    /* ������� n=1 ��ģ�棬����ģ������� */
    CHn = 1;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_EN(FTM1, CHn); //�������벶׽�ж�
        /*     �û�����       */


        /*********************/
        //�����������￪�����벶׽�ж�
        //FTM_IRQ_EN(FTM1, CHn); //�������벶׽�ж�
    }
}

/*!
 *  ��������	PIT0_ISR
 *  ��  �ܣ�	PIT0�жϷ�����
 *  ��  �أ�	void
 *  ʱ  �䣺	2018-12-22 16:45
 */
int time_count = 0;
float left_speed_in = 0, left_speed_out = 0, left_speed_set = 180;
float right_speed_in = 0, right_speed_out = 0, right_speed_set = 180;
pid_t pid1,pid2;
void PIT0_ISR()
{
    PIT_Flag_Clear(PIT0);//���жϱ�־λ 
   /*if(time_count == 10)
    {
      left_speed_in = (float)ftm_quad_get(FTM1);
      right_speed_in = -(float)ftm_quad_get(FTM2);
      
      pid_compute(pid1);//��
      pid_compute(pid2);//��
      PWMSetMotor2((s32)right_speed_out,(s32)left_speed_out); 
      //uart_printf(UART_0, "%f %f\n",left_speed_in,right_speed_in);
      //���ftm������
      ftm_quad_clean(FTM1);
      ftm_quad_clean(FTM2);
      time_count = 0;
    }
    time_count = time_count + 1;*/
    PWMSetMotor2(4000,4000);
    //����
    int adc1 = 0, adc2 = 0, adc3 = 0,adc4=0;
    adc1 = adc_once(ADC1_DM0, ADC_8bit);     //ͨ��drivers_cfg.h�ҵ�����E0��Ӧ��ADC��Դ ��ADC1_AD4a
    adc2 = adc_once(ADC0_DP3, ADC_8bit);
    adc3 = adc_once(ADC1_SE18, ADC_8bit);
    adc4 = adc_once(ADC1_SE16, ADC_8bit);
    //uart_printf(UART_0, "%d %d %d %d\n",adc1,adc2,adc3,adc4);
    direction_control(adc3+adc4 , adc1+adc2);  
}
