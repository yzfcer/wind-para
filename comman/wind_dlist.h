/****************************************Copyright (c)**************************************************
**                                       ��  ��  ��  ��
**
**                                       yzfcer@163.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: wind_list.h
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
#ifndef __WIND_DLIST_H__
#define __WIND_DLIST_H__
#include "wind_type.h"
typedef struct __dnode_s dnode_s, *pdnode_s;
typedef struct __pri_dnode_s prinode_s, *pprinode_s;
typedef struct __dlist_s dlist_s, *pdlist_s;

//����ڵ�ṹ
struct __dnode_s 
{
    pdnode_s prev;
    pdnode_s next;
};

//�����ȼ�����ڵ�ṹ
struct __pri_dnode_s 
{
    dnode_s node;
    w_uint32_t prio;
};


//����ͷ���ṹ
struct __dlist_s 
{
    pdnode_s head;
    pdnode_s tail;
};



#define DNODE_INIT(dnode) {dnode.prev = NULL;dnode.next = NULL;}
#define PRIO_DNODE_INIT(prionode) {prionode.node.prev = NULL;prionode.node.next = NULL;prionode.prio = 0;}
#define DLIST_INIT(dlist) {dlist.head = NULL;dlist.tail = NULL;}
#define FIND(type,e) ((w_uint32_t)&(((type*)0)->e))
#define DLIST_OBJ(ptr,type,mbrnode) (void*)(((char*)(ptr))-((w_uint32_t)&(((type*)0)->mbrnode)))
#define PRI_DLIST_OBJ(ptr,type,mbrnode) (void*)(((char*)(ptr))-((w_uint32_t)&(((type*)0)->mbrnode.node)))

#define foreach_node(node,list) for(node = dlist_head(list);node != NULL;node = dnode_next(node))

//��ȡ����ͷ���ڵ�
static __INLINE__ 
pdnode_s dlist_head(pdlist_s dlist)
{
    return dlist->head;
}

// ��ȡ����β���ڵ�
static __INLINE__ 
pdnode_s dlist_tail(pdlist_s dlist)
{
    return dlist->tail;
}

// ��ȡ�����ڵ����һ���ڵ�
static __INLINE__ 
pdnode_s dnode_next(pdnode_s node) 
{
    return node->next;
}

// ��ȡ�����ڵ����һ���ڵ�
static __INLINE__ 
pdnode_s dnode_prev(pdnode_s node) 
{
    return node->prev;
}


// ������ͷ������һ���ڵ�
void dlist_insert_head(pdlist_s dlist,pdnode_s node);

//���� ��β������һ���ڵ�
void dlist_insert_tail(pdlist_s dlist,pdnode_s node);

// ��ָ���ڵ�����һ���ڵ�
void dlist_insert(pdlist_s dlist,pdnode_s lpAfter,pdnode_s node);

// ������ͷ������һ���ڵ�
pdnode_s dlist_remove_head(pdlist_s dlist);

// ������β������һ���ڵ�
pdnode_s dlist_remove_tail(pdlist_s dlist);

// ��������ɾ�������ڵ�
pdnode_s dlist_remove(pdlist_s dlist,pdnode_s node);

// ��� �����Ƿ�Ϊ��
w_bool_t dlist_is_empty(pdlist_s dlist);

// ��ȡ�����еĽڵ���
w_int32_t dlist_get_count(pdlist_s dlist);
// �ϲ���������
pdlist_s dlist_combine(pdlist_s dlist1,pdlist_s dlist2);

// ���������һ�������ȼ��ڵ�
void dlist_insert_prio(pdlist_s dlist,pprinode_s prinode,w_uint32_t prio);

// ��������ɾ�����������ȼ��ڵ�
pprinode_s dlist_remove_prio(pdlist_s dlist,pprinode_s prinode);

#endif//__dlist_s_H__
