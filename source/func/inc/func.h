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
#ifndef __FUNC_H__
#define __FUNC_H__

#include "common.h"
#include "lptmr.h"

#define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )              //求最大值
#define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )              //求最小值
#define ABS(x) ((x)<0?-(x):(x))                            //绝对值函数，返回x的绝对值
#define LMT(x,a,b) ((x)<(a)?(a):((x)>(b)?(b):(x)))           //将x限制在a到b之间
#define delayms(x) time_delay_ms(x)

extern int32 A2I(const char * str);	//将字符串转换为整数
extern double A2F(const char * str);	//将字符串转换为浮点数
extern int Sprintf(char * szBuffer, const char * szFormat, ...);	//IAR 自带的sprintf无法转换%f和%e

#endif // !__FUNC_H__