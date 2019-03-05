//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       main.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */                                         
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4


#include "include.h" 
//������
#define test_port UART_0
//#if -#elif -#endif  ��Ԥ������� 1��ʾҪ��������ݣ�����I2C
#if 0
//���ڴ�ӡ ��Hello world!��
void main()
{
  DisableInterrupts;  
  uint8_t res;
  uart_init(test_port, 115200);
  Test_MPU6050();                //������������MPU6050��OLEDˢ������
  EnableInterrupts;
  while(1)
  {
  }
}
#elif 0       
//gpio,��ƽ�����������
void main()
{
  int result;
  DisableInterrupts;  
  uart_init(test_port, 115200);
  uart_printf(test_port, "GPIO ����\n");
 
  //GPO
  gpio_init (PTD7, GPO, HIGH);         //��ʼ��������������
  gpio_init (PTC15, GPO, LOW);
  //GPI
  gpio_init (PTA4, GPI, LOW);      //��ƽ��ȡ�� ��ʼ��LOW, HIGHû������
  
  result = gpio_get(PTA4);            //��ȡĳ�����뿪�ص�ֵ
  uart_printf(test_port, "%d\n", result);
  while(1);
  
  EnableInterrupts;
  while(1)                                //1s��תһ�Σ���ʱΪ����ȷ���ƣ���ȷ���Ƽ�PIT
  {
     gpio_turn(PTC15);
     delayms(1000);
  }
}
#elif 0
//ģ�⡢����ת���� ADC
#define AD_CH   ADC1_DM0
void main()
{
  DisableInterrupts;  
  uart_init(test_port, 115200);
  ftm_pwm_init(FTM3, FTM_CH1, 50,0);
  //uart_printf(test_port, "ADC ����\n");
  //��ʼ��ADC1_SE18,ADC1_SE16,ADC0_DP3,ADC1_DM3
  adc_init(AD_CH);
  adc_init(ADC0_DP3);
  adc_init(ADC1_SE18);
  adc_init(ADC1_SE16);
  pit_init(PIT0, 100);               //�����ж϶�һ������main������ʼ������isr.h isr.c�����Ͷ���
  //ʹ��PIT  ����ʹ��PITʱ��ش�ʹ��
  pit_irq_en(PIT0);
  motor_init();
  PWMSetMotor2(4500,4500); 
  EnableInterrupts;
  while(1)
  {
  }
}
#elif 0
//���������������  FTMģ�� 750���ң� -1020����
void main()
{  
  DisableInterrupts;  
  uart_init(test_port, 115200);
  //ftm_pwm_init(FTM1, FTM_CH1, 50,0);
  ftm_pwm_init(FTM3, FTM_CH1, 50,0);//PTE6
  delayms(1000);
  int duty = 885;
  //������Ƶ����ռ�ձ����εĺ�����ע�������FTM.c
  EnableInterrupts;
  while(1)
  {
    //duty = duty + 10;
    ftm_pwm_duty(FTM3, FTM_CH1,duty);
    //if (duty >1050)
      //duty = 750;
    uart_printf(test_port, "ռ�ձȣ�%d\n",duty);
    delayms(1000);
  }
}
#elif 0
//�ⲿ�ж� EXTI
void main()
{
  DisableInterrupts;  
  uart_init(test_port, 115200);
  uart_printf(test_port, "EXTI ����\n");
  
  //��ʼ��
  exti_enable(PTE0,IRQ_FALLING|PULLUP);//�½��ش������ڲ���������port.h��
  EnableInterrupts;
  while(1)
  {
  }
}
#elif 0
//�ڲ���ʱ�ж�  PIT
void main()
{
  DisableInterrupts;  
  uart_init(test_port, 115200);
  uart_printf(test_port, "PIT����\n");
  
  //��ʼ��PIT0 ,  2Hz  
  //0.5s����һ���ж�
  pit_init(PIT0, 2);               //�����ж϶�һ������main������ʼ������isr.h isr.c�����Ͷ���
  //ʹ��PIT  ����ʹ��PITʱ��ش�ʹ��
  pit_irq_en(PIT0);
  
  EnableInterrupts;
  while(1)
  {
    
  }
}

#elif 0
//�����ж�  UART_IRQ
void main()
{
  DisableInterrupts;
  uart_init(test_port, 115200);
  uart_rx_irq_en(test_port);    //�����ж�
  EnableInterrupts;
  while(1)
  {}
}

#elif 0
//����motor
void main()
{
  DisableInterrupts;
  motor_init();
  PWMSetMotor2(5000,5000); 
  EnableInterrupts;
  while(1)
  {}
}

#elif 0
//���Զ��
void main()
{
  DisableInterrupts;
  ftm_pwm_init();
  PWMSetMotor2(5000,5000); 
  EnableInterrupts;
  while(1)
  {}
}
#elif 1
//���Ա�����
void main()
{
  DisableInterrupts;
  //motor_init();
  //PWMSetMotor2(5000,5000); 
  uart_init(test_port, 115200);
  ftm_quad_init(FTM1);//��ʼ����������ģ��ftm1:
  ftm_quad_init(FTM2);//��ʼ����������ģ��ftm1:
  EnableInterrupts;
  while(1)
  {
    //�õ���������,������ֵ�������
    int16 speed1 = ftm_quad_get(FTM1);
    int16 speed2 = (-1) * ftm_quad_get(FTM2);
    uart_printf(test_port, "speed1 = %d �� speed2 = %d\n",speed1,speed2); 
    //���ftm������
    ftm_quad_clean(FTM1);
    ftm_quad_clean(FTM2);
    delayms(200);//�����ӳ�
  
  }
}
#elif 0 //��������ͷ
void main(void)
{    
    
  DisableInterrupts;           //�ر��ж�
  PLL_Init(PLL220);            //��ʼ��PLLΪ?M,����Ϊ��M
  uart_init(test_port,115200);    //UART��ʼ��
  //LQMT9V034_Init();            //����ͷ��ʼ��   
  EnableInterrupts;            //�����ж�
  
  Test_LQV034();               //����������������ͷ TFT��ʾ��ֵ��ͼ�� 
  
  while(1)
  { 
    //LED_Ctrl(LED1, RVS);       //LEDָʾ��������״̬
    
  }
}

#elif 0
//���ڻ��淢�� uart_sendbuffer
void main(void)
{
   DisableInterrupts;        //�ر����ж�
          
   pit_init(PIT0, 100);      
   uart_init  (test_port,9600);       
   uart_sendbuffer_enable(test_port);  //�������ͻ��棨��ϸ˵����UART.C��
   EnableInterrupts;  
   pit_irq_en(PIT0);
   int16 i=0;
   while(1)
   {
      ++i;
      delayms(1);
   }
}
#endif