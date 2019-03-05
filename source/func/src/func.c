//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       func.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "func.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*!
 *  ��������	A2I
 *  ��  �ܣ�	���ַ���ת��Ϊ����
 *  ��  �أ�	int32
 *  ��  ����	const char * str	��ת�����ַ���
 *  ʱ  �䣺	2018-12-22 19:38
 */
int32 A2I(const char * str)
{
  int8 sign;
  int32 n=0;
  while(isspace(*str))str++;//�����հ׷�;
  sign=(*str=='-')?-1:1;
  if(*str=='+'||*str=='-') str++;//�������� 
  while(isspace(*str))str++;//�����հ׷�;
  for(n=0;*str>='0'&&*str<='9';str++)
    n=10*n+(*str-'0');//�������ַ�ת������������
  return sign *n;
}

/*!
 *  ��������	A2F
 *  ��  �ܣ�	���ַ���ת��Ϊ������
 *  ��  �أ�	double
 *  ��  ����	const char * str	��ת�����ַ���
 *  ʱ  �䣺	2018-12-22 19:39
 */
double A2F(const char * str)
{
	double s = 0.0;
	double d = 10.0;
	int16 indices = 0, sign = 0;	
	while (isspace(*str))str++;//�����հ׷�;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-') str++;//�������� 
	if (!(*str >= '0'&&*str <= '9'))//���һ��ʼ���������˳�������0.0
		return s;

	while (*str >= '0'&&*str <= '9'&&*str != '.')//����С����ǰ��������
	{
		s = s * 10.0 + *str - '0';
		str++;
	}

	if (*str == '.')//�Ժ�ΪС������
		str++;

	while (*str >= '0'&&*str <= '9')//����С������
	{
		s = s + (*str - '0') / d;
		d *= 10.0;
		str++;
	}

	if (*str == 'e' || *str == 'E')//���ǿ�ѧ������
	{
		str++;		
		for (indices = A2I(str); indices > 0; --indices)
			s *= 10.0;
		for (; indices < 0; ++indices)
			s /= 10.0;
	}
	return s * sign;
}

/*!
 *  ��������	Sprintf
 *  ��  �ܣ�	IAR �Դ���sprintf�޷�ת��%f��%e
 *  ��  �أ�	int
 *  ��  ����	char * szBuffer	
 *  ��  ����	const char * szFormat	
 *  ��  ����	...	
 *  ʱ  �䣺	2018-12-22 19:41
 */
int Sprintf(char * szBuffer, const char * szFormat, ...)
{
	int iReturn; 
	va_list pArgs; 
	va_start(pArgs, szFormat); 
	iReturn = vsprintf(szBuffer, szFormat, pArgs); 
	va_end(pArgs); 
	return iReturn;
}