//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
/*!                    �����ʵ��ѧ K66 ѧϰ����
 *  �ļ����ƣ�       wdog.c
 *      ���ߣ�       maddevil
 *      ˵����       �����ڲ�ѧϰʹ�ã������⴫
 *  �ο����ϣ�       ����ѧ�����롢ɽ��K60�⡢����K66ģ�塢����KEAģ��
 *    �汾�ţ�       V1.0.0
 *  �����£�       2018-12-21 13:41
 */
//QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4QlVQVC1LNjYgbWFkZGV2aWwgNzkzNTU4NzU4
#include "include.h"
#include "wdog.h"	//����wdog.hͷ�ļ�
       
//-------------------------------------------------------------------------*
//������: wdog_disable                                                     *
//��  ��: �رտ��Ź�ģ��                                                   * 
//��  ��: ��			  					   *	
//��  ��: ��                                                               *
//˵  ��: ��                                                               *
//-------------------------------------------------------------------------*
void wdog_disable(void)
{
    //�����Ź�ģ��������Ա�д�Ĵ���
    wdog_unlock();
    //�رտ��Ź�
    WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK;
}

//-------------------------------------------------------------------------*
//������: wdog_unlock                                                      *
//��  ��: ���Ź�����                                                       * 
//��  ��: ��							           *	
//��  ��: ��                                                               *
//˵  ��: ��                                                               *
//-------------------------------------------------------------------------*
void wdog_unlock(void)
{
    /* ע��: ��Ҫ�������Դ˳���!!! �����������CPU��λ*/
    //�����ж�
    DisableInterrupts;		
    //д�����Ĵ���
    WDOG_UNLOCK = 0xC520;	
    //��ɽ���
    WDOG_UNLOCK = 0xD928;	
    //�����ж�
    EnableInterrupts;		
}
