#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED
#include "./Status.h"

typedef int ElemType;

typedef struct DNode{
    ElemType         data;
	struct DNode *prior;
	struct DNode *next;
}DNode, *DLinkedList;

Status InitList(DLinkedList *L);

Status ClearList(DLinkedList L);

void DestroyList(DLinkedList *L);

Status ListEmpty(DLinkedList L);

int ListLength(DLinkedList L);

Status GetElem(DLinkedList L, int i, ElemType *e);

int LocateElem(DLinkedList L, ElemType, Status(Compara)(ElemType, ElemType));

Status PriorElem(DLinkedList L, ElemType cur_e, ElemType *e);

Status NextElem(DLinkedList L, ElemType cur_e, ElemType *e);

DLinkedList GetElemPtr(DLinkedList L, int i);

Status ListInsert(DLinkedList L, int i, ElemType e);

Status ListDelete(DLinkedList L, int i, ElemType *e);

Status ListTraverse(DLinkedList L, void(Visit)(ElemType));


#endif // DOUBLELINKEDLIST_H_INCLUDED
