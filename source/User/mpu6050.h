#ifndef __LQMPU6050_H
#define __LQMPU6050_H		

#define MPU6050_ADDR  0xd1  //IICд��ʱ�ĵ�ַ�ֽ����ݣ�+1Ϊ��ȡ
#define MPU6050_ID    0x68	//IIC��ַ�Ĵ���(Ĭ����ֵ0x68��ֻ��)
#define WHO_AM_I      0X75	//����ID�Ĵ���
uint8_t MPU_Read_Byte(uint8_t devaddr,uint8_t reg);
#endif