#include "include.h"
void Test_MPU6050(void)
{
  int16_t aacx,aacy,aacz;	//加速度传感器原始数据
  int16_t gyrox,gyroy,gyroz;	//陀螺仪原始数据
  MPU6050_Init();                          //初始化MPU6050
  while(1)
  {
    MPU_Get_Raw_data(&aacx,&aacy,&aacz,&gyrox,&gyroy,&gyroz);	//得到加速度传感器数据
    UART_Put_Str(UART_4,(u8*)a);  //串口助手显示
    time_delay_ms(100);

  }
}