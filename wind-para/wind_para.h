/****************************************Copyright (c)**************************************************
**                                       ��  ��  ��  ��
**
**                                       yzfcer@163.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: wind_para.h
**��   ��   ��: Jason Zhou
**����޸�����: 2017.12.10
**��        ��: 
**              
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: Jason Zhou
** ��  ��: v1.0
** �ա���: 2017.12.10
** �衡��: ԭʼ�汾
**
**--------------��ǰ�汾�޶�----------------------------------------------------------------------------
** �޸���: Jason Zhou
** �ա���: 2017.12.10
** �衡��: 
**
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
#ifndef WIND_PARA_H__
#define WIND_PARA_H__
#include "wind_type.h"
typedef struct
{
    w_int8_t pch;
    w_int16_t pint16;
    w_int32_t pint32;
    w_int64_t pint64;
    w_uint8_t puch;
    w_uint16_t puint16;
    w_uint32_t puint32;
    w_uint64_t puint64;
    w_bool_t pbool;
    w_int16_t arr16[4];
    w_uint32_t arru32[3];
    w_str16_t str16;
    w_str128_t str128;
}param_s;


#endif