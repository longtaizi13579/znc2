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
#ifndef __FUNC_H__
#define __FUNC_H__

#include "common.h"
#include "lptmr.h"

#define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )              //�����ֵ
#define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )              //����Сֵ
#define ABS(x) ((x)<0?-(x):(x))                            //����ֵ����������x�ľ���ֵ
#define LMT(x,a,b) ((x)<(a)?(a):((x)>(b)?(b):(x)))           //��x������a��b֮��
#define delayms(x) time_delay_ms(x)

extern int32 A2I(const char * str);	//���ַ���ת��Ϊ����
extern double A2F(const char * str);	//���ַ���ת��Ϊ������
extern int Sprintf(char * szBuffer, const char * szFormat, ...);	//IAR �Դ���sprintf�޷�ת��%f��%e

#endif // !__FUNC_H__