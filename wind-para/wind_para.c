/****************************************Copyright (c)**************************************************
**                                       ��  ��  ��  ��
**
**                                       yzfcer@163.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: wind_para.c
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
#ifndef PARAM_DICTIONARY_H__
#define PARAM_DICTIONARY_H__
#include "wind_para.h"
#include "para_dictionary.h"

param_s sys_param;
DICT_ITEM_START(dic_tb)
DICT_ITEM(param_s,sys_param,w_int8_t,pch),
DICT_ITEM(param_s,sys_param,w_int16_t,pint16),
DICT_ITEM(param_s,sys_param,w_int32_t,pint32),
DICT_ITEM(param_s,sys_param,w_int64_t,pint64),
DICT_ITEM(param_s,sys_param,w_uint8_t,puch),
DICT_ITEM(param_s,sys_param,w_uint16_t,puint16),
DICT_ITEM(param_s,sys_param,w_uint32_t,puint32),
DICT_ITEM(param_s,sys_param,w_uint64_t,puint64),
DICT_ITEM(param_s,sys_param,w_bool_t,pbool),
DICT_ITEM(param_s,sys_param,w_int16_t,arr16),
DICT_ITEM(param_s,sys_param,w_uint32_t,arru32),
DICT_ITEM(param_s,sys_param,w_str16_t,str16),
DICT_ITEM(param_s,sys_param,w_str128_t,str128),
DICT_ITEM_END
DICT_DEFINE(sys_dict,dic_tb)

#endif

