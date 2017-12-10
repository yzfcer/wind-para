/****************************************Copyright (c)**************************************************
**                                       清  风  海  岸
**
**                                       yzfcer@163.com
**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: wind_para.c
**创   建   人: Jason Zhou
**最后修改日期: 2017.12.10
**描        述: 
**              
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人: Jason Zhou
** 版  本: v1.0
** 日　期: 2017.12.10
** 描　述: 原始版本
**
**--------------当前版本修订----------------------------------------------------------------------------
** 修改人: Jason Zhou
** 日　期: 2017.12.10
** 描　述: 
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

