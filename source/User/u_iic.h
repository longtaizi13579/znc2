#ifndef __U_IIC_H
#define __U_IIC_H


#include "include.h"

#define SDA_PORT  PTB_BASE_PTR    //SDAʹ��A�˿�     1.�޸�ģ��IIC����ʱ��Ҫ�޸�
#define SDA_INDEX 3      //SDAʹ��A18����
#define SCL_PORT  PTB_BASE_PTR    //SCLʹ��A�˿�
#define SCL_INDEX 2      //SCLʹ��A19����
//����MPU6050�ӿڣ�GPIOģ��IIC

#define SDA_IN()  {GPIO_PDDR_REG(SDA_PORT) &= ~(1<<SDA_INDEX);}	//����
#define SDA_OUT() {GPIO_PDDR_REG(SDA_PORT) |= (1<<SDA_INDEX);} //���

//IO��������	 
#define IIC_SCL    PTB2_OUT //SCL             2.�޸�ģ��iic����ʱ��Ҫ�޸�
#define IIC_SDA    PTB3_OUT //SDA	 
#define READ_SDA   PTB3_IN  //����SDA 

//IIC_1���в�������
void IIC_Init(void);        //��ʼ��IIC��IO��3.�޸�ģ��iic����ʱ��Ҫ�޸�			 
void IIC_Start(void);			  //����IIC��ʼ�ź�
void IIC_Stop(void);	  	  //����IICֹͣ�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�
uint8_t IIC_WaitAck(void); 		 //IIC�ȴ�ACK�ź�
void IIC_SendByte(uint8_t data);  //IIC����һ���ֽ�
uint8_t IIC_ReadByte(uint8_t ack);//IIC��ȡһ���ֽ�
uint8_t IIC_ReadByteFromSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t *buf);
uint8_t IIC_ReadMultByteFromSlave(uint8_t dev, uint8_t reg, uint8_t length, uint8_t *data);
uint8_t IIC_WriteByteToSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t buf);
uint8_t IIC_WriteMultByteToSlave(uint8_t dev, uint8_t reg, uint8_t length, uint8_t* data);



#endif