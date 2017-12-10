/****************************************Copyright (c)**************************************************
**                                       ��  ��  ��  ��
**
**                                       yzfcer@163.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: wind_list.c
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
#ifndef __DLIST_H__
#define __DLIST_H__
#include "wind_dlist.h"

// ������ͷ������һ���ڵ�
void dlist_insert_head(pdlist_s dlist,pdnode_s node)
{
    node->prev = NULL;
    node->next = dlist->head;
    if(dlist->head)
        dlist->head->prev = node;
    else
        dlist->tail = node;
    dlist->head = node;
}

//���� ��β������һ���ڵ�
void dlist_insert_tail(pdlist_s dlist,pdnode_s node)
{
    node->next = NULL;
    node->prev = dlist->tail;
    if(dlist->tail)
        dlist->tail->next = node;
    else
        dlist->head = node;
    dlist->tail = node;
}

// ��ָ���ڵ�����һ���ڵ�
void dlist_insert(pdlist_s dlist,pdnode_s prenode,pdnode_s node) 
{
    if(prenode) {
        if(prenode->next)
            prenode->next->prev = node;
        else
            dlist->tail = node;
        node->prev = prenode;
        node->next = prenode->next;
        prenode->next = node;
    } else {
        dlist_insert_head(dlist, node);
    }
}

// ������ͷ������һ���ڵ�
pdnode_s dlist_remove_head(pdlist_s dlist) 
{
    if(dlist->head) {
        pdnode_s node = dlist->head;
        if(dlist->head->next)
            dlist->head->next->prev = NULL;
        else
            dlist->tail = NULL;
        dlist->head = dlist->head->next;
        node->prev = node->next = NULL;
        return node;
    } else {
        return NULL;
    }
}

// ������β������һ���ڵ�
pdnode_s dlist_remove_tail(pdlist_s dlist) 
{
    if(dlist->tail) {
        pdnode_s node = dlist->tail;
        if(dlist->tail->prev)
            dlist->tail->prev->next = NULL;
        else
            dlist->head = NULL;
        dlist->tail = dlist->tail->prev;
        node->prev = node->next = NULL;
        return node;
    } else {
        return NULL;
    }
}

// ��������ɾ�������ڵ�
pdnode_s dlist_remove(pdlist_s dlist,pdnode_s node) 
{
    if(node->prev)
        node->prev->next = node->next;
    else
        dlist->head = node->next;
    if(node->next)
        node->next->prev = node->prev;
    else
        dlist->tail = node->prev;
    return node;
}

// ��� �����Ƿ�Ϊ��
w_bool_t dlist_is_empty(pdlist_s dlist) 
{
    if(dlist->head || dlist->tail)
        return B_FALSE;
    else
        return B_TRUE;
}

// ��ȡ�����еĽڵ���
w_int32_t dlist_get_count(pdlist_s dlist) 
{
    w_int32_t count = 0;
    pdnode_s node = dlist_head(dlist);
    while(node) {
        ++ count;
        node = dnode_next(node);
    }
    return count;
}

//�ϲ���������
pdlist_s dlist_combine(pdlist_s dlist1,pdlist_s dlist2) 
{
    if(!dlist_is_empty(dlist2)) {
        if(!dlist_is_empty(dlist1)) {
            dlist1->tail->next = dlist2->head;
            dlist2->head->prev = dlist1->tail;
            dlist1->tail = dlist2->tail;
    } else {
        dlist1->head = dlist2->head;
        dlist1->tail = dlist2->tail;
    }
        dlist2->head = NULL;
        dlist2->tail = NULL;
    }
    return dlist1;
}

// ���������һ�������ȼ��ڵ�
void dlist_insert_prio(pdlist_s dlist, pprinode_s prinode,w_uint32_t prio)
{
    pprinode_s prin = NULL;
    pdnode_s dnode;
    prinode->prio = prio;
    dnode = dlist_head(dlist);
    if(dnode == NULL)
    {
        dlist_insert_tail(dlist,&prinode->node);
        return;
    }
    while(dnode)
    {
        prin = DLIST_OBJ(dnode,prinode_s,node);
        if(prin->prio <= prinode->prio)
            dnode = dnode_next(dnode);
        else
            break;
    }
    if(dnode == NULL)
        dlist_insert_tail(dlist,&prinode->node);
    else 
    {
        if(prin->node.prev)
            dlist_insert(dlist,prin->node.prev,&prinode->node);
        else
            dlist_insert_head(dlist,&prinode->node);
    }
}

// ��������ɾ�����������ȼ��ڵ�
pprinode_s dlist_remove_prio(pdlist_s dlist,pprinode_s prinode)
{
    pdnode_s pdnode;
    pdnode = dlist_remove(dlist,&prinode->node);
    return DLIST_OBJ(pdnode,prinode_s,node);
}

#endif//__dlist_s_H__
