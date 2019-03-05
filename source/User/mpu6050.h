#ifndef __LQMPU6050_H
#define __LQMPU6050_H		

#define MPU6050_ADDR  0xd1  //IIC写入时的地址字节数据，+1为读取
#define MPU6050_ID    0x68	//IIC地址寄存器(默认数值0x68，只读)
#define WHO_AM_I      0X75	//器件ID寄存器
uint8_t MPU_Read_Byte(uint8_t devaddr,uint8_t reg);
#endif