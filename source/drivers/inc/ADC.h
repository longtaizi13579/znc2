//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       ADC.h
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4


#ifndef __ADC_H__
#define __ADC_H__ 
typedef enum
{
    // ---------------------------------ADC0-------------------------
    
    RES13,          // 保留
    RES14,          // 保留
    RES15,          // 保留
    ADC0_DP3,       //ADC0_DP3
    //软件触发不支持B通道
    ADC0_SE4b,      // PTC2     不支持软件ADC
    ADC0_SE5b,      // PTD1     不支持软件ADC
    ADC0_SE6b,      // PTD5     不支持软件ADC
    ADC0_SE7b,      // PTD6     不支持软件ADC

    ADC0_SE8,       // PTB0
    ADC0_SE9,       // PTB1
    ADC0_SE10,      // PTA7
    ADC0_SE11,      // PTA8
    ADC0_SE12,      // PTB2
    ADC0_SE13,      // PTB3
    ADC0_SE14,      // PTC0
    ADC0_SE15,      // PTC1
    ADC0_SE16,      // ADC0_SE16
    ADC0_SE17,      // PTE24
    ADC0_SE18,      // PTE25
    ADC0_DM0,       // ADC1_DM3 
    RES0,           // 保留
    ADC0_SE21,      //ADC0_SE21
    ADC0_SE22,      //ADC0_SE22
    ADC0_SE23,      //ADC0_SE23
    RES1,           // 保留
    RES2,           // 保留
    Temp0_Sensor,   // Temperature Sensor,内部温度测量，可用ADC函数
    Bandgap0,       // 温度补偿结构带隙基准源   不支持ADC
    RES3,           // 保留
    VREFH0,         // 参考高电压,可用ADC函数 ,结果恒为 2^n-1
    VREFL0,         // 参考低电压,可用ADC函数 ,结果恒为 0
    Module0_Dis,    // 不支持 ADC

    // ---------------------------------ADC1-------------------------
    ADC1_DP0,
    RES4,           // 保留
    RES5,           // 保留
    RES6,           // 保留

    ADC1_SE4a,      // PTE0
    ADC1_SE5a,      // PTE1
    ADC1_SE6a,      // PTE2
    ADC1_SE7a,      // PTE3

    ADC1_SE4b = ADC1_SE4a,  // PTC8     不支持软件ADC ,传递 ADC1_SE4b 到软件ADC函数里，会当作 ADC1_SE4a 处理。
    ADC1_SE5b = ADC1_SE5a,  // PTC9     不支持软件ADC
    ADC1_SE6b = ADC1_SE6a,  // PTC10    不支持软件ADC
    ADC1_SE7b = ADC1_SE7a,  // PTC11    不支持软件ADC

    ADC1_SE8,       // PTB0
    ADC1_SE9,       // PTB1
    ADC1_SE10,      // PTB4
    ADC1_SE11,      // PTB5
    ADC1_SE12,      // PTB6
    ADC1_SE13,      // PTB7
    ADC1_SE14,      // PTB10
    ADC1_SE15,      // PTB11
    ADC1_SE16,      // ADC1_SE16
    ADC1_SE17,      // PTA17
    ADC1_SE18,      // ADC1_SE18
    ADC1_DM0,       // ADC0_DM3    
    RES7,           //保留
    RES8,           //保留
    RES9,           //保留
    ADC1_SE23,      //ADC1_SE23
    RES10,          //保留
    RES11,
    Temp1_Sensor,
    Bandgap1,       // 温度补偿结构带隙基准源   不支持ADC
    RES12,
    VREFH1,         // 参考高电压,可用ADC函数 ,结果恒为 2^n-1
    VREFL1,         // 参考低电压,可用ADC函数 ,结果恒为 0
    Module1_Dis,    // 不支持 ADC

} ADCn_Ch_e;

typedef enum  //ADC模块
{
    ADC0,
    ADC1
} ADCn_e;

//精度位数
typedef enum ADC_nbit
{
    ADC_8bit   = 0x00,
    ADC_10bit  = 0x02,
    ADC_12bit  = 0x01,
    ADC_16bit  = 0x03
} ADC_nbit;


//外部函数接口声明
extern void     adc_init    (ADCn_Ch_e);                //ADC初始化
extern uint16   adc_once    (ADCn_Ch_e, ADC_nbit);      //采集一次一路模拟量的AD值

extern void     adc_stop    (ADCn_e);                   //停止ADC转换


#endif 
