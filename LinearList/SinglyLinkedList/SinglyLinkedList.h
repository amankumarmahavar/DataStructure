#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "./Status.h"

typedef int ElemType;

typedef struct LNode{
	ElemType        data;
	struct LNode  *next;
}LNode;

typedef struct LNode *LinkList;

Status InitList(LinkList* L);

Status ClearList(LinkList L);

Status DestoryList(LinkList* L);

Status ListEmpty(LinkList L);

int ListLength(LinkList L);

Status GetElem(LinkList L, int i, ElemType *e);

Status NextElem(LinkList L, ElemType cur_e, ElemType *e);

Status PriorElem(LinkList L, ElemType cur_e, ElemType *e);

int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status ListInsert(LinkList L, int i, ElemType e);

Status ListDelete(LinkList L, int i, ElemType *e);

Status ListTarverse(LinkList L, void(Visit)(ElemType));

Status CreateList_h(LinkList* L, int n);

Status CreateList_t(LinkList* L, int n);

Status GetMiddleNode(LinkList L, ElemType *e);


#endif // SINGLYLINKEDLIST_H_INCLUDED
