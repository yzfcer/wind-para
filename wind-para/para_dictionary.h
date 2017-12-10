/****************************************Copyright (c)**************************************************
**                                       ��  ��  ��  ��
**
**                                       yzfcer@163.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: para_dictionary.h
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
#include "wind_type.h"
typedef enum 
{
    TYPE_w_int8_t = 0x01,
    TYPE_w_int16_t ,
    TYPE_w_int32_t ,
    TYPE_w_int64_t ,

    TYPE_w_uint8_t ,
    TYPE_w_uint16_t ,
    TYPE_w_uint32_t ,
    TYPE_w_uint64_t ,

    TYPE_w_bool_t ,
    TYPE_w_str16_t ,
    TYPE_w_str32_t ,
    TYPE_w_str64_t ,
    TYPE_w_str128_t ,
    TYPE_w_str256_t ,
    
}PARA_TYPE;


typedef struct
{
    char *name;
    w_uint8_t type;
    w_uint8_t count;
    w_int16_t itemsize;
    void *ptr;
}dic_item_s;

typedef struct
{
    char *name;
    w_int32_t count;
    dic_item_s *item;
}para_dic_s;

#define DICT_ITEM_START(tb_name) dic_item_s tb_name[] = {
#define DICT_ITEM(objtype,obj,mbrtype,mbr) {#mbr,TYPE_##mbrtype,(w_uint8_t)(sizeof(obj.mbr)/sizeof(mbrtype)),sizeof(mbrtype),/*MBR_OS(objtype,mbr),*/&obj.mbr}
#define DICT_ITEM_END };
#define DICT_DEFINE(dic_name,tb_name) para_dic_s dic_name = {#dic_name,sizeof(tb_name)/sizeof(dic_item_s),tb_name};
#define DICT_DECLARE(dic_name) extern para_dic_s dic_name

w_bool_t param_set(para_dic_s *dic,char *name,void *value);
w_bool_t param_get(para_dic_s *dic,char *name,void *value);
void param_print(para_dic_s *dic);


