//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       main.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */                                         
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4


#include "include.h" 
//主函数
#define test_port UART_0
//#if -#elif -#endif  是预编译命令， 1表示要编译的内容，测试I2C
#if 0
//串口打印 “Hello world!”
void main()
{
  DisableInterrupts;  
  uint8_t res;
  uart_init(test_port, 115200);
  Test_MPU6050();                //测试龙邱六轴MPU6050，OLED刷新数据
  EnableInterrupts;
  while(1)
  {
  }
}
#elif 0       
//gpio,电平输入输出控制
void main()
{
  int result;
  DisableInterrupts;  
  uart_init(test_port, 115200);
  uart_printf(test_port, "GPIO 测试\n");
 
  //GPO
  gpio_init (PTD7, GPO, HIGH);         //初始化并点亮二极管
  gpio_init (PTC15, GPO, LOW);
  //GPI
  gpio_init (PTA4, GPI, LOW);      //电平读取， 初始化LOW, HIGH没有意义
  
  result = gpio_get(PTA4);            //读取某个拨码开关的值
  uart_printf(test_port, "%d\n", result);
  while(1);
  
  EnableInterrupts;
  while(1)                                //1s翻转一次，延时为不精确控制，精确控制见PIT
  {
     gpio_turn(PTC15);
     delayms(1000);
  }
}
#elif 0
//模拟、数字转换， ADC
#define AD_CH   ADC1_DM0
void main()
{
  DisableInterrupts;  
  uart_init(test_port, 115200);
  ftm_pwm_init(FTM3, FTM_CH1, 50,0);
  //uart_printf(test_port, "ADC 测试\n");
  //初始化ADC1_SE18,ADC1_SE16,ADC0_DP3,ADC1_DM3
  adc_init(AD_CH);
  adc_init(ADC0_DP3);
  adc_init(ADC1_SE18);
  adc_init(ADC1_SE16);
  pit_init(PIT0, 100);               //所有中断都一样，在main函数初始化，在isr.h isr.c声明和定义
  //使能PIT  正常使用PIT时务必打开使能
  pit_irq_en(PIT0);
  motor_init();
  PWMSetMotor2(4500,4500); 
  EnableInterrupts;
  while(1)
  {
  }
}
#elif 0
//方波的输入与输出  FTM模块 750（右） -1020（左）
void main()
{  
  DisableInterrupts;  
  uart_init(test_port, 115200);
  //ftm_pwm_init(FTM1, FTM_CH1, 50,0);
  ftm_pwm_init(FTM3, FTM_CH1, 50,0);//PTE6
  delayms(1000);
  int duty = 885;
  //其他对频率与占空比修饰的函数、注意事项见FTM.c
  EnableInterrupts;
  while(1)
  {
    //duty = duty + 10;
    ftm_pwm_duty(FTM3, FTM_CH1,duty);
    //if (duty >1050)
      //duty = 750;
    uart_printf(test_port, "占空比：%d\n",duty);
    delayms(1000);
  }
}
#elif 0
//外部中断 EXTI
void main()
{
  DisableInterrupts;  
  uart_init(test_port, 115200);
  uart_printf(test_port, "EXTI 测试\n");
  
  //初始化
  exti_enable(PTE0,IRQ_FALLING|PULLUP);//下降沿触发，内部上拉（见port.h）
  EnableInterrupts;
  while(1)
  {
  }
}
#elif 0
//内部定时中断  PIT
void main()
{
  DisableInterrupts;  
  uart_init(test_port, 115200);
  uart_printf(test_port, "PIT测试\n");
  
  //初始化PIT0 ,  2Hz  
  //0.5s进入一次中断
  pit_init(PIT0, 2);               //所有中断都一样，在main函数初始化，在isr.h isr.c声明和定义
  //使能PIT  正常使用PIT时务必打开使能
  pit_irq_en(PIT0);
  
  EnableInterrupts;
  while(1)
  {
    
  }
}

#elif 0
//串口中断  UART_IRQ
void main()
{
  DisableInterrupts;
  uart_init(test_port, 115200);
  uart_rx_irq_en(test_port);    //串口中断
  EnableInterrupts;
  while(1)
  {}
}

#elif 0
//测试motor
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
//测试舵机
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
//测试编码器
void main()
{
  DisableInterrupts;
  //motor_init();
  //PWMSetMotor2(5000,5000); 
  uart_init(test_port, 115200);
  ftm_quad_init(FTM1);//初始化正交解码模块ftm1:
  ftm_quad_init(FTM2);//初始化正交解码模块ftm1:
  EnableInterrupts;
  while(1)
  {
    //得到正交解码,脉冲数值并输出：
    int16 speed1 = ftm_quad_get(FTM1);
    int16 speed2 = (-1) * ftm_quad_get(FTM2);
    uart_printf(test_port, "speed1 = %d ， speed2 = %d\n",speed1,speed2); 
    //清空ftm计数器
    ftm_quad_clean(FTM1);
    ftm_quad_clean(FTM2);
    delayms(200);//短暂延迟
  
  }
}
#elif 0 //测试摄像头
void main(void)
{    
    
  DisableInterrupts;           //关闭中断
  PLL_Init(PLL220);            //初始化PLL为?M,总线为？M
  uart_init(test_port,115200);    //UART初始化
  //LQMT9V034_Init();            //摄像头初始化   
  EnableInterrupts;            //开启中断
  
  Test_LQV034();               //测试龙邱神眼摄像头 TFT显示二值化图像 
  
  while(1)
  { 
    //LED_Ctrl(LED1, RVS);       //LED指示程序运行状态
    
  }
}

#elif 0
//串口缓存发送 uart_sendbuffer
void main(void)
{
   DisableInterrupts;        //关闭总中断
          
   pit_init(PIT0, 100);      
   uart_init  (test_port,9600);       
   uart_sendbuffer_enable(test_port);  //开启发送缓存（详细说明在UART.C）
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