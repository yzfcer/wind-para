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

dic_item_s g_dic[] = 
{
    PARAM_ITEM(param_s,sys_param,w_int8_t,pch),
    PARAM_ITEM(param_s,sys_param,w_int16_t,pint16),
    PARAM_ITEM(param_s,sys_param,w_int32_t,pint32),
    PARAM_ITEM(param_s,sys_param,w_int64_t,pint64),
    PARAM_ITEM(param_s,sys_param,w_uint8_t,puch),
    PARAM_ITEM(param_s,sys_param,w_uint16_t,puint16),
    PARAM_ITEM(param_s,sys_param,w_uint32_t,puint32),
    PARAM_ITEM(param_s,sys_param,w_uint64_t,puint64),
    PARAM_ITEM(param_s,sys_param,w_bool_t,pbool),
    PARAM_ITEM(param_s,sys_param,w_int16_t,arr16),
    PARAM_ITEM(param_s,sys_param,w_uint32_t,arru32),
    PARAM_ITEM(param_s,sys_param,w_str16_t,str16),
    PARAM_ITEM(param_s,sys_param,w_str128_t,str128),
};


#endif

