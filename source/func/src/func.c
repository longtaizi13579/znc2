//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    北京邮电大学 K66 学习例程
 *  文件名称：       func.c
 *      作者：       maddevil
 *      说明：       仅做内部学习使用，请勿外传
 *  参考资料：       历届学长代码、山外K60库、龙邱K66模板、北邮KEA模板
 *    版本号：       V1.0.0
 *  最后更新：       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "func.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*!
 *  函数名：	A2I
 *  功  能：	将字符串转换为整数
 *  返  回：	int32
 *  参  数：	const char * str	待转换的字符串
 *  时  间：	2018-12-22 19:38
 */
int32 A2I(const char * str)
{
  int8 sign;
  int32 n=0;
  while(isspace(*str))str++;//跳过空白符;
  sign=(*str=='-')?-1:1;
  if(*str=='+'||*str=='-') str++;//跳过符号 
  while(isspace(*str))str++;//跳过空白符;
  for(n=0;*str>='0'&&*str<='9';str++)
    n=10*n+(*str-'0');//将数字字符转换成整形数字
  return sign *n;
}

/*!
 *  函数名：	A2F
 *  功  能：	将字符串转换为浮点数
 *  返  回：	double
 *  参  数：	const char * str	待转换的字符串
 *  时  间：	2018-12-22 19:39
 */
double A2F(const char * str)
{
	double s = 0.0;
	double d = 10.0;
	int16 indices = 0, sign = 0;	
	while (isspace(*str))str++;//跳过空白符;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-') str++;//跳过符号 
	if (!(*str >= '0'&&*str <= '9'))//如果一开始非数字则退出，返回0.0
		return s;

	while (*str >= '0'&&*str <= '9'&&*str != '.')//计算小数点前整数部分
	{
		s = s * 10.0 + *str - '0';
		str++;
	}

	if (*str == '.')//以后为小数部分
		str++;

	while (*str >= '0'&&*str <= '9')//计算小数部分
	{
		s = s + (*str - '0') / d;
		d *= 10.0;
		str++;
	}

	if (*str == 'e' || *str == 'E')//考虑科学计数法
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
 *  函数名：	Sprintf
 *  功  能：	IAR 自带的sprintf无法转换%f和%e
 *  返  回：	int
 *  参  数：	char * szBuffer	
 *  参  数：	const char * szFormat	
 *  参  数：	...	
 *  时  间：	2018-12-22 19:41
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