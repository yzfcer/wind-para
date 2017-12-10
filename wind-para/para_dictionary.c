/****************************************Copyright (c)**************************************************
**                                       ��  ��  ��  ��
**
**                                       yzfcer@163.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: para_dictionary.c
**��   ��   ��: Jason Zhou
**����޸�����: 2017.12.10
**��        ��: 
**              
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: 
** ��  ��: v1.0
** �ա���: 2017.12.10
** �衡��: ԭʼ�汾
**
**--------------��ǰ�汾�޶�----------------------------------------------------------------------------
** �޸���: 
** �ա���: 2017.12.10
** �衡��: 
**
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
#include "wind_string.h"
#include "wind_debug.h"
#include "para_dictionary.h"

w_bool_t param_set(para_dic_s *dic,char *name,void *value)
{
    w_int32_t i;
	w_int32_t count = dic->count;
    for(i = 0;i < count;i ++)
    {
        if(wind_strcmp(name,dic->item[i].name) == 0)
        {
            wind_memcpy(dic->item[i].ptr,value,dic->item[i].count*dic->item[i].itemsize);
            return B_TRUE;
        }
    }
    return B_FALSE;
}

w_bool_t param_get(para_dic_s *dic,char *name,void *value)
{
    w_int32_t i;
	w_int32_t count = dic->count;
    for(i = 0;i < count;i ++)
    {
        if(wind_strcmp(name,dic->item[i].name) == 0)
        {
            wind_memcpy(value,dic->item[i].ptr,dic->item[i].count*dic->item[i].itemsize);
            return B_TRUE;
        }
    }
    return B_FALSE;
}

static void print_int8_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_int8_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%d ",va[i]);
}

static void print_uint8_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_uint8_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%u ",va[i]);
}

static void print_int16_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_int16_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%d ",va[i]);
}

static void print_uint16_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_uint16_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%u ",va[i]);
}

static void print_int32_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_int32_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%ld ",va[i]);
}

static void print_uint32_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_uint32_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%lu ",va[i]);
}

static void print_int64_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_int64_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%lld ",va[i]);
}

static void print_uint64_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_uint64_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%llu ",va[i]);
}

static void print_bool_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_bool_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%s ",va[i]?"true":"false");
}

static void print_string_arr(dic_item_s *dic)
{
    w_int32_t i;
    w_str128_t *va = dic->ptr;
    for(i = 0;i < dic->count;i ++)
        wind_printf("%s ",va[i]);
}

void param_print(para_dic_s *dic)
{
    w_int32_t i,j;
    w_int32_t count = dic->count;
    for(i = 0;i < count;i ++)
    {
        wind_printf("%s=",dic->item[i].name);
        for(j = 0;j < dic->item[i].count;j ++)
        {
            switch(dic->item[i].type)
            {
                case TYPE_w_int8_t:
                    print_int8_arr(&dic->item[i]);
                    break;
                case TYPE_w_int16_t:
                    print_int16_arr(&dic->item[i]);
                    break;
                case TYPE_w_int32_t:
                    print_int32_arr(&dic->item[i]);
                    break;
                case TYPE_w_int64_t:
                    print_int64_arr(&dic->item[i]);
                    break;
                case TYPE_w_uint8_t:
                    print_uint8_arr(&dic->item[i]);
                    break;
                case TYPE_w_uint16_t:
                    print_uint16_arr(&dic->item[i]);
                    break;
                case TYPE_w_uint32_t:
                    print_uint32_arr(&dic->item[i]);
                    break;
                case TYPE_w_uint64_t:
                    print_uint64_arr(&dic->item[i]);
                    break;
                case TYPE_w_bool_t:
                    print_bool_arr(&dic->item[i]);
                    break;
                case TYPE_w_str16_t:
                case TYPE_w_str32_t:
                case TYPE_w_str64_t:
                case TYPE_w_str128_t:
                case TYPE_w_str256_t:
                    print_string_arr(&dic->item[i]);
                    break;
                default:
                    wind_printf("undefined param type:%d\r\n",dic->item[i].type);
                    break;
            }
            wind_printf("\r\n");
        }
    }
}
