#include "include.h"
void Test_MPU6050(void)
{
  int16_t aacx,aacy,aacz;	//���ٶȴ�����ԭʼ����
  int16_t gyrox,gyroy,gyroz;	//������ԭʼ����
  MPU6050_Init();                          //��ʼ��MPU6050
  while(1)
  {
    MPU_Get_Raw_data(&aacx,&aacy,&aacz,&gyrox,&gyroy,&gyroz);	//�õ����ٶȴ���������
    UART_Put_Str(UART_4,(u8*)a);  //����������ʾ
    time_delay_ms(100);

  }
}